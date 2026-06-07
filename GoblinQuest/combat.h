#pragma once

#include <random>
#include "EventLoop.h"
#include "gameconfig.h"

TurnResult chooseAction(Level& level, Hero& hero);
void troopAction(Level& level, Hero& hero, const CombatConfig& config, std::mt19937& rngEngine);
bool rollForHit(double hitChance, std::mt19937& gen);