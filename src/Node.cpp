//
// Created by Kazi Asif Sadmine on 2023-02-02.
//

#include <iostream>
#include "Node.h"

using namespace std;


Node::Node(Node *parent, Fillgame *game) {
    this->parent = parent;
    this->fillgame_state = game;
}

Node::~Node() {}

void Node::set_phi(int p) {
    this->phi = p;
}

int Node::get_phi() {
    return this->phi;
}

void Node::set_delta(int d) {
    this->delta = d;
}

int Node::get_delta() {
    return this->delta;
}

void Node::add_child(Node *child) {
    this->children.push_back(child);
}

vector<Node*> Node::get_children() {
    return this->children;
}

void Node::print_board_status() {
    int **board = this->fillgame_state->get_board();

    for (int i = 0; i < this->fillgame_state->get_board_row(); i++) {
        for (int j = 0; j < this->fillgame_state->get_board_column(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Node::add_children_to_node(Fillgame *fill_game) {
    Fillgame new_fill_game(fill_game->get_board_row(), fill_game->get_board_column());

    for (int i = 0; i < new_fill_game.get_board_row(); i++) {   // copy from parent
        for (int j = 0; j < new_fill_game.get_board_column(); j++) {
            new_fill_game.add_move_to_board(i, j, fill_game->get_board()[i][j]);
        }
    }
    new_fill_game.add_move_to_board(1, 2, 3);   // add a new move to child
    Node child(this, &new_fill_game);
    this->add_child(&child);

    Fillgame new_fill_game2(fill_game->get_board_row(), fill_game->get_board_column());

    for (int i = 0; i < new_fill_game2.get_board_row(); i++) {   // copy from parent
        for (int j = 0; j < new_fill_game2.get_board_column(); j++) {
            new_fill_game2.add_move_to_board(i, j, fill_game->get_board()[i][j]);
        }
    }
    new_fill_game2.add_move_to_board(2, 2, 3);   // add a new move to child
    Node child2(this, &new_fill_game2);
    this->add_child(&child2);

    vector<Node*> v = this->get_children();
    for (Node *cur : v) {
        cur->print_board_status();
        cout << endl;
    }
}
