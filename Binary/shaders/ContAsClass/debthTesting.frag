// Fragment shader:
// ================
#version 330 core
in vec2 TexCoords;

out vec4 color;

uniform sampler2D texture1;

float LinearizeDepth(float depth)
{
	float near = 0.1;
	float far = 100.0;
	float z = depth * 2.0 - 1.0; // Back to NDC
	return (2.0 * near) / (far + near - z * (far - near));
}
void main()
{
//	float depth = LinearizeDepth(gl_FragCoord.z);
//	color = vec4(vec3(depth), 1.0f);
//	color = normalize(texture(texture1, TexCoords),1.0f);
	
	//color = vec4(sin(gl_FragCoord.z), cos(gl_FragCoord.z), sin(gl_FragCoord.z / gl_FragCoord.x), 1.0f);
//	color *= texture(texture1, TexCoords);
	color = texture(texture1, TexCoords);
	
	//color = texture(texture1, TexCoords);
	//	color = normalize(texture(texture1, TexCoords)*vec4(vec3(gl_FragCoord.z), 1.0f));
//	color = vec4(vec3(gl_FragCoord.z), 1.0f);
}