#include "monster.h"

Monster::Monster(std::string name, int health, int attack) {
    stats.name = name;
    stats.health = health;
    stats.attack = attack;
}

Monster::~Monster() {}