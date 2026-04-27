#include <iostream>
#include <windows.h>
//#include "hero.h"
//#include "terminal.h"
#include "eventloop.h"

void enableColors() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

int main() {
    // If Windows OS is detected enableColors will run for a colored terminal environment.
    enableColors();

    // Temporary home until this gets refactored.
    play();
}