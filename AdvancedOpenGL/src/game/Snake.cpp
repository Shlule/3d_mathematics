#include"Snake.h"
#include"CubeMesh.h"

Snake::Snake(float xP, float yP, float zP, CubeMesh* cubeMeshP)
: posX {xP}, posY{yP}, posZ{zP}, cubeMesh{cubeMeshP}
{
    snakePart.emplace_back(posX,posY,cubeMesh);
}

void Snake::addPart(){
    snakePart.emplace_back(posX-0.25f,posY, cubeMesh);

}

void Snake::moveUp(){
    setSpeedX(0.0f);
    setSpeedY(0.02f);
}
void Snake::moveDown(){
    setSpeedX(0.0f);
    setSpeedY(-0.02f);
}
void Snake::moveLeft(){
    setSpeedX(-0.02f);
    setSpeedY(0.0f);
}
void Snake::moveRight(){
    setSpeedX(0.02f);
    setSpeedY(0.0f);
}

void Snake::update(){
    float formerXPosition = snakePart[0].getX();
    float formerYPosition = snakePart[0].getY();
    newXPosition = formerXPosition + speedX;
    newYPosition = formerYPosition + speedY;

    snakePart[0].setPosition(newXPosition, newYPosition);

    for(int i =1; i<snakePart.size();i++){
        snakePart[i].setPosition(snakePart[i-1].getPrevPosX(),snakePart[i-1].getPrevPosY());
    }
}

void Snake::draw(Shader& shaderP){
    for(CubeObject mycube : snakePart){
        mycube.draw(shaderP);
    }
}

void Snake::clean(){
    cubeMesh->clean();
    delete cubeMesh;
}


