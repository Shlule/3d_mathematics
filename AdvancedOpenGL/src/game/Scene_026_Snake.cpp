#include"Scene_026_Snake.h"
#include"../engine/Timer.h"
#include"../engine/MacroUtils.h"

#include<cstdlib>
#include<ctime>
#include<GL/glew.h>

Scene_026_Snake::Scene_026_Snake(){

}
Scene_026_Snake::~Scene_026_Snake(){
    clean();
}

void Scene_026_Snake::setGame(Game *_game){
    game=_game;
}
void Scene_026_Snake::load(){
    std::srand((int)std::time(nullptr));
    Assets::loadShader(SHADER_VERT(SHADER_NAME),SHADER_FRAG(SHADER_NAME),"","","",SHADER_ID(SHADER_NAME));
    projection = Matrix4::createPerspectiveFOV(70.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);

    cubeMesh = new CubeMesh();
    cubeMesh->load();

    snake = new Snake(0.0f,1.0f,-4.0f,cubeMesh);
    snake->addPart();

    apple = new Apple(0.0f,0.5f,-4.0f,cubeMesh);



    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));

    cubes.emplace_back(0.0f, 0.0f, cubeMesh);
    cubes.emplace_back(-0.25f,0.0f ,cubeMesh);
}

void Scene_026_Snake::clean(){
    cubeMesh->clean();
    delete cubeMesh;
    snake->clean();
    delete snake;
    apple->clean();
    delete apple;

}

void Scene_026_Snake::pause(){

}
void Scene_026_Snake::resume(){

}
 void Scene_026_Snake::handleEvent(const InputState &inputState){
    if(inputState.keyboardState.isDown(SDL_SCANCODE_W)){
        snake->moveUp();
    }

    if(inputState.keyboardState.isDown(SDL_SCANCODE_S)){
        snake->moveDown();
    }

    if(inputState.keyboardState.isDown(SDL_SCANCODE_A)){
        snake->moveLeft();
    }

    if(inputState.keyboardState.isDown(SDL_SCANCODE_D)){
        snake->moveRight();
    }

    
}
void Scene_026_Snake::update(float dt){
    /*for (auto& cube : cubes){
        cube.update();
    }*/
    float formerXPosition = cubes[0].getX();
    newXPosition = formerXPosition + 0.02f;
    cubes[0].setPosition(newXPosition, cubes[0].getY());

    for(int i = 1 ; i < cubes.size(); i++ ){
        cubes[i].setPosition(cubes[i-1].getPrevPosX(),cubes[i-1].getPrevPosY());
    }

    snake->update();

}
void Scene_026_Snake::draw(){

    static const GLfloat bgColor[] = {0.0f, 0.0f, 0.2f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    shader.use();
    shader.setMatrix4("proj_matrix", projection);
    

    for(CubeObject& cube : cubes){
        cube.draw(shader);
    }
    snake->draw(shader);
    apple->draw(shader);


}

