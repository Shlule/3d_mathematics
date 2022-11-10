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
    Assets::loadShader(SHADER_VERT(SHADER_NAME),SHADER_PATH_+"007_SpinningCube.frag","","","", SHADER_ID(SHADER_NAME));

    // create a VAO 
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // set the projection matrix4
    proj = Matrix4::createPerspectiveFOV(70.0f, game->windowWidth, game->windowHeight, 0.1f, 1000.0f);
    vector<float> x = icosphere.computeIcosahedronVertices();

    static  GLfloat vertexPositions[36];
    for(int i = 0; i < x.size(); i++) 
    {
        vertexPositions[i] = x[i];
        std::cout<<vertexPositions[i]<<'\n';
    }

    static const GLushort Faces[] = {
        2, 1, 0,
        3, 2, 0,
        4, 3, 0,
        5, 4, 0,
        1, 5, 0,
        11, 6,  7,
        11, 7,  8,
        11, 8,  9,
        11, 9,  10,
        11, 10, 6,
        1, 2, 6,
        2, 3, 7,
        3, 4, 8,
        4, 5, 9,
        5, 1, 10,
        2,  7, 6,
        3,  8, 7,
        4,  9, 8,
        5, 10, 9,
        1, 6, 10 };

    indexCount = sizeof(Faces)/ sizeof(Faces[0]);
    
    
    
    // create VBO for positions:
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);
    
    // Cretae VBO for indices:
    GLuint indices;
    glGenBuffers(1,&indices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER , indices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Faces), Faces, GL_STATIC_DRAW);

    //glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);

    

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    shader = Assets::getShader(SHADER_ID(SHADER_NAME));

}

void Scene_027_microBios::update(float dt) {
    const float t = Timer::getTimeSinceStart() * 0.3f;
    transform = Matrix4::createTranslation(Vector3(0.0f, 0.0f, -4.0f))
        * Matrix4::createTranslation(Vector3(Maths::sin(2.1f * t) * 0.5f, Maths::cos(1.7f * t) * 0.5f, Maths::sin(1.3f * t) * Maths::cos(1.5f * t) * 2.0f))
        * Matrix4::createRotationY(t * 45.0f / 10.0f)
        * Matrix4::createRotationX(t * 81.0f / 10.0f);
}

void Scene_027_microBios::draw()
{
   static const GLfloat bgColor[] = {0.0f, 0.0f, 0.2f, 1.0f};
    
    shader.use();
    shader.setMatrix4("mv_matrix", transform);
    shader.setMatrix4("proj_matrix", proj);

    shader.setFloat("TessLevelInner",3.0);
    shader.setFloat("TessLevelOuter",3.0);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    glDrawElements(GL_TRIANGLE_STRIP,indexCount,GL_UNSIGNED_SHORT, 0 );
    
    
}
