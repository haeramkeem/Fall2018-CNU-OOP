#include "board.h"
#include "appcontroller.h"
#include "appview.h"

void AppController::run() {
    AppView appview;
    playernum = appview.init_page();
    playerset = new Player[playernum];

    while(round < 3) {
        this->reset();
        while (finish_checker != playernum) this->round_process(appview);
        this->allocate_money();
        round++;
    }

    appview.end_page(playerset, playernum);
}

void AppController::reset() {
        for (int board_reset = 0; board_reset < 6; board_reset++){
            boardset[board_reset].init_board(board_reset, playernum);
            boardset[board_reset].resetPlayer(playernum);
        }

        for(int diceReset = 0; diceReset < playernum; diceReset++) playerset[diceReset].setDiceLeft(8); 

        player_counter = 0;
        finish_checker = 0;
}

void AppController::round_process(AppView &_appview) {
    player_counter = player_counter % playernum;

    if (playerset[player_counter].getDiceLeft() == 0)
    {
        player_counter++;
        finish_checker++;
    } 
    else
    {
        finish_checker = 0;
        playerset[player_counter].setRandomDice(player_counter);

        casinopick = _appview.main_page(round+1, player_counter, playernum, playerset, boardset);

        boardset[casinopick].getPlayer()[player_counter] += playerset[player_counter].getRandomDice()[casinopick]; //save player's betting in collected Casino.
        int diceLeft = playerset[player_counter].getDiceLeft();
        int usedDiceNum = playerset[player_counter].getRandomDice()[casinopick];
        playerset[player_counter].setDiceLeft(diceLeft - usedDiceNum);
        player_counter++;
    }
}

void AppController::allocate_money() {
    for (int casino = 0; casino < 6; casino++)
    {
        for (int i = 0; i < playernum; i++)
        {
            int firstValue = boardset[casino].getPlayer()[i];
            for (int j = i + 1; j < playernum; j++)
            {
                int SecondValue = boardset[casino].getPlayer()[j];
                if (SecondValue == firstValue)
                {
                    boardset[casino].getPlayer()[j] = 0; //set second overlap ArrayNumber on 0
                    boardset[casino].getPlayer()[i] = 0; //set first overlap ArrayNumber on 0
                }
            }
        }

        Money *p = boardset[casino].getHead();
        while (p != nullptr)
        {
            int MaxIndex = 0;
            for (int i = 1; i < playernum; i++)
            {
                if (boardset[casino].getPlayer()[i] > boardset[casino].getPlayer()[MaxIndex])
                {
                    MaxIndex = i;
                }
            }
            if (boardset[casino].getPlayer()[MaxIndex] == 0)
                break;
            playerset[MaxIndex].setEarnMoney(playerset[MaxIndex].getEarnMoney() + p->getCost());
            p = p->getNext();
            boardset[casino].getPlayer()[MaxIndex] = 0;
        }
    }
}