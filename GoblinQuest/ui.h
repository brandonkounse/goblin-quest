#pragma once
#include "hero.h"

void displayBanner();
void clearScreen();
void displayHud(const Hero& hero);
std::string getColoredHealthStr(const Hero& hero);
std::string getColoredPotionsStr(const Hero& hero);
void displayLevel(Level& level);