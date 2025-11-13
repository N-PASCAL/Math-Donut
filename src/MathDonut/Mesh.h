#pragma once
#include <vector>

class Mesh
{
public:
    struct Vertex
    {
        int x;
        int y;
        int z;
    };

    std::vector<Vertex> vertices;
    void                Debug(Vertex v);
};
