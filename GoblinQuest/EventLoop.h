#pragma once
#include "terminal.h"
#include "hero.h"
#include "level.h"

enum class TurnResult {
    Invalid,
    ConsumedTurn
};

void play();
void playLevel(Level& level, Hero& hero);
TurnResult chooseAction(Level& level, Hero& hero);
Difficulty selectDifficulty();
Hero createHero(Difficulty difficulty);
void displayHud(const Hero& hero);
void displayLevel(Level& level);
void displayBanner();
void clearScreen();
void troopAction(Level& level, Hero& hero);