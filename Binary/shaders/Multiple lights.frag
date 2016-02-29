//#include<ToShaderBookHighlight.h>
#version 330 core
struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};
struct DirLight
{
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
struct PointLight{
	vec3 position;

	float constant;
	float linear;
	float quadratic;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
#define NR_POINT_LIGHTS 4
in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform Material material;


vec3 CalcDirLight(DirLight light,vec3 normal,vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
void main()
{
	//Properties
	vec3 norm = normalize(Normal);
	//����� ������ ������� ��� ����� ��� ���� ���� 
	vec3 ViewDir = normalize(viewPos-FragPos);
	//����� ��� ���� ������ ���� ����� ���� ������ 
	//��� ������ ������ �� ����� �������� ��� ����� 
	//��� �������� ����� ���� ��� �������� 
	//Phase No 1: Directional Lighting
	vec3 result = CalcDirLight(dirLight,norm,ViewDir);
	//���� ����� ����� ������� 
	//��� �� ����� ����� ���� ������ 
	//������ �� ������ ����� ����� 
	//��� ���� ����� ���� ������ ��� ������ ����� ����
	//Phase 2:point light
	for (int i = 0; i < NR_POINT_LIGHTS; i++)
	{
		result += CalcPointLight(pointLights[i],norm,FragPos,ViewDir);
	}
	//phase 3: Spot Light
	//result+=CalcSpotLight(spotLight,norm,FragPos,viewDir);
	
	color = vec4(result,1.0);
}
vec3 CalcDirLight(DirLight light,vec3 normal,vec3 viewDir)
{
	//���� ���� ������ ����� ����� �� ����� ��� ����� ����� ����� 
	// �� ����� ��� ���� ����
	vec3 lightDir = normalize(-light.direction);
	//���� ����� ����� ������ 
	//��� ����� ���� ����� ������� ����� ������ ������� ��� �����
	//�� ���� ����� ����� �� ����� ��� ���� ���� ��� ����� ���� ��� ���� �������
	//������ ��� ������ ���� ����
	//�� ������ ���� ������ ������ ���� ������� �������
	float diff = max(dot(normal,lightDir),0.0);
	//���� ����� ������ ����� �������� ���� �����
	// ������ ���� ������ ������ �� ����� ��� ���� �� ���� ������ �� ���� �����
	//������� ������ �� ������ ������� ��� �����
	//����� ������ ������ ����� ���� �� ������ ����� 
	vec3 reflectDir = reflect(-lightDir, normal);
	//���� ���� ����� �������� �� ���� spec
	//��� �� ��� ���� ����� ��� ����� �� ���� ����� 
	//���� �� ������ ������� �� ����� ������� ����� ������ �� ���� 
	//���� �������
	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
	//����� ���� ����� ������� ������� ��� ������ �����
	//����� �� ���� ��� ����� ������� ������ �������� ��� �� ��������� �� �������
	//���� ����� ������ ������ ���� �������� ��� ��� ������ ������ 
	// ���� ���� ����� �� ���� ������� ������� �������� ������� �� ������  
	//���� �������� ���� ������� 
	//��� ����� ��� ������ ���� ����� ����� ����� ������ amb
	vec3 ambient = light.ambient*vec3(texture(material.diffuse,TexCoords));
	//�� ���� ����� ������ ����� ������ 
	//����� �� ��� ���� ���� ������ ��������� �� ��������
	//�� ���� ���� ������ ����� �� ������ ��� �� ������ �� ������
	//���� ��� ������ �� ������ ����� �������� ������ ����� �� ������
	//��� ����  ������� ������� ������� �� �������� ����� ��������
	vec3 diffuse = light.diffuse*diff*vec3(texture(material.diffuse, TexCoords));
	//��� �� ���� ����� ����� ������ 
	//����� �� ��� ����� �������� ������ ��� ��� 
	//��� ��� ���� ������ �� �������� ���� ���� �������� ��� ����� ������� ��������
	//���� ����� �� ����
	vec3 specular = light.specular*spec*vec3(texture(material.specular,TexCoords));
	//���� ����� ��� ������� ������� 
	return (ambient+diffuse+specular);
}
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	
	vec3 lightDir = normalize(light.position-fragPos);
	//���� ���� ����� ���� �� ��� ���� ���� 
	//������� ���� ������� �� ����� ����� ������ �� ���� ��� �����
	//��� ����� ����� ��� ���� ���� ����� ����� 
	//�� ������ ������� �����
	//Diffuse Shading
	float diff = max(dot(normal, lightDir), 0.0);
	//������ ���� ���� ������ ������ ��� ����� ������
	//�������� ���� ����� ������� ������ ������� ��� ����� normal
	//�� ������ ����� ���� �� ����� ���� ������� ������ ��� �����
	//����� ���� ������ ������ ���� ������� �������
	//�������� ���� �� ��� ������ ������ ��� ���� ���� ��� ��� ��� ����� ������ ��� ����
	//��� �� ���� �������� ������� ���� ��� ���� ����� ������� 
	//��� ��� ��� ������ ���� ���� ������ �� 
	//Specular Shading
	vec3 reflectDir = reflect(-lightDir, normal);
	//��� ���� �� ���� ����� ������ �� ���� �� ���� ����� ���� �������
	//����� ���� �� ���� ������� ���� ����� ������ ���� ����� ���� ������ ������
	//��� ����� ������ ����� �� ����� ��� ���� �������� ������ �������� �������
	//������� ������ ��� ������ ������� ��� ����� 
	//������� �� ������ ���� ����
	//��� ���� ������� ��� ���� ����
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	//���� ����� ���� ����� ����� �� ���� ����� ������� ����� ������ 
	//�� ���� �������� 
	//����� ���� ������ ��� �� ��� ����� ���� ������� �� ������ ������� �� ���� ������
	//Attenuation
	float distance = length(light.position - fragPos);
	//��� ���� �� ���� ������� �� �� ���� ����� ��� ���� ������ 
	//�� ���� ���� ���� ������ ��� ������ ����� ���� ������� 
	//����� �� ���� ������ ������� ����� ���� ����� ��� ������ 
	//�������� ���� ��� ����� ����� �������� ������ ������ �� �������
	float attenuation = 1.0f/(light.constant+light.linear+distance+light.quadratic*(distance*distance));
	//������ ������� ��� ���� ���� ������� ����� �� ���� ������ ���� ����� ����� ��������
	//��� ��� �� �����
	//Combine Results  ���� ���� ��� ������� ��� ����� 
	vec3 ambient = light.ambient*vec3(texture(material.diffuse, TexCoords));
	//���� ����� ������� ������ ��� ������� ���� ���� ���� ������ ����� 
	//����� ���� �� ��� �� ������� ������� ���� �� ����� ������� �� �� �����
	//������� �� �������� ������� ���� ������ �� ����� ������ �������� ��������
	vec3 diffuse = light.diffuse*diff*vec3(texture(material.diffuse,TexCoords));
	vec3 specular = light.specular*spec*vec3(texture(material.specular, TexCoords));
	//��� �� ����� ���� ������ ������� ������ �� �� ���� ���� ������� 
	//��� ���� �� ���� �� ���� �������
	//����� ���� ���� �� ����� ������� ��� ���� ����� 
	//����� ��� ������ ��� ���� ������ ����� ���� ������ 
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	//����� ������ ����� ���� ����� ��� ����� ������
	return(ambient+diffuse+specular);
}










