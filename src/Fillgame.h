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
    bool is_valid_board_cell(int row, int column);
    void push_adjacent_moves(Move move);
    bool is_legal_move(Move move);
    std::vector<Move> get_all_legal_moves();
    bool violate_block_rule(Move move, int value, int limit, int **visited);
};


#endif //FILLGAME_FILLGAME_H
