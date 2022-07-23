#ifndef PLAYER_H
#define PLAYER_H

class Player{
    public:
        Player();
        int getDiceLeft();
        void setDiceLeft(int i);
        int getEarnMoney();
        void setEarnMoney(int i);
        int *getRandomDice();
        void setRandomDice(int seed_set);
    private:
        int diceLeft;
        int earnMoney;
        int dice[6] = {0};
};
#endif
