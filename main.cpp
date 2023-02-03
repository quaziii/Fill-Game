#include <iostream>
#include <sstream>
#include "src/Fillgame.h"
#include "src/Node.h"
#include "src/game_basics.h"

using namespace std;

int PROVEN = 100;
int DISPROVEN = 0;


int countColumns(string fill_game_position) {
    int i = 0;
    int count = 0;

    while (fill_game_position[i] != '*') {
        count++;
        i++;
    }

    return count;
}

void initiate_board_from_input(string fill_game_position, Fillgame *fill_game) {
    stringstream ss(fill_game_position);
    string row;
    int i = 0;

    while (getline(ss, row, '*')) {
        int n = row.length();
        for (int j = 0; j < n; j++) {
            if (row[j] == '.') {
                fill_game->add_move_to_board(i, j, 0);
            } else {
                fill_game->add_move_to_board(i, j, (int)(row[j] - '0'));
            }
        }
        i++;
    }
}

void add_children_to_node(Node *N, Fillgame *fill_game) {
    Fillgame new_fill_game(fill_game->get_board_row(), fill_game->get_board_column());

    for (int i = 0; i < new_fill_game.get_board_row(); i++) {   // copy from parent
        for (int j = 0; j < new_fill_game.get_board_column(); j++) {
            new_fill_game.add_move_to_board(i, j, fill_game->get_board()[i][j]);
        }
    }
    new_fill_game.add_move_to_board(1, 2, 3);   // add a new move to child
    Node child(N, &new_fill_game);
    N->add_child(&child);

    Fillgame new_fill_game2(fill_game->get_board_row(), fill_game->get_board_column());

    for (int i = 0; i < new_fill_game2.get_board_row(); i++) {   // copy from parent
        for (int j = 0; j < new_fill_game2.get_board_column(); j++) {
            new_fill_game2.add_move_to_board(i, j, fill_game->get_board()[i][j]);
        }
    }
    new_fill_game2.add_move_to_board(2, 2, 3);   // add a new move to child
    Node child2(N, &new_fill_game2);
    N->add_child(&child2);

    vector<Node*> v = N->get_children();
    for (Node *cur : v) {
        cur->print_board_status();
        cout << endl;
    }
}

void MID (Node N) {

}

int Df_pn (Node R) {
    R.set_phi(INFINITY);
    R.set_delta(INFINITY);

    MID(R);

    if (R.get_delta() == INFINITY) {
        return PROVEN;
    } else {
        return DISPROVEN;
    }
}

int main(int argc, char **argv) {
    string fill_game_position = argv[1];
    string time_limit = argv[2];

    //this code block will be removed later
    string my_move_row = argv[3];
    string my_move_column = argv[4];
    string my_move_value = argv[5];

    int board_row = count(fill_game_position.begin(), fill_game_position.end(), '*') + 1;
    int board_column = countColumns(fill_game_position);

    Fillgame fill_game(board_row, board_column);    //creates an empty board

    initiate_board_from_input(fill_game_position, &fill_game);  // initalizes board from input

    fill_game.print_board();    // prints the board with initialized value

    Move m((int)my_move_row[0] - '0', (int)my_move_column[0] - '0', (int)my_move_value[0] - '0');  // change row, column and value to test, will remove later
    if (fill_game.is_legal_move(m))     // outputs to test if the above move is legal
        cout << "LEGAL MOVE FOR " << m.get_value() << " AT (" << m.get_row() << "," << m.get_column() << ")" << endl;
    else
        cout << "ILLEGAL MOVE FOR " << m.get_value() << " AT (" << m.get_row() << "," << m.get_column() << ")" << endl;

    Node root(nullptr, &fill_game);
    root.add_children_to_node(&fill_game);

    return 0;
}
