#include <iostream>
#include <cstdlib>
#include <time.h>

#include "player.h"

Player::Player(){
    setDiceLeft(8);
    setEarnMoney(0);
}

int Player::getDiceLeft(){
    return diceLeft;
}

void Player::setDiceLeft(int i){
    this->diceLeft = i;
}

int Player::getEarnMoney(){
    return earnMoney;
}

void Player::setEarnMoney(int i){
    this->earnMoney = i;
}

int *Player::getRandomDice(){
    return dice;
}

void Player::setRandomDice(int seed_set) {
    srand((unsigned int)time(0));
    for(int a = 0; a<seed_set; a++) rand();
    srand(rand());

    for(int b = 0; b < 6; b++){
        dice[b] = 0;
    }

    for(int c = 0; c < getDiceLeft(); c++){
        int k = rand() % 6;
        dice[k]++;
    }
}