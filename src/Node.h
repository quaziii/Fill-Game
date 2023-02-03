//
// Created by Kazi Asif Sadmine on 2023-02-02.
//

#ifndef FILLGAME_NODE_H
#define FILLGAME_NODE_H

#include <vector>
#include "Fillgame.h"

using namespace std;


class Node {
    Node *parent;
    vector<Node*> children;
    Fillgame *fillgame_state;

    int phi;
    int delta;
public:
    Node(Node *parent, Fillgame *game);
    ~Node();

    void set_phi(int p);
    int get_phi();
    void set_delta(int d);
    int get_delta();
    void add_child(Node *child);
    vector<Node*> get_children();
    void print_board_status();
    void add_children_to_node(Fillgame *fill_game);
};


#endif //FILLGAME_NODE_H
