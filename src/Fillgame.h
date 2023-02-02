//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#ifndef FILLGAME_FILLGAME_H
#define FILLGAME_FILLGAME_H

#include "Move.h"
#include <vector>


class Fillgame {
private:
    int board_row;
    int board_column;
    int **board;
    int to_play;
    std::vector<Move> moves;
public:
    Fillgame(int b_r, int b_c);
    ~Fillgame();

    void print_board();
    void addMoveToBoard(int r, int c, int n);
    bool is_legal_move_for_four(Move move);
    std::vector<Move> get_all_legal_moves();
    void push_adjacent_moves(Move move);
};


#endif //FILLGAME_FILLGAME_H
