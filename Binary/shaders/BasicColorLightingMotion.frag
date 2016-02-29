//íÓÊÎÏã ãÚ ÇáÚäÇÕÑ ÇáãÊÃËÑÉ ÈÇáÖæÁ

#version 330 core
out vec4 color;
in vec4 Normal;
in vec4 FragPos;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightpos;

void main()
{
	vec4 objectColor4=vec4(objectColor,1.0f);
	vec4 lightColor4=vec4(lightColor,1.0f);
	vec4 lightpos4=vec4(lightpos,1.0f);

	float ambientStrength=0.1f;//first we define ratio to suppose that ther any where would be color
	vec4 ambient=ambientStrength*lightColor4;//second we calculate the new light color
	vec4 norm=normalize(Normal);
	vec4 ligthDir=normalize(lightpos4-FragPos);

	float diff=max(dot(norm,lightColor4),0.0f);//if the angle 
	//between norm and lightColor vectors is >90 it`s will return negative value
	//and this will case a negative colors ,but we needn't this
	//so we will use max function which return the largest value of two parametres
	//and we put the second value as 0.0f
	vec4 diffues=diff*lightColor;
	vec4 result=(ambient+diffues)*objectColor;//third we calculate the new color of our boject
    color =result;//fourth we applay all this
}