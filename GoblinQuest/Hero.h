#pragma once
#include <string>
#include "stats.h"
#include "difficulty.h"

class Hero {
public:
    Stats stats;
    Hero(Difficulty setting);
    ~Hero();
    void setName();
    int attack() const;
    void takeDamage(int attack);
};