#include "level.h"

Level createLevel1() {
	const Troop goblins = {
		Monster("Goblin Scout", 30, 5),
		Monster("Goblin Warrior", 50, 8),
		Monster("Goblin Shaman", 40, 10)
	};
	return { goblins, 1 };
}