//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#ifndef FILLGAME_MOVE_H
#define FILLGAME_MOVE_H

#include <list>

using namespace std;


//class Cell {
//public:
//    int row;
//    int column;
//
//    Cell(int r, int c);
//    ~Cell();
//};

class Move {
private:
    int row;
    int column;
    int value;

    list<Move> *adjacent_cell_moves;
public:
    Move();
    Move(int r, int c, int n);
    ~Move();

    int get_row();
    int get_column();
    int get_value();

    void add_adjacent_cell_move(Move move);
    list<Move>* get_adjacent_cell_moves();
};


#endif //FILLGAME_MOVE_H
