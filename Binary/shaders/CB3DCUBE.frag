#version 330 core
//in vec3 ourColor;
in vec2 TexCoord;
out vec4 colorUseAnyName;
uniform sampler2D shaderUseAnyname;
uniform sampler2D secondshader;
void main()
{
	colorUseAnyName = mix(texture(shaderUseAnyname, TexCoord), texture(secondshader, 1.0f - TexCoord), 0.79);
	//	colorUseAnyName = texture(shaderUseAnyname, TexCoord) * vec4(ourColor, 1.0f);
	//color = texture(ourTexture, TexCoord);
}

