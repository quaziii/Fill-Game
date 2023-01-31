//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#include "Fillgame.h"

#include <iostream>

#include "game_basics.h"
#include "Fillgame.h"
#include "Move.h"


Fillgame::Fillgame(int b_size) {
    board_size = b_size;
    board = new int*[board_size];

    for (int i = 0; i < board_size; i++) {
        board[i] = new int[board_size];
    }

    to_play = BLACK;
    moves = new Move[board_size*board_size];

    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = 0;
        }
    }
}

Fillgame::~Fillgame() {
    delete board;
}

void Fillgame::print_board() {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
