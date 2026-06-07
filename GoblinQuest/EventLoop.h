#pragma once

#include <random>

#include "gameconfig.h"
#include "hero.h"
#include "level.h"

enum class TurnResult {
    Invalid,
    ConsumedTurn
};

[[noreturn]] void play();
void playLevel(Level& level, Hero& hero, const CombatConfig& config, std::mt19937& rngEngine);
Difficulty selectDifficulty();
Hero createHero(Difficulty difficulty);
void levelInterlude(Hero& hero);