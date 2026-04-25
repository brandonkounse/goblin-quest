#include <iostream>
#include <iomanip>
#include "terminal.h"

const char* const GREEN = "\x1b[32m";
const char* const RED = "\x1b[31m";
const char* const RESET = "\x1b[0m";

std::string narrate(std::string text) {
    return GREEN + text + RESET;
}

std::string narrateDanger(std::string text) {
    return RED + text + RESET;
}

void hud(Hero& hero) {
    std::cout << "NAME: " << hero.stats.name
        << " | HP: " << hero.stats.health
        << std::endl;
}

void displayLevel(Level& level) {
	std::cout << "--- Level " << level.getLevelNum() << " ---" << std::endl;
	std::cout << "Enemies:" << std::endl;

	Troop& troops = level.getTroops();
	for (int i = 0; i < troops.size(); i++) {
		std::cout << i + 1 << ". " 
			<< std::left << std::setw(20) << troops[i].stats.name 
			<< "[HP: " << troops[i].stats.health << "]" 
			<< std::endl;
	}
}