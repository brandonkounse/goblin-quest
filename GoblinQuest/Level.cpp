#include <algorithm>
#include "level.h"

Level::Level(const Troop &troops, const int levelNum) {
	this->troops = troops;
	this->levelNum = levelNum;
}

Troop& Level::getTroops() {
	return this->troops;
}

bool Level::isCleared() {
	return std::all_of(troops.begin(), troops.end(), [](const Monster& m) {
		return !m.stats.isAlive();
	});
}

int Level::getLevelNum() const {
	return this->levelNum;
}