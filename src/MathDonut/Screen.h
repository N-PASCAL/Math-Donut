#pragma once
#include "Settings.h"

class Screen
{
public:
    Screen(Settings settings);
    void    Display(int w , int h);

private:
    int     m_width;
    int     m_height;
    
};
