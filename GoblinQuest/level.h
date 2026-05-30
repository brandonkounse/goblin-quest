#pragma once
#include "troop.h"

class Level {
public:
	Level(const Troop &troops, int levelNum);
	Troop& getTroops();
	bool isCleared();
	int getLevelNum() const;
private:
	Troop troops;
	int levelNum;
};