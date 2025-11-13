#pragma once
#include <iostream>
#include <ostream>
#include <vector>

#include "Settings.h"

class Mesh
{
public:

    Mesh(Settings const &settings);
    
    struct Vertex
    {
        int x;
        int y;
        int z;
        void Debug() const {std::cout << x << ", " << y << ", " << z << '\n';};
    };

    std::vector<Vertex> vertices;
    void Debug() const;
   
    void GenerateSquare(float side);
    void GenerateRectangle(float width, float height);
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);

private:
    std::vector<Vertex> m_vertices;
    float m_resolution;
    void _GenerateSector(float radius, float angle);
};
