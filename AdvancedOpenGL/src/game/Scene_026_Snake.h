#ifndef Scene_026_Snake_H
#define Scene_026_Snake_H

#include"../engine/Scene.h"
#include"../engine/Assets.h"
#include"CubeMesh.h"
#include"CubeObject.h"
#include"../engine/input/InputManager.h"
#include"Snake.h"
#include"Apple.h"

class Scene_026_Snake : public Scene{
public:
    Scene_026_Snake();
    ~Scene_026_Snake();
    void load();
    void clean();
    void pause();
    void resume();
    void handleEvent(const InputState &);
    void update(float dt);
    void draw();
    void setGame(Game *);

private:

    Game *game;
    CubeMesh* cubeMesh;
   
    std::vector<CubeObject> cubes;
    Matrix4 projection;
    
    Shader shader;
    float newXPosition { 0 };

    InputManager inputManager;

    Snake* snake;
    Apple* apple;
    


};

#endif//Scene_026_Snake_H