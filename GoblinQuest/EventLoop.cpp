#include <iostream>
#include "terminal.h"
#include "hero.h"
#include "level1.h"
#include "eventloop.h"

void play() {
	Difficulty difficulty = selectDifficulty();

}

Difficulty selectDifficulty() {
	while (true) {
		std:: cout << narrate("Please select difficult : ") << std::endl;
		std::cout << "[1] Easy" << std::endl;
		std::cout << "[2] Normal" << std::endl;
		std::cout << narrateDanger("[3] Hard") << std::endl;

		std::string difficulty;
		std::cin >> difficulty;

		if (difficulty.size() > 1 || !std::isdigit(difficulty[0])) {
			std::cout << "Please select a difficulty or press 'q' to quit..." << std::endl;
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
		else if (difficulty == "q") {
			exit(0);
		}
		else {
			std::cout << "Please select a difficulty or press 'q' to quit..." << std::endl;
		}
	}
}