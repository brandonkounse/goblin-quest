#include <iostream>
#include "hero.h"
#include "terminal.h"

Hero::Hero(Difficulty setting) {
    if (setting == EASY) {
        stats.health = 150;
        stats.attack = 20;
    }
    else if (setting == NORMAL) {
        stats.health = 100;
        stats.attack = 15;
    }
    else {
        stats.health = 45;
        stats.attack = 10;
    }
}

Hero::~Hero() {}

void Hero::setName() {
    std::cout << narrate("Enter your Hero's name...") << std::endl;
    std::cin >> stats.name;
    std::cout << narrate("Greetings " + stats.name) << std::endl;
}

int Hero::attack() const {
    return stats.attack;
}

void Hero::takeDamage(int attack) {
    stats.health -= attack;
}