//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#ifndef FILLGAME_FILLGAME_H
#define FILLGAME_FILLGAME_H

#include "Move.h"


class Fillgame {
private:
    int board_size;
    int **board;
    int to_play;
    Move *moves;
public:
    Fillgame(int board_size);
    ~Fillgame();

    void print_board();
};


#endif //FILLGAME_FILLGAME_H
