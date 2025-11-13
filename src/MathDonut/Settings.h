#pragma once

class Settings
{
public:
    Settings(int argc, char** argv);
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
    int GetMeshResolution() const { return 20; } // Fixed resolution for simplicity

private:
    void _ParseArguments(int argc, char** argv);
    
    int m_screenWidth;
    int m_screenHeight;
};