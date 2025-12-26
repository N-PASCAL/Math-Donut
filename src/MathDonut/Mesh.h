#pragma once
#include <cstdio>
#include <vector>

class Settings;
class Light;

enum class Axis { X, Y, Z };

struct Vertex
{
    float x, y, z;
    float nx, ny, nz;
    void Rotate(float angle, Axis axis);
    float ComputeIllumination(Light const& light) const;
    void Debug() const { std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\t[nx=%5.2f, ny=%5.2f, nz=%5.2f]\n", x, y, z, nx, ny, nz); }
};

class Mesh
{
    public:
    Mesh(Settings const& settings);
    virtual ~Mesh() = default;
    
    std::vector<Vertex> const& GetVertices() const { return m_vertices; }
    void Rotate(float angle, Axis axis);
    void Debug() const;
 
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);
    void GenerateRectangle(float width, float height);
    void GenerateSquare(float side);

    
    protected:
    std::vector<Vertex> m_vertices;
    int m_resolution;
    void _GenerateSector(float radius, float angle);
};