#include <iostream>

#include "appview.h"

int AppView::init_page() {
    system("clear");
    int return_val;

    std::cout << "<GANG WON LAND>" << std::endl; //1
    std::cout << std::endl;//2
    std::cout << "-Input player number : ";//3
    std::cin >> return_val;

    while(return_val < 2 || return_val > 4) {
        std::cout << "!Wrong value. please enter a correct one : " << std::endl;
        std::cin >> return_val;
    }

    return return_val;
}

int AppView::main_page(int _round, int _player, int _playernum, Player *_playerset, Board *_boardset) {
    Money *walker;
    system("clear");
    std::cout << "                                   <ROUND " << _round << ">" << std::endl;//1
    std::cout << std::endl;
    std::cout << "   CASINO <1>   CASINO <2>   CASINO <3>   CASINO <4>   CASINO <5>   CASINO <6>  " << std::endl;//2
    std::cout << " +------------+------------+------------+------------+------------+------------+" << std::endl;//3
    std::cout << " + WIN MONEY  + WIN MONEY  + WIN MONEY  + WIN MONEY  + WIN MONEY  + WIN MONEY  +" << std::endl;//4

    for(int vert1 = 0; vert1 < 5; vert1++) {
        std::cout << " | ";
        for(int hori1 = 0; hori1 < 6; hori1++) {
            walker = _boardset[hori1].getHead();
            int p1 = 0;
            while(walker != nullptr && p1++ < vert1) walker = walker->getNext();
            if(walker == nullptr) std::cout << "           | ";
            else std::cout << walker->getCost() << "      | ";
        }
        std::cout << std::endl;
    }

    std::cout << " +------------+------------+------------+------------+------------+------------+" << std::endl;//10
    std::cout << " + BET STATUS + BET STATUS + BET STATUS + BET STATUS + BET STATUS + BET STATUS +" << std::endl;//11
    
    for(int vert2 = 0; vert2 < 4; vert2++) {
        if(vert2 < _playernum) {
            std::cout << " | ";
            for(int hori2 = 0; hori2 < 6; hori2++) {
                std::cout << "PLAYER" << (vert2+1) << ": " << _boardset[hori2].getPlayer()[vert2] << " | ";
            }
        } else {
            std::cout << " |            |            |            |            |            |            |" << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::cout << " +------------+------------+------------+------------+------------+------------+" << std::endl;//16
    std::cout << std::endl;//17
    std::cout << " <PLAYER " << (_player+1) << ">" <<std::endl;//18
    std::cout << " -Roll the Dice..." << std::endl;
    std::cout << "  -Dice : <1>  <2>  <3>  <4>  <5>  <6>" << std::endl;
    std::cout << "  -Pcs  :";
    for(int hori3 = 0; hori3 < 6; hori3++) std::cout << "  " << _playerset[_player].getRandomDice()[hori3] << "  ";
    std::cout << std::endl;
    std::cout << " -What casino are you bet to? : ";
    int returnee;
    std::cin >> returnee;
    while(returnee < 1 || returnee > 6 || _playerset[_player].getRandomDice()[returnee-1] == 0) {
        std::cout << " !Wrong value. please enter a correct one : ";
        std::cin >> returnee;
    }
    return returnee-1;
}

void AppView::end_page(Player *_playerset, int _playernum) {
    system("clear");
    std::cout << "<TOTAL RESULT>" << std::endl;
    std::cout << std::endl;
    for(int a = 0; a < _playernum; a++) {
        std::cout << "-PLAYER " << (a+1) << " : " << _playerset[a].getEarnMoney() << "$" << std::endl;
    }
}