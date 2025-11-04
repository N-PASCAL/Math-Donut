#include <iostream>
#include <Windows.h>

int main()
{
    
    
    std::cout << "Hello, World!\n";
    
    std::cout << "\x1b[2J\n";
    std::cout << "\x1b[H\n";
    std::cout << "\x1b[?25l\n";

    while (true)
    {
        
    }
    return 0;
}