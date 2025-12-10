#define _USE_MATH_DEFINES

#include <chrono>
#include <iostream>
#include <windows.h> // For console settings
#include <cmath>
#include <csignal>
#include <signal.h>
#include <thread>

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void SetCursorVisible(bool visible)
{
    if(visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

void SetCursorHome()
{
    std::cout << "\x1b[H";
}

void SignalHandler(int signum)
{
    SetCursorVisible(true);
    SetCursorHome();
    std::exit(signum);
}

int main(int argc, char** argv)
{
    InitConsole();
    ClearConsole();
    SetCursorVisible(false);

    std::signal(SIGINT, SignalHandler);
    
    Settings settings(argc, argv);
    Screen screen(settings);
    Mesh mesh(settings);
    
    mesh.GenerateTorus(4.f, 0.9f);

    while (true)
    {
        SetCursorHome();
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::X);
        mesh.Rotate(settings.GetMeshRotationYPerFrame(), Axis::Y);
        mesh.Rotate(settings.GetMeshRotationZPerFrame(), Axis::Z);
        screen.Display(mesh);
        std::this_thread::sleep_for(std::chrono::microseconds(settings.GetFrameDuration()));
        
    }

    SetCursorVisible(true);
    return 0;
}