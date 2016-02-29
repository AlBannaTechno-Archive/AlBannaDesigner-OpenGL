//vertex shader
#version 330 core
layout (location = 0) in vec3 position;
//out vec4 testcolor;
void main()
{
    gl_Position = vec4(position, 1.0f);
	//testcolor=vec4(0.3f,0.4f,0.1f,0.5f);
}
