#include <iostream>
#include <cstdlib>
#include <ctime>

#include "board.h"

using namespace std;

Board::Board() {}

Money* Board::getHead() {
    return head;
}

void Board::setHead(Money *_head) {
    head = _head;
}

void Board::init_board(int seed_set,int playerNum) {
    setPlayer(new int[playerNum]);
    this->resetPlayer(playerNum);

    srand((unsigned int)time(0));
    for(int i = 0; i<seed_set; i++) rand();
    srand(rand());
    setHead(new Money((rand()%9+1)*10000));

    int total = this->getHead()->getCost();
    
    while(total <= 50000) {
        int temp = (rand()%9+1)*10000;
        total += temp;((unsigned int)time(0));

        if(this->getHead()->compareTo(temp) == -1) {
            Money *temp_head = this->getHead();
            this->setHead(new Money(temp, temp_head));
        } else {
            Money *walker = head;
            while(walker->getNext() != nullptr) {
                if(walker->getNext()->compareTo(temp) != 1) break;
                else walker = walker->getNext();
            }
            if(walker->getNext() == nullptr) {
                if(walker->compareTo(temp) != -1)
                walker->setNext(new Money(temp));
            } else {
                Money *temp_money = new Money(temp, walker->getNext());
                walker->setNext(temp_money);
            }
        }
    }
 
}

int* Board::getPlayer(){
    return player;
}

void Board::setPlayer(int* _player){
    this->player = _player;
}

void Board::resetPlayer(int playerNum) {
    for(int a = 0; a<playerNum; a++) getPlayer()[a] = 0;
}