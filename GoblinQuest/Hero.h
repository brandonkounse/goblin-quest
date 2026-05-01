#pragma once
#include <string>
#include "stats.h"
#include "difficulty.h"

class Hero {
public:
    Stats stats;
    Hero(Difficulty setting);
    ~Hero();
    int getPotions() const;
    int usePotion();
    void setName();
    int attack() const;
    void takeDamage(int attack);
private:
    int potions;
    int maxHP;
    static const int potionRestore = 30;
};