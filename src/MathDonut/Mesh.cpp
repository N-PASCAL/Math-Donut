#define _USE_MATH_DEFINES

#include <cmath>
#include "Mesh.h"
#include "Settings.h"
#include "Light.h"

void Vertex::Rotate(float angle, Axis axis)
{
    Vertex previous = *this;
    float cos = std::cos(angle);
    float sin = std::sin(angle);
    switch(axis)
    {
        case Axis::X:
        {
            y = previous.y * cos - previous.z * sin;
            z = previous.y * sin + previous.z * cos;
            ny = previous.ny * cos - previous.nz * sin;
            nz = previous.ny * sin + previous.nz * cos;
        }
        break;
        case Axis::Y:
        {
            x = previous.z * sin + previous.x * cos;
            z = previous.z * cos - previous.x * sin;
            nx = previous.nz * sin + previous.nx * cos;
            nz = previous.nz * cos - previous.nx * sin;
        }
        break;
        case Axis::Z:
        {
            x = previous.x * cos - previous.y * sin;
            y = previous.x * sin + previous.y * cos;
            nx = previous.nx * cos - previous.ny * sin;
            ny = previous.nx * sin + previous.ny * cos;
        }
        break;
    }
}

float Vertex::ComputeIllumination(Light const& light) const
{
    return nx*light.GetNormalizedLight().nx + ny*light.GetNormalizedLight().ny + nz*light.GetNormalizedLight().nz; 
}

Mesh::Mesh(Settings const& settings)
: m_resolution(settings.GetMeshResolution())
{
}

void Mesh::Rotate(float angle, Axis axis)
{
    for(Vertex& vertex : m_vertices)
    {
        vertex.Rotate(angle, axis);
    }
}

void Mesh::Debug() const
{
    for(Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}


void Mesh::GenerateCircle(float radius)
{
    _GenerateSector(radius, 2 * M_PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
    _GenerateSector(radius, M_PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        for(int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f*i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f*j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;
            m_vertices[m_resolution * i + j].nx = 0.f;
            m_vertices[m_resolution * i + j].ny = 0.f;
            m_vertices[m_resolution * i + j].nz = -1.f;
        }
    }
}

void Mesh::GenerateSquare(float side)
{
    GenerateRectangle(side, side);
}


void Mesh::_GenerateSector(float radius, float angle)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for(int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = r * std::cos(theta);
            m_vertices[m_resolution * i + j].y = r * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;
            m_vertices[m_resolution * i + j].nx = 0.f;
            m_vertices[m_resolution * i + j].ny = 0.f;
            m_vertices[m_resolution * i + j].nz = -1.f;
        }
    }
}
