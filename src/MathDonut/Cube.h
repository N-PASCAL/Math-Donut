#pragma once
#include "Mesh.h"

class Cube : public Mesh
{
public:
    using Mesh::Mesh;
    void GenerateCube(float size);
    
    private:
    void _GenerateFace(float size, int axis, float direction);
    float _ComputeCoordinate(int index, float halfSize) const;
    Vertex _CreateVertex(float u, float v, float depth, int axis, float dir) const;
};
