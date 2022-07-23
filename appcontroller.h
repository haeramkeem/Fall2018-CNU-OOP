#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "appview.h"

class AppController {
    private:
        int round = 0;
        int playernum = 0;
        int player_counter = 0;
        int finish_checker = 0;
        int casinopick = 0;
        Player *playerset;
        Board boardset[6];
    public:
        void run();
        void reset();
        void round_process(AppView &_appview);
        void allocate_money();
};

#endif