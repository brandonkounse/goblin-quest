#pragma once
#include <string>

struct Stats {
    std::string name;
    int health = 0;
    int attack = 0;

    bool isAlive() const { return health > 0; }
    void takeDamage(int damage) { health -= damage; }
};