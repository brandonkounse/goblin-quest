#pragma once
#include <string>

struct Stats {
    std::string name;
    int health;
    int attack;

    bool isAlive() const { return health > 0; }
    void takeDamage(int damage) { health -= damage; }
};