#include <cstdlib>
#include <iostream>

#include "EventLoop.h"
#include "Level3.h"
#include "monster.h"
#include "terminal.h"
#include "troop.h"
#include "combat.h"

TurnResult chooseAction(Level& level, Hero& hero) {
    std::cout << "\nSelect target to attack, 'h' to heal, 'q' to quit: ";

    std::string action;
    std::cin >> action;

    if (action == "q") {
        exit(0);
    }

    if (action == "h") {
        const int amountHealed = hero.usePotion();
        if (amountHealed > 0) {
            addLog(blue("Potion restored ") + blue(std::to_string(amountHealed)) + blue(" hit points!"));
            return TurnResult::ConsumedTurn;
        } else {
            addLog(red("Could not use potion."));
            return TurnResult::Invalid;
        }
    }

    if (action.size() > 1 || !std::isdigit(action[0])) {
        addLog(red("Invalid input. Please enter a valid number or command."));
        return TurnResult::Invalid;
    }

    const int target = std::stoi(action);

    Troop& troops = level.getTroops();

    if (target < 1 || target > static_cast<int>(troops.size())) {
        addLog(red("Please select a valid target from the enemy list."));
        return TurnResult::Invalid;
    }

    Monster& monster = troops[static_cast<size_t>(target) - 1];
    if (!monster.stats.isAlive()) {
        addLog(red(monster.stats.name + " is already dead!"));
        return TurnResult::Invalid;
    }

    addLog(green("Attacking " + monster.stats.name + " for " + std::to_string(hero.stats.attack) + " damage!"));
    monster.stats.takeDamage(hero.attack());

    if (!monster.stats.isAlive()) {
        addLog(red(monster.stats.name + " has been defeated!"));
    }
    return TurnResult::ConsumedTurn;
}

void troopAction(Level& level, Hero& hero, const CombatConfig& config, std::mt19937& rngEngine) {
    Troop& troops = level.getTroops();

    for (Monster& m : troops) {
        if (m.stats.isAlive()) {
            if (rollForHit(config.monsterHitChance, rngEngine)) {
                addLog(red(m.stats.name + " attacks you for "
                + std::to_string(m.stats.attack) + " damage!"));
                hero.takeDamage(m.stats.attack);
            } else {
                addLog(red(m.stats.name) + " tries to attack...but misses!");
            }
        }
    }

    if (!hero.stats.isAlive()) {
        addLog(red("You have been defeated..."));
        std::exit(0);
    }
}

bool rollForHit(const double hitChance, std::mt19937& gen) {
    std::bernoulli_distribution dist(hitChance);
    return dist(gen);
}