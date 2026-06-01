#include <algorithm>
#include <iostream>
#include <limits>

#include "combat.h"
#include "hero.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "terminal.h"
#include "ui.h"

bool isLevel1Completed;
bool isLevel2Completed;
bool isLevel3Completed;

[[noreturn]] void play() {
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
			levelInterlude(hero);
		}
		else if (!isLevel2Completed) {
			Level level = createLevel2();
			while (!level.isCleared()) {
				playLevel(level, hero);
			}
			isLevel2Completed = true;
			clearScreen();
			levelInterlude(hero);
		}
		else if (!isLevel3Completed) {
			Level level = createLevel3();
			while (!level.isCleared()) {
				playLevel(level, hero);
			}
			isLevel3Completed = true;
			clearScreen();
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
}

Hero createHero(const Difficulty difficulty) {
	Hero hero(difficulty);
	hero.setName();
	return hero;
}

void levelInterlude(Hero& hero) {
	displayBanner();
	displayHud(hero);

	hero.gainPotion();
	std::cout << "You've looted 1 potion!" << std::endl;
	std::cout << "Press Enter to continue to the next level";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	clearScreen();

	while (true) {
		displayBanner();
		displayHud(hero);

		std::cout << "Would you like to use a potion before the next level? (y/n) ";
		std::string willUsePotion;
		std::cin >> willUsePotion;

		std::transform(willUsePotion.begin(), willUsePotion.end(), willUsePotion.begin(), [](const unsigned char c) {
			return std::tolower(c);
		});

		if (willUsePotion != "y" && willUsePotion != "n") {
			clearScreen();
			std::cout << "Please select either yes(y) or no(n)" << std::endl;
			continue;
		}

		if (willUsePotion == "y") {
			const int amountHealed = hero.usePotion();
			if (amountHealed > 0) {
				std::cout << blue("\nPotion restored ") << blue(std::to_string(amountHealed)) << blue(" hit points!\n");
				std::cout << "Press Enter to march forward...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
				break;
			} else {
				clearScreen();
				std::cout << red("You are already at full health! Save your potions.\n");
				continue;
			}
		}
		if (willUsePotion == "n") {
			break;
		}
	}
}