//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#include "Fillgame.h"

#include <iostream>

#include "game_basics.h"
#include "Fillgame.h"
#include "Move.h"


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
