#ifndef APPVIEW_H
#define APPVIEW_H

#include <string>

#include "board.h"

class AppView {
    private:
    public:
        int init_page();
        int main_page(int _round, int _player, int _playernum, Player *_playerset, Board *_boardset);
        void end_page(Player *_playerset, int _playernum);
};

#endif