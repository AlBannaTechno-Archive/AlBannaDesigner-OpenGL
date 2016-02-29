#version 330 core
struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};
in vec2 TexCoords;

struct Light {
	vec3 position;
	vec3 direction;
	float cutOff;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

uniform Light light;
uniform Material material;
out vec4 color;
in vec3 Normal;
in vec3 FragPos;
//uniform vec3 objectColor;//befcome material
//uniform vec3 lightColor; //become Light
uniform vec3 viewPos;


void main()
{
	vec3 lightDir = normalize(light.position - FragPos);
    
    // Check if lighting is inside the spotlight cone
    float theta = dot(lightDir, normalize(-light.direction)); 
    
    if(theta > light.cutOff) // Remember that we're working with angles as cosines instead of degrees so a '>' is used.
    {    


	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	 float distance    = length(light.position - FragPos);

	float attenuation = 1.0f / (light.constant + light.linear * distance +
	light.quadratic * (distance * distance));

// Diffuse
	vec3 norm = normalize(Normal);
	//vec3 lightDir = normalize(-light.direction);1
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,TexCoords));
// Specular
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	///vec3 specular = light.specular * (spec * material.specular);
	///‰·«ÕŸ «‰ «·”ÿ— «·”«»ﬁ «” »œ·‰«Â »«·”ÿ— «· «·Ì ⁄‰œ„« «” Œœ„‰« «·Œ—«∆ÿ ÕÌÀ «‰ Œ—«∆ÿ «·÷Ê¡ „«ÂÌ ≈·« ≈ﬂ”«∆« 
	vec3 specular = light.specular * spec * vec3(texture(material.specular,TexCoords));
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);
	}
	else
	        color = vec4(light.ambient * vec3(texture(material.diffuse, TexCoords)), 1.0f);
}