#include <iostream>
#include <sstream>
#include <cstring>
#include "src/Fillgame.h"

using namespace std;


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
                fill_game->addMoveToBoard(i, j, 0);
            } else {
                fill_game->addMoveToBoard(i, j, (int)(row[j] - '0'));
            }
        }
        i++;
    }
}

int main(int argc, char **argv) {
    string fill_game_position = argv[1];
    string time_limit = argv[2];

    int board_row = count(fill_game_position.begin(), fill_game_position.end(), '*') + 1;
    int board_column = countColumns(fill_game_position);

    Fillgame fill_game(board_row, board_column);

    initiate_board_from_input(fill_game_position, &fill_game);

    fill_game.print_board();
    return 0;
}
