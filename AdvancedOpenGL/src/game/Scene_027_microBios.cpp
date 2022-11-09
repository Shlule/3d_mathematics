#include "Scene_027_microBios.h"
#include "../engine/Timer.h"
#include "../engine/MacroUtils.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>

const std::string SHADER_PATH_ = "assets/shaders/";


Scene_027_microBios::Scene_027_microBios(): totalTime(0) {

}

Scene_027_microBios::~Scene_027_microBios() {
    clean();
}

void Scene_027_microBios::setGame(Game *_game) {
    game = _game;
}

void Scene_027_microBios::clean() {
    glDeleteVertexArrays(1, &vao);
}

void Scene_027_microBios::pause() {
}

void Scene_027_microBios::resume() {
}

void Scene_027_microBios::handleEvent(const InputState &inputState) {

}

void Scene_027_microBios::load() {
    std::srand((int) std::time(nullptr));
    Assets::loadShader(SHADER_PATH_+"007_SpinningCube.vert", SHADER_PATH_+"007_SpinningCube.frag", "", "", "", SHADER_ID(SHADER_NAME));

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    proj = Matrix4::createPerspectiveFOV(70.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);
    vector<float> x = icosphere.computeIcosahedronVertices();

    static  GLfloat vertexPositions[36];
    for(int i = 0; i < x.size(); i++) 
    {
        vertexPositions[i] = x[i];
        std::cout<<vertexPositions[i]<<'\n';
    }
    

    // Generate data and put it in buffer object
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

    // Setup vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    //glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));

}

void Scene_027_microBios::update(float dt) {
    const float t = Timer::getTimeSinceStart() * 0.3f;
    transform = Matrix4::createTranslation(Vector3(0.0f, 0.0f, -4.0f));
       /* Matrix4::createTranslation(Vector3(Maths::sin(2.1f * t) * 0.5f, Maths::cos(1.7f * t) * 0.5f, Maths::sin(1.3f * t) * Maths::cos(1.5f * t) * 2.0f))
        * Matrix4::createRotationY(t * 45.0f / 10.0f)
        * Matrix4::createRotationX(t * 81.0f / 10.0f);*/
}

void Scene_027_microBios::draw()
{
   static const GLfloat bgColor[] = {0.0f, 0.0f, 0.2f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);
    
    shader.use();
    shader.setMatrix4("mv_matrix", transform);
    shader.setMatrix4("proj_matrix", proj);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    glDrawArrays(GL_LINE_STRIP, 0, 36);
    
    
}
