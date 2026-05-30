#include "level.h"

Level createLevel2() {
	const Troop minotaurs = {
		Monster("Minotaur Warlord", 60, 15),
		Monster("Minotaur Battlemage", 30, 20)
	};
	return { minotaurs, 2 };
}