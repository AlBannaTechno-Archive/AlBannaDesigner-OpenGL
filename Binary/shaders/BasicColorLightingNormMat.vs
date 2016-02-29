#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 Normal;
out vec3 FragPos;
void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
	FragPos=vec3 (model*vec4(position,1.0f));//we make position as vec4 because model matrix has 4 dia
	Normal = mat3(transpose(inverse(model))) * normal;//it solve shadow motion problem,and the best
	//for this to do normal on cpu not gpu because it's will do at  every frame',
	//we can do this via uniform
	//Normal=normal*vec3(model);//we need to modify all vec3 to vec4 see shadow when cube rotations
} 