#pragma once

#include "hero.h"
#include "level.h"

enum class TurnResult {
    Invalid,
    ConsumedTurn
};

[[noreturn]] void play();
void playLevel(Level& level, Hero& hero);
Difficulty selectDifficulty();
Hero createHero(Difficulty difficulty);
void levelInterlude(Hero& hero);