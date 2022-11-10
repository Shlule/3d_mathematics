#version 450

layout(vertices = 3 ) out;

// entry my vertex position wich come of my vertex shader
in vec3 vPosition[];
out vec3 tcPosition[];

uniform float TessLevelInner;
uniform float TessLevelOuter;

#define ID gl_InvocationID

void main(){
    // simply pass my VertexPosition and return the same thing to my TE shader
    tcPosition[ID] = vPosition[ID];

    // do the execution only once 
    if(ID==0){
        gl_TessLevelInner[0] = TessLevelInner;
        gl_TessLevelOuter[0] = TessLevelOuter;
        gl_TessLevelOuter[1] = TessLevelOuter;
        gl_TessLevelOuter[2] = TessLevelOuter;
    }
}