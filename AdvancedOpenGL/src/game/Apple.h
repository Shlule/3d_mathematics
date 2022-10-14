#pragma once 
#include"CubeObject.h"
#include"../engine/Assets.h"

class CubeMesh;

class Apple{
public:

    Apple(float xP, float yP, float zP, CubeMesh* cubeMeshP);

    void draw(Shader& shaderP);
    void clean();

private:
    float posX{ 0.0f };
    float posY{ 0.0f };
    float posZ{ 0.0f };

    CubeMesh* cubeMesh;
    CubeObject* cubeObject;
};