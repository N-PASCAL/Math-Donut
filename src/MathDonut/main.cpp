#include <iostream>
#include <Windows.h>

#include "Screen.h"
#include "Settings.h"

int main(int argc, char *argv[])
{
    
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // DWORD mode;
    // GetConsoleMode(hConsole, &mode);
    // SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    
    std::cout << "\x1b[2J\n";       // clear
    std::cout << "\x1b[H\n";        // (0,0)
    std::cout << "\x1b[?25l\n";     // cache le curseur
    std::cout << "\x1b[?25h\n";     // montre le curseur

    Screen screen(Settings(argc, argv));
    screen.Display(10, 20);
    
    
    
    return 0;
}