#include"Apple.h"
#include"CubeMesh.h"

Apple::Apple(float xP, float yP, float zP, CubeMesh* cubeMeshP)
: posX {xP}, posY {yP}, posZ{zP}, cubeMesh{cubeMeshP}
{
    cubeObject = new CubeObject(posX,posY,cubeMesh);
}
void Apple::clean(){
    cubeMesh->clean();
    delete cubeMesh;
    delete cubeObject;
}

void Apple::draw(Shader& shaderP){
    cubeObject->draw(shaderP);
}
