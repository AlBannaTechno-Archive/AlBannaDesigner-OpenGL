//#ifndef __STOP_SHADER_H__
//#include"ToShaderBookHighlight.h"
//#endif
#version 330 core
out vec4 color;
uniform vec3 objectColor;
//uniform vec3 lightColor;
uniform float Time;
in vec3 Normal;
//uniform vec3 lightPos;
in vec3 FragPos;
uniform vec3 viewPos;
struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};
struct  Light
{
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
uniform Light light;
uniform Material material;
void main()
{
	
	vec3 ambient = light.ambient*material.ambient;
	
	//Diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position-FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse*(diff*material.diffuse);
	
	//Specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflecDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflecDir), 0.0), material.shininess);
	vec3 specular = light.specular *(spec*material.specular);

	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);
}
