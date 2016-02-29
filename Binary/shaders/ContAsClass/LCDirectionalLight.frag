//#include<ToShaderBookHighlight.h>
#version 330 core
struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float     shininess;
};

struct Light {
	//vec3 position;
	vec3 direction;
	vec3 position;
	float cutOff;
	float outerCutOff;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float constant;
	float linear;
	float quadratic;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	// Diffuse 
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

	// Specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

	// Spotlight (soft edges)
	float theta = dot(lightDir, normalize(-light.direction));
	float epsilon = (light.cutOff - light.outerCutOff);
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
	diffuse *= intensity;
	specular *= intensity;

	// Attenuation
	float distance = length(light.position - FragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	color = vec4(ambient + diffuse + specular, 1.0f);
}
/*
// Ambient
vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

// Diffuse
vec3 norm = normalize(Normal);
// vec3 lightDir = normalize(light.position - FragPos);
vec3 lightDir = normalize(-light.direction);
float diff = max(dot(norm, lightDir), 0.0);
vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

// Specular
vec3 viewDir = normalize(viewPos - FragPos);
vec3 reflectDir = reflect(-lightDir, norm);
float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

float distance = length(light.position - FragPos);//it's Should be position instead of direction
float attenuation = 1.0f / (light.constant + light.linear * distance +
light.quadratic * (distance * distance));

ambient *= attenuation;
diffuse *= attenuation;
specular *= attenuation;
color = vec4(ambient + diffuse + specular, 1.0f);
*/

//////////////
/*
// Check if lighting is inside the spotlight cone
vec3 lightDir = normalize(light.position - FragPos);
float theta = dot(lightDir, normalize(-light.direction));
float epsilon = light.cutOff - light.outerCutOff;
float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

if (theta > light.cutOff) // Remember that we're working with angles as cosines instead of degrees so a '>' is used.
{
// Ambient
vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));

// Diffuse
vec3 norm = normalize(Normal);
float diff = max(dot(norm, lightDir), 0.0);
vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));

// Specular
vec3 viewDir = normalize(viewPos - FragPos);
vec3 reflectDir = reflect(-lightDir, norm);
float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

// Attenuation
float distance = length(light.position - FragPos);
float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

// ambient  *= attenuation;  // Also remove attenuation from ambient, because if we move too far, the light in spotlight would then be darker than outside (since outside spotlight we have ambient lighting).
diffuse *= attenuation;
specular *= attenuation;
diffuse *= intensity;
specular *= intensity;
color = vec4(ambient + diffuse + specular, 1.0f);
}
else    // else, use ambient light so scene isn't completely dark outside the spotlight.
color = vec4(light.ambient * vec3(texture(material.diffuse, TexCoords)), 1.0f);

*/