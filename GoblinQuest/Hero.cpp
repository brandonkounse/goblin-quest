#include <iostream>
#include "hero.h"
#include "terminal.h"

Hero::Hero(Difficulty setting) {
    if (setting == EASY) {
        this->maxHP = 150;
        stats.health = maxHP;
        stats.attack = 20;
        this->potions = 3;
    }
    else if (setting == NORMAL) {
        this->maxHP = 100;
        stats.health = maxHP;
        stats.attack = 15;
        this->potions = 2;
    }
    else {
        this->maxHP = 70;
        stats.health = maxHP;
        stats.attack = 10;
        this->potions = 1;
    }
}

Hero::~Hero() {}

void Hero::setName() {
    std::cout << green("Enter your Hero's name: ");
    std::cin >> stats.name;
}

int Hero::attack() const {
    return stats.attack;
}

void Hero::takeDamage(int attack) {
    stats.health -= attack;
}

int Hero::getPotions() const {
    return this->potions;
}

int Hero::usePotion() {
    if (this->potions <= 0) {
        std::cout << red("No potions remaining!") << std::endl;
        return 0;
    }
    if (this->potions > 0) {
        if (this->stats.health == maxHP) {
            std::cout << "Can't heal. Already have full HP" << std::endl;
            return 0;
        }
        else if (this->stats.health < maxHP && this->stats.health > 0) {
            int amountHealed;
            if (this->stats.health + potionRestore > maxHP) {
                amountHealed = maxHP - this->stats.health;
                this->stats.health = maxHP;
                this->potions -= 1;
                return amountHealed;
            }
            else {
                this->stats.health += potionRestore;
                this->potions -= 1;
                return potionRestore;
            }
        }
    }
}