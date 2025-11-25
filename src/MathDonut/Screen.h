#pragma once
#include <vector>

class Settings;

class Screen
{
    public:
    Screen(Settings const& settings);
    void Display() const;

    private:
    int m_width;
    int m_height;
    char m_background;
    char m_meshProjection;
    float m_zPosition;
    std::vector<char> m_pixels;
};