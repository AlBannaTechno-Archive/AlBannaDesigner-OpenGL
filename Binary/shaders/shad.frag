//fragment shader
#version 330 core
out vec4 color;
//in vec4 testcolor;
uniform vec4 testcolor;
void main()
{
    color = testcolor;
}