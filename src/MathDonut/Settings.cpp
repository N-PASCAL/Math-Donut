#include "Settings.h"

#include <iostream>

Settings::Settings(int argc, char* argv[]) : m_screenWidth(100), m_screenHeight(20)
{
    ParseArgs(argc, argv);
}

void Settings::ParseArgs(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "-w" && i + 1 < argc)
        {
            m_screenWidth = atoi(argv[++i]);
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            m_screenHeight = atoi(argv[++i]);
        }
    }
}
