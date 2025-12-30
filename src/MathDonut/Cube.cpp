#include "Cube.h"

void Cube::GenerateCube(float size)
{
    m_vertices.clear();
    // X Axis
    _GenerateFace(size, 0, 1.f);
    _GenerateFace(size, 0, -1.f);
    // Y Axis
    _GenerateFace(size, 1, 1.f);
    _GenerateFace(size, 1, -1.f);
    // Z Axis
    _GenerateFace(size, 2, 1.f);
    _GenerateFace(size, 2, -1.f);
}

void Cube::_GenerateFace(float size, int axis, float direction)
{
    float half = size * 0.5f;
    for(int i = 0; i < m_resolution; i++)
    {
        float u = _ComputeCoordinate(i, half);
        for(int j = 0; j < m_resolution; j++)
        {
            float v = _ComputeCoordinate(j, half);
            m_vertices.push_back(_CreateVertex(u, v, half, axis, direction));
        }
    }
}

float Cube::_ComputeCoordinate(int index, float halfSize) const
{
    // [0, resolution] -> [-half, +half]
    return (2.0f * index / (m_resolution - 1) - 1.0f) * halfSize;
}

Vertex Cube::_CreateVertex(float u, float v, float depth, int axis, float dir) const
{
    float d = depth * dir;
    if (axis == 0)  // Face X (Gauche/Droite)
        return {.x = d, .y = u, .z = v, .nx = dir, .ny = 0.f, .nz = 0.f};
    if (axis == 1) // Face Y (Haut/Bas)
        return {.x = u, .y = d, .z = v, .nx = 0.f, .ny = dir, .nz = 0.f};
    return {.x = u, .y = v, .z = d, .nx = 0.f, .ny = 0.f, .nz = dir};   // Face Z (Devant/Derrière)
}