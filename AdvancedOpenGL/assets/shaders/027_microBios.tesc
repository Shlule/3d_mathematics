#version 450

layout(vertices = 3 ) out;

in vec3 vPosition[];
out vec3 tcPosition[];

uniform float TessLevelInner;
uniform float TessLevelOuter;


void main(){

    tcPosition[gl_InvocationID] = vPosition[gl_InvocationID];
    // do the execution only once 
    if(gl_InvocationID == 0){
        gl_TessLevelInner[0] = TessLevelInner;
        gl_TessLevelOuter[0] = TessLevelOuter;
        gl_TessLevelOuter[1] = TessLevelOuter;
        gl_TessLevelOuter[2] = TessLevelOuter;
    }
    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
    
}