#pragma once

#include"../engine/maths/Matrix4.h"

class CubeMesh;
class Shader;

class CubeObject{
public:
    CubeObject(){}
    CubeObject(float xP, float yP, CubeMesh* cubemeshP);

    void update();
    void draw(Shader& shader);

    float getX() const {return posX;}
    float getY() const {return posY;}
    float getPrevPosX() const {return prevPosX;}
    float getPrevPosY() const {return prevPosY;}
    // this function build a Matrix4 for the translation 
    void setPosition(float xP, float yP);
    // function that buildall transformation matrix and apply change
    Matrix4 computeTransform();

private:
    float posX { 0.0f };
    float posY { 0.0f };
    float prevPosX{0.0f};
    float prevPosY{0.0f};
    Matrix4 transform {};
    

    CubeMesh* cubeMesh{nullptr};

};