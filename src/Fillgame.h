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
};


#endif //FILLGAME_FILLGAME_H
