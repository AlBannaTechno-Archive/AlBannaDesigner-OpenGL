//#include<ToShaderBookHighlight.h>
#version 330 core
in vec3 ourColor;
in vec2 TexCoord;
out vec4 colorUseAnyName;
uniform sampler2D shaderUseAnyname;
uniform sampler2D secondshader;
uniform sampler2D thirdTex;
void main()
{
	colorUseAnyName = mix(texture(shaderUseAnyname, TexCoord), texture(secondshader, 1.0f - TexCoord)* vec4(ourColor, 1.0f), 0.5);
}
