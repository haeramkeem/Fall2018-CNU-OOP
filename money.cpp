#include "money.h"

Money::Money(int _cost){
    setCost(_cost);
    setNext(nullptr);
}

Money::Money(int _cost, Money* _next){
    setCost(_cost);
    setNext(_next);
}

int Money::getCost(){
    return cost;
}

void Money::setCost(int c){
    this->cost = c;
}

Money* Money::getNext(){
    return next;
}

void Money::setNext(Money *m){
    this->next = m;
}

int Money::compareTo(int m){
    if(this->getCost() < m) return -1; // m is more expensive than this
    else if(this->getCost() == m) return 0;    // same cost
    else return 1;  // m is cheaper than this
}