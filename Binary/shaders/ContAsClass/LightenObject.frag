//#ifndef __STOP_SHADER_H__
//#include"ToShaderBookHighlight.h"
//#endif
#version 330 core
out vec4 color;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float Time;
in vec3 Normal;
uniform vec3 lightPos;
in vec3 FragPos;
uniform vec3 viewPos;

void main()
{

	vec3 norm = normalize(Normal);
	vec3 LightDir = normalize(lightPos-FragPos);
	float ambientStrength = 0.1f;
	vec3 ambient = ambientStrength * lightColor;//Scaller
	float dif = max(dot(norm, LightDir), 0.0);
	vec3 diffuse = dif*lightColor;
	//vec3 diffuse = vec3(0.3, 0.4, 0.8);
	float specularStrength = 0.5f;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-LightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor;
	vec3 result = (diffuse + ambient + specular) * objectColor;
	color = vec4(result, 1.0f);

}
//	vec3 result = ambient * objectColor*vec3(sin(Time),cos(Time),tan(Time-cos(Time)))*Scolar;
//	float Scolar = sin(Time) - cos(Time);
