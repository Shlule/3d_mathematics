#pragma once

#include<GL/glew.h>

class CubeMesh{
    public:

    void load();
    void draw();
    void clean();

    private:
    GLuint vao;
    GLuint buffer;
};