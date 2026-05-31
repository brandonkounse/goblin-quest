#pragma once
#include <vector>
#include <string>

extern const char* const GREEN;
extern const char* const RED;
extern const char* const BLUE;
extern const char* const ORANGE;
extern const char* const RESET;

extern std::vector<std::string> COMBAT_LOG;

std::string green(const std::string& text);
std::string red(const std::string &text);
std::string blue(const std::string &text);
std::string orange(const std::string &text);

void addLog(const std::string& message);
void printLog(const std::vector<std::string>& messages);