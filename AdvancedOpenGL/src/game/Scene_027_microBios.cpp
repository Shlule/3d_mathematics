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
    Assets::loadShader(SHADER_PATH_+"screen.vert",SHADER_PATH_+"fractalNoise.frag", "", "","", SHADER_ID(SHADER_NAME));


    shader = Assets::getShader(SHADER_ID(SHADER_NAME));
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void Scene_027_microBios::update(float dt) {
    totalTime += dt;
}

void Scene_027_microBios::draw()
{
    static const GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};
    // static const GLfloat one = 1.0f;
    // float f = totalTime * timeScale;

    // glClearBufferfv(GL_COLOR, 0, black);
    // glClearBufferfv(GL_DEPTH, 0, &one);


    // proj = Matrix4::createPerspectiveFOV(45.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);
    // view = Matrix4::createTranslation(Vector3(0.0f, 0.0f, -8.0f)) *
    //                         Matrix4::createRotationY(f * 15.0f) *
    //                         Matrix4::createRotationX(f * 21.0f);

    // shader.use();
    // shader.setMatrix4("proj_matrix", proj);
    // shader.setMatrix4("mv_matrix", view);
    // shader.setFloat("normal_length", sinf((float)f * 8.0f) * cosf((float)f * 6.0f) * 0.03f + 0.05f);

    // object.render();

    glClearBufferfv(GL_COLOR, 0, black);
    shader.use();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
