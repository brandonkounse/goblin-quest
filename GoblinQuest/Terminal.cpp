#include <iostream>
#include <string>
#include <vector>
#include "terminal.h"

const char* const GREEN = "\x1b[32m";
const char* const RED = "\x1b[31m";
const char* const BLUE = "\x1b[34m";
const char* const ORANGE = "\x1b[38;5;208m";
const char* const RESET = "\x1b[0m";

std::vector<std::string> COMBAT_LOG;

std::string green(const std::string& text) {
    return GREEN + text + RESET;
}

std::string red(const std::string& text) {
    return RED + text + RESET;
}

std::string blue(const std::string& text) {
    return BLUE + text + RESET;
}

std::string orange(const std::string& text) {
    return ORANGE + text + RESET;
}

void addLog(const std::string& message) {
    COMBAT_LOG.push_back(message);
    if (COMBAT_LOG.size() > 10) {
        COMBAT_LOG.erase(COMBAT_LOG.begin());
    }
}

void printLog(const std::vector<std::string>& messages) {
    for (const std::string& message : messages) {
        std::cout << message << std::endl;
    }
}

void clearLog(std::vector<std::string>& messages) {
    messages.clear();
}
