//íÓÊÎÏã ãÚ ÇáÚäÇÕÑ ÇáãÊÃËÑÉ ÈÇáÖæÁ

#version 330 core
out vec4 color;
in vec3 Normal;
in vec3 FragPos;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightpos;

void main()
{
	float ambientStrength=0.1f;//first we define ratio to suppose that ther any where would be color
	vec3 ambient=ambientStrength*lightColor;//second we calculate the new light color
	vec3 norm=normalize(Normal);
	vec3 ligthDir=normalize(lightpos-FragPos);

	float diff=max(dot(norm,lightColor),0.0f);//if the angle 
	//between norm and lightColor vectors is >90 it`s will return negative value
	//and this will case a negative colors ,but we needn't this
	//so we will use max function which return the largest value of two parametres
	//and we put the second value as 0.0f
	vec3 diffues=diff*lightColor;
	vec3 result=(ambient+diffues)*objectColor;//third we calculate the new color of our boject
    color = vec4(result, 1.0f);//fourth we applay all this

}