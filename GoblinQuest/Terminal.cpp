#include <iostream>
#include "terminal.h"

const char* const GREEN = "\x1b[32m";
const char* const RED = "\x1b[31m";
const char* const RESET = "\x1b[0m";

std::string green(std::string text) {
    return GREEN + text + RESET;
}

std::string red(std::string text) {
    return RED + text + RESET;
}