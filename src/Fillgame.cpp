//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#include "Fillgame.h"

#include <iostream>

#include "game_basics.h"
#include "Fillgame.h"
#include "Move.h"

using namespace std;


Fillgame::Fillgame(int b_r, int b_c) {
    board_row = b_r;
    board_column = b_c;
    board = new int*[board_row];

    for (int i = 0; i < board_row; i++) {
        board[i] = new int[board_column];
    }

    to_play = BLACK;

    for (int i = 0; i < board_row; i++) {
        for (int j = 0; j < board_column; j++)
        {
            board[i][j] = 0;
        }
    }
}

Fillgame::~Fillgame() {
    delete board;
}

void Fillgame::print_board() {
    for (int i = 0; i < board_row; i++) {
        for (int j = 0; j < board_column; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Fillgame::addMoveToBoard(int r, int c, int n) {
    board[r][c] = n;
    Move new_move(r, c, n);
    moves.push_back(new_move);
}

bool Fillgame::is_valid_board_cell(int row, int column) {
    if (row >= 0 && row < board_row && column >= 0 && column < board_column)
        return true;

    return false;
}

void Fillgame::push_adjacent_moves(Move move) {
    int row_directions[4] = {0, 1, 0, -1};   //directions of row to move left, right, top, bottom
    int column_directions[4] = {-1, 0, 1, 0};   //directions of column to move left, right, top, bottom

    for (int i = 0; i < 4; i++) {
        int adj_x = move.get_row() + row_directions[i];
        int adj_y = move.get_column() + column_directions[i];
        int adj_cell_value = 0;

        if (is_valid_board_cell(adj_x, adj_y)) {
            adj_cell_value = board[adj_x][adj_y];
        }

        move.add_adjacent_cell_move(Move(adj_x, adj_y, adj_cell_value));
    }
}

bool Fillgame::violate_block_rule(Move move, int value, int limit, int **visited, int total_visited) {
    visited[move.get_row()][move.get_column()] = 1;
    total_visited++;

    if (total_visited - 1 == value) {   // 1 has been subtracted here because of considering the root node's value
        return true;
    }

    if (limit <= 0)
        return false;

    push_adjacent_moves(move);
    list<Move> *adjacent_moves = move.get_adjacent_cell_moves();

    for (Move m : *adjacent_moves) {
        if (is_valid_board_cell(m.get_row(), m.get_column()) && m.get_value() == value && !visited[m.get_row()][m.get_column()]) {
            if (violate_block_rule(m, value, limit - 1, visited, total_visited)) {
                return true;
            }
        }
    }

    return false;
}

bool Fillgame::is_legal_move(Move move) {
    Move root_move = move;
    int *visited[board_column];
    for (int i = 0; i < board_row; i++) {
        visited[i] = new int [board_column];
    }
    for (int i = 0; i < board_row; i++) {
        for (int j = 0; j < board_column; j++) {
            visited[i][j] = false;
        }
    }

    bool is_legal_move = !violate_block_rule(move, move.get_value(), move.get_value(), visited, 0);

    return is_legal_move;
}

vector<Move> Fillgame::get_all_legal_moves() {

}
