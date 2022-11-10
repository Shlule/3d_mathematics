#ifndef Scene_027_microBios_H
#define Scene_027_microBios_H

#include "../engine/Scene.h"
#include "../engine/Assets.h"
#include "../engine/MeshObject.h"
#include "../engine/Icosphere.h"

class Scene_027_microBios : public Scene {
public:
    Scene_027_microBios();
    ~Scene_027_microBios();
    void load();
    void clean();
    void pause();
    void resume();
    void handleEvent(const InputState &);
    void update(float dt);
    void draw();
    void setGame(Game *);

private:
    Icosphere icosphere;
    Game *game;
    GLuint vao;
    GLuint buffer;
    float totalTime;
    const float timeScale = 0.05f;
    MeshObject object;

    std::vector<unsigned int> Faces;

    // Uniforms
    Matrix4 transform;
    Matrix4 mvp;
    Matrix4 view;
    Matrix4 proj;

    Shader shader;
};

#endif