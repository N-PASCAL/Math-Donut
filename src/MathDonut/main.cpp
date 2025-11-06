#include <iostream>
#include <Windows.h>

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

    int h = atoi(argv[1]);
    int w = atoi(argv[2]);
    
    std::cout << h << " " << w << "\n";
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            std::cout << ".";
        std::cout << "\n";
    }
    
    return 0;
}