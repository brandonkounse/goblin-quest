#pragma once
#include "Difficulty.h"

struct CombatConfig {
    double monsterHitChance;
    double heroHitChance;
};

inline CombatConfig createCombatConfig(const Difficulty difficulty) {
    switch (difficulty) {
        case Difficulty::EASY:
            return {0.50, 0.85};
        case Difficulty::NORMAL:
            return {0.70, 0.75};
        case Difficulty::HARD:
            return {0.80, 0.65};
        default:
            return {0.70, 0.75};
    }
}
