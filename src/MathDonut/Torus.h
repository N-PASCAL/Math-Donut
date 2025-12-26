#pragma once
#include "Mesh.h"

class Torus : public Mesh
{
public:
    using Mesh::Mesh;
    void GenerateTorus(float majorRadius, float minorRadius);
};
