#include "Screen.h"

#include <iostream>

Screen::Screen(Settings settings)
{
    m_width = settings.GetScreenWidth();
    m_height = settings.GetScreenHeight();
}

void Screen::Display(int w , int h)
{
    w = m_width;
    h = m_height;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }
}
