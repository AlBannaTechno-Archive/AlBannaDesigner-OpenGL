//#include"ToShaderBookHighlight.h"
#version 330 core
layout(location = 0) in vec3 position;

// vUV is equal to gl_FragCoord/uScreenResolution
// do some pixel shader related work

out vec3 TransColor;
void main()
{
//	gl_Position = vec4(position, 1.0f);
	gl_Position = vec4(position, 1.0f);
	TransColor = position;
	
}

