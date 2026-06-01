#include <iostream>
#include "hero.h"
#include "terminal.h"

Hero::Hero(const Difficulty setting) {
    if (setting == EASY) {
        stats.maxHP = 150;
        stats.health = stats.maxHP;
        stats.attack = 20;
        this->potions = 3;
    }
    else if (setting == NORMAL) {
        stats.maxHP = 100;
        stats.health = stats.maxHP;
        stats.attack = 15;
        this->potions = 2;
    }
    else {
        stats.maxHP = 70;
        stats.health = stats.maxHP;
        stats.attack = 10;
        this->potions = 1;
    }
}

Hero::~Hero() = default;

void Hero::setName() {
    std::cout << green("Enter your Hero's name: ");
    std::cin >> stats.name;
}

int Hero::attack() const {
    return stats.attack;
}

void Hero::takeDamage(const int attack) {
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
        if (this->stats.health == this->stats.maxHP) {
            std::cout << "Can't heal. Already have full HP" << std::endl;
            return 0;
        }
        else if (this->stats.health < this->stats.maxHP && this->stats.health > 0) {
            if (this->stats.health + potionRestore > this->stats.maxHP) {
                const int amountHealed = this->stats.maxHP - this->stats.health;
                this->stats.health = this->stats.maxHP;
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
    return 0;
}

void Hero::gainPotion() {
    if (this->getPotions() < 3) {
        this->potions++;
    }
}
