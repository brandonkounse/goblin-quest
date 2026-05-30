#include "monster.h"

Monster::Monster(const std::string &name, const int health, const int attack) {
    stats.name = name;
    stats.health = health;
    stats.attack = attack;
}

Monster::~Monster() = default;

int Monster::attack() const {
    return stats.attack;
}

void Monster::takeDamage(const int attack) {
    stats.health -= attack;
}