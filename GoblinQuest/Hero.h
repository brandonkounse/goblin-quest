#pragma once
#include <string>
#include "stats.h"
#include "difficulty.h"

class Hero {
public:
    Stats stats;

    explicit Hero(Difficulty setting);
    ~Hero();
    int getPotions() const;
    int usePotion();
    void setName();
    int attack() const;
    void takeDamage(int attack);
private:
    int potions;
    int maxHP;
    static constexpr int potionRestore = 30;
};