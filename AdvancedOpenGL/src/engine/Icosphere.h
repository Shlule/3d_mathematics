#pragma once

#include<iostream>
#include<vector>
#include<map>

class Icosphere{

public:

    Icosphere(float radiusP = 1.0f, int subdivisionP = 1, bool smoothP = false);

    std::vector<float> computeIcosahedronVertices();
    void computeHalfVertex(const float v1[3], const float v2[3], float length, float newV[3]);
    float computeScaleForLength(const float v[3], float length);
    void subdivideVerticesFlat();
    void displayvertices(std::vector<float> verticesP);
    void addTriangle(const float v1[3], const float v2[3], const float v3[3]);
    void addIndices(unsigned int i1, unsigned int i2, unsigned int i3);



private:

    float radius;
    int subdivision;
    bool smooth;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;

};
