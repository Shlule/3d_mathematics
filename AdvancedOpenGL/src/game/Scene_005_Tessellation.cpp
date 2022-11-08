//
// Created by gaetz on 04/12/2019.
//

#include "Scene_005_Tessellation.h"

#include <cstdlib>
#include <ctime>
#include <GL/glew.h>


Scene_005_Tessellation::Scene_005_Tessellation() {
}

Scene_005_Tessellation::~Scene_005_Tessellation() {
    clean();
}

void Scene_005_Tessellation::setGame(Game *_game) {
    game = _game;
}

void Scene_005_Tessellation::load() {
    std::srand((int) std::time(nullptr));
    Assets::loadShader("assets/shaders/005_tessellation.vert", "assets/shaders/005_tessellation.frag",
                                "assets/shaders/005_tessellation.tesc", "assets/shaders/005_tessellation.tese",
                                "", "005_tessellation");

    glPatchParameteri(GL_PATCH_VERTICES , 4);
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    shader = Assets::getShader("005_tessellation");
}

void Scene_005_Tessellation::clean() {
    glDeleteVertexArrays(1, &vao);
}

void Scene_005_Tessellation::pause() {
}

void Scene_005_Tessellation::resume() {
}

void Scene_005_Tessellation::handleEvent(const InputState &inputState) {
}

void Scene_005_Tessellation::update(float dt) {
}
unsigned int cpt {0};

void Scene_005_Tessellation::draw() {
    static const GLfloat bgColor[] = {0.0f, 0.0f, 0.2f, 1.0f};
    glClearBufferfv(GL_COLOR, 0, bgColor);

    shader.use();
    glPointSize(5.0f);
    GLint loc = glGetUniformLocation(shader.id,"innerTessellation");
    double animation= sin(((double)cpt*3.0f)/60.0f)*5.0f+ 5;
    glUniform1f(loc,animation);

    glDrawArrays(GL_PATCHES, 0, 4);
    cpt++;
}
