#include <iostream>
#include <Windows.h>

int main(int argc, char *argv[])
{
    
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // DWORD mode;
    // GetConsoleMode(hConsole, &mode);
    // SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    
    std::cout << "\x1b[2J\n";
    std::cout << "\x1b[H\n";
    std::cout << "\x1b[?25l\n";
    std::cout << "Hello, World!\n";
    std::cout << "\x1b[?25h\n";
    
    return 0;
}