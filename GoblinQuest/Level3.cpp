#include "level.h"

Level createLevel3() {
    const Troop boss = {
        Monster("Goblin King Ziixus", 200, 30),
    };
    return { boss, 3 };
}