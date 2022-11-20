#version 450 core

in vec4 position;
out vec3 vPosition;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;



void main()
{
    vPosition = position.xyz;
    gl_Position = proj_matrix * mv_matrix * position;
    
}










