#include <iostream>
#include <thread>
#include "terminal.h"
#include "hero.h"
#include "level1.h"
#include "level2.h"
#include "eventloop.h"

bool isLevel1Completed;
bool isLevel2Completed;

void play() {
	displayBanner();
	const Difficulty difficulty = selectDifficulty();
	Hero hero = createHero(difficulty);
	while (true) {
		if (!isLevel1Completed) {
			Level level = createLevel1();
			while (!level.isCleared()) {
				playLevel(level, hero);
			}
			isLevel1Completed = true;
			clearScreen();
		}
		else if (!isLevel2Completed) {
			Level level = createLevel2();
			while (!level.isCleared()) {
				playLevel(level, hero);
			}
			isLevel2Completed = true;
			clearScreen();
		// TODO implement final level 3
		}
	}
}

void playLevel(Level& level, Hero& hero) {
	clearScreen();
	displayBanner();
	displayHud(hero);
	displayLevel(level);
	printLog(COMBAT_LOG);
	const TurnResult result = chooseAction(level, hero);
	if (result == TurnResult::ConsumedTurn) {
		troopAction(level, hero);
	}
}

TurnResult chooseAction(Level& level, Hero& hero) {


	std::cout << "\nSelect target to attack, 'h' to heal, 'q' to quit: ";

	std::string action;
	std::cin >> action;

	if (action == "q") {
		exit(0);
	}

	if (action == "h") {
		const int amountHealed = hero.usePotion();
		if (amountHealed > 0) {
			addLog(blue("Potion restored ") + blue(std::to_string(amountHealed)) + blue(" hit points!"));
			return TurnResult::ConsumedTurn;
		} else {
			addLog(red("Could not use potion."));
			return TurnResult::Invalid;
		}
	}

	if (action.size() > 1 || !std::isdigit(action[0])) {
		addLog(red("Invalid input. Please enter a valid number or command."));
		return TurnResult::Invalid;
	}

	const int target = std::stoi(action);

	Troop& troops = level.getTroops();

	if (target < 1 || target > static_cast<int>(troops.size())) {
		addLog(red("Please select a valid target from the enemy list."));
		return TurnResult::Invalid;
	}

	Monster& monster = troops[static_cast<size_t>(target) - 1];
	if (!monster.stats.isAlive()) {
		addLog(red(monster.stats.name + " is already dead!"));
		return TurnResult::Invalid;
	}

	addLog(green("Attacking " + monster.stats.name + " for " + std::to_string(hero.stats.attack) + " damage!"));
	monster.stats.takeDamage(hero.attack());

	if (!monster.stats.isAlive()) {
		addLog(red(monster.stats.name + " has been defeated!"));
	}
	return TurnResult::ConsumedTurn;
}

void troopAction(Level& level, Hero& hero) {
	Troop& troops = level.getTroops();

	for (Monster& m : troops) {
		if (m.stats.isAlive()) {
			addLog(red(m.stats.name + " attacks you for "
				+ std::to_string(m.stats.attack) + " damage!"));
			// std::cout << red(m.stats.name + " attacks you for "
			// 	+ std::to_string(m.stats.attack) + " damage!") << std::endl;
			hero.takeDamage(m.stats.attack);
		}
	}

	if (!hero.stats.isAlive()) {
		addLog(red("You have been defeated..."));
		// std::cout << red("You have been defeated...") << std::endl;
		exit(0);
	}
}

Difficulty selectDifficulty() {
	while (true) {
		std::cout << "[1] Easy" << std::endl;
		std::cout << "[2] Normal" << std::endl;
		std::cout << red("[3] Hard") << std::endl;
		std::cout << green("Select Difficulty: ");

		std::string difficulty;
		std::cin >> difficulty;

		if (difficulty.size() > 1 || (!std::isdigit(difficulty[0]) && difficulty != "q")) {
			std::cout << "Please select a difficulty or press 'q' to quit..." << std::endl;
		}
		else if (difficulty == "q") {
			exit(0);
		}
		else if (std::stoi(difficulty) == 1) {
			return Difficulty::EASY;
		}
		else if (std::stoi(difficulty) == 2) {
			return Difficulty::NORMAL;
		}
		else if (std::stoi(difficulty) == 3) {
			return Difficulty::HARD;
		}
		else {
			std::cout << red("\nPlease select a difficulty or press 'q' to quit...") << std::endl;
		}
	}
	std::cout << std::endl;
}

Hero createHero(const Difficulty difficulty) {
	Hero hero(difficulty);
	hero.setName();
	return hero;
}

void displayHud(const Hero& hero) {
	std::cout << green("NAME: " + hero.stats.name)
		<< green(" | HP: " + std::to_string(hero.stats.health))
		<< green(" | POTIONS: " + std::to_string(hero.getPotions()))
		<< std::endl;
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