#pragma once 
#include"CubeObject.h"
#include"../engine/Assets.h"
#include<vector>

class CubeMesh;

class Snake{
public:

    Snake(float xP, float yP, float zP, CubeMesh* cubeMeshP);

    void addPart();
    void draw(Shader& shaderP);
    void load();
    void clean();

    void setSpeedX(float value){ speedX = value;}
    void setSpeedY(float value){ speedY = value;}

    void update();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:

std::vector<CubeObject> snakePart;

float posX{ 0.0f };
float posY{ 0.0f };
float posZ{ 0.0f };

float newXPosition{ 0.0f };
float newYPosition{ 0.0f };

float speedX { 0.0f };
float speedY{ 0.0f };

CubeMesh* cubeMesh;


};