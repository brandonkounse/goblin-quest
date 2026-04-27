#pragma once
#include "stats.h"

class Monster {
public:
    Stats stats;
    Monster(std::string name, int health, int attack);
    ~Monster();
    int attack() const;
    void takeDamage(int attack);
};