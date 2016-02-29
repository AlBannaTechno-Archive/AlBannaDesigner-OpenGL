#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec4 Normal;
out vec4 FragPos;
void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
	FragPos=model*vec4(position,1.0f);//we make position as vec4 because model matrix has 4 dia
	Normal=vec4(normal,1.0f);
	Normal=normal*vec4(model);//we need to modify all vec3 to vec4 see shadow when cube rotations

} 