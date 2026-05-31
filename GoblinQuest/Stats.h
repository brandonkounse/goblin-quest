#pragma once
#include <string>

struct Stats {
    std::string name;
    int health = 0;
    int maxHP = 0;
    int attack = 0;

    bool isAlive() const { return health > 0; }
    void takeDamage(const int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }
};