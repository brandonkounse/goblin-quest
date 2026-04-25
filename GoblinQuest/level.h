#pragma once
#include "troop.h"

class Level {
public:
	Level(Troop troops, int levelNum);
	Troop& getTroops();
	bool isCleared();
	int getLevelNum();
private:
	Troop troops;
	int levelNum;
};