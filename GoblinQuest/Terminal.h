#pragma once
#include "hero.h"
#include "level.h"

extern const char* const GREEN;
extern const char* const RED;
extern const char* const RESET;

std::string narrate(std::string text);
std::string narrateDanger(std::string text);
void displayHud(Hero& hero);
void displayLevel(Level& level);