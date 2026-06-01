#include <iostream>

#include "hero.h"
#include "Level3.h"
#include "terminal.h"
#include "troop.h"

void displayBanner() {
    std::cout << R"(
  ________      ___.   .__  .__         ________                          __
 /  _____/  ____\_ |__ |  | |__| ____   \_____  \  __ __   ____   _______/  |_
/   \  ___ /  _ \| __ \|  | |  |/    \   /  / \  \|  |  \_/ __ \ /  ___/\   __\
\    \_\  (  <_> ) \_\ \  |_|  |   |  \ /   \_/.  \  |  /\  ___/ \___ \  |  |
 \______  /\____/|___  /____/__|___|  / \_____\ \_/____/  \___  >____  > |__|
        \/           \/             \/         \__>           \/     \/
)" << std::endl;
}

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void displayLevel(Level& level) {
    std::cout << "--- Level " << level.getLevelNum() << " ---" << std::endl;
    std::cout << "Enemies:" << std::endl;

    const Troop& troops = level.getTroops();
    for (int i = 0; i < troops.size(); i++) {
        std::string name = troops[i].stats.name;
        std::cout << i + 1 << " - ";
        std::cout << red(name);
        for (size_t j = name.size(); j < 20; j++) std::cout << " ";
        std::cout << "[" << troops[i].stats.health << "]";
        std::cout << std::endl;
    }
}

std::string getColoredHealthStr(const Hero& hero) {
    const std::string hpStr = std::to_string(hero.stats.health);

    if (hero.stats.health < hero.stats.maxHP && hero.stats.health > 0) {
        return orange(hpStr);
    }
    return green(hpStr);
}

std::string getColoredPotionsStr(const Hero& hero) {
    const std::string potionStr = std::to_string(hero.getPotions());

    if (hero.getPotions() < 3 && hero.getPotions() > 0) {
        return orange(potionStr);
    } else if (hero.getPotions() == 0) {
        return red(potionStr);
    } else {
        return green(potionStr);
    }
}

void displayHud(const Hero& hero) {
    std::cout << green("NAME: " + hero.stats.name)
       << green(" | HP: ")
       << getColoredHealthStr(hero) << green("/" + std::to_string(hero.stats.maxHP))
       << green(" | POTIONS: ")
       << getColoredPotionsStr(hero) << green("/3")
       << std::endl;
}