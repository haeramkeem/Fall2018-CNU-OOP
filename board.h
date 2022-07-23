#ifndef BOARD_H
#define BOARD_H

#include "money.h"

class Board {
    private:
        Money *head;
        int* player;
    public:
        Board();
        Money* getHead();
        void setHead(Money *_head);
        void init_board(int seed_set, int playerNum);
        int* getPlayer();
        void setPlayer(int* _player);
        void resetPlayer(int playerNum);
};

#endif