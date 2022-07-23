#ifndef MONEY_H
#define MONEY_H

#include "player.h"

class Money{
    public:
        Money(int _cost);
        Money(int _cost, Money *_next);
        int getCost();
        void setCost(int c);
        Money* getNext();
        void setNext(Money *m);
        int compareTo(int m);
    private:
        int cost;
        Money *next;
        
};

#endif