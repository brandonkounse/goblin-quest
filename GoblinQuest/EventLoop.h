#pragma once
#include "terminal.h"
#include "hero.h"

void play();
bool playLevel(Level& level, Hero& hero);
Difficulty selectDifficulty();
Hero createHero(Difficulty difficulty);