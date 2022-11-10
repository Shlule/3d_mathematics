#version 450 core

in vec4 position;
out vec3 vPosition;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

out VS_OUT
{
    vec4 color;
} vs_out;

void main()
{
    vPosition = position.xyz;
    gl_Position = proj_matrix * mv_matrix * position;
    vs_out.color = position * 2.0 + vec4(0.5, 0.5, 0.5, 0.0);
}










