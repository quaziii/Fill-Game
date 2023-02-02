//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#include "Move.h"


Move::Move() {}

Move::Move(int r, int c, int v) {
    row = r;
    column = c;
    value = v;

    adjacent_cell_moves = new list<Move>[4];
}

Move::~Move() {}

int Move::get_row() {
    return this->row;
}

int Move::get_column() {
    return this->column;
}

int Move::get_value() {
    return this->value;
}

void Move::add_adjacent_cell_move(Move move) {
    adjacent_cell_moves->push_back(move);
}

list<Move>* Move::get_adjacent_cell_moves() {
    return this->adjacent_cell_moves;
}
