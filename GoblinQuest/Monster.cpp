#include "monster.h"

Monster::Monster(std::string name, int health, int attack) {
    stats.name = name;
    stats.health = health;
    stats.attack = attack;
}

Monster::~Monster() {}

int Monster::attack() const {
    return stats.attack;
}

void Monster::takeDamage(int attack) {
    stats.health -= attack;
}