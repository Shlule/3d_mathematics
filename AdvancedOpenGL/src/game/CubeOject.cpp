#include"CubeObject.h"
#include"../engine/Shader.h"
#include"CubeMesh.h"

CubeObject::CubeObject(float xP, float yP ,CubeMesh* cubeMeshP)
: cubeMesh { cubeMeshP }
{
    setPosition(xP , yP);
}

void CubeObject::update(){
    
}

void CubeObject::draw(Shader& shader){
    shader.setMatrix4("mv_matrix", transform);
    cubeMesh->draw();
}

void CubeObject::setPosition(float xP, float yP){
    prevPosX = posX;
    prevPosY = posY;

    posX=xP; 
    posY=yP;
    
    transform = computeTransform();
    
    
}

Matrix4 CubeObject::computeTransform(){
    return Matrix4::createTranslation(Vector3(posX, posY, -4.0f))
    *Matrix4::createScale(Vector3(0.25f,0.25f,0.25f));
}
