#pragma once
#include "terminal.h"
#include "hero.h"
#include "level.h"

void play();
void playLevel(Level& level, Hero& hero);
void chooseAction(Level& level, Hero& hero);
Difficulty selectDifficulty();
Hero createHero(Difficulty difficulty);
void displayHud(Hero& hero);
void displayLevel(Level& level);
void displayBanner();
void clearScreen();
void troopAction(Level& level, Hero& hero);