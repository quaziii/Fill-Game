//
// Created by Kazi Asif Sadmine on 2023-01-31.
//

#ifndef FILLGAME_MOVE_H
#define FILLGAME_MOVE_H


class Move {
private:
    int row;
    int column;
    int number;
public:
    Move();
    Move(int r, int c, int n);
    ~Move();
};


#endif //FILLGAME_MOVE_H
