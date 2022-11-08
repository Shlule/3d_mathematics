#version 450 core

layout (vertices = 4) out;

uniform float innerTessellation;

void main(void)
{
    if(gl_InvocationID == 0) {
        gl_TessLevelInner[0] = innerTessellation;
        gl_TessLevelInner[1] = innerTessellation;
        gl_TessLevelOuter[0] = 5.0;
        gl_TessLevelOuter[1] = 5.0;
        gl_TessLevelOuter[2] = 5.0;
        gl_TessLevelOuter[3] = 5.0;
    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}
