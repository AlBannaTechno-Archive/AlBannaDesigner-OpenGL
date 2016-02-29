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
	//ÍæáäÇ ÇáãÊÌå ÇáÚãæÏí Úáì ÇáÓØÍ Çáì ãÊÌå æÍÏÉ 
	vec3 ViewDir = normalize(viewPos-FragPos);
	//ÍÕáäÇ Úáì ãÊÌå ÇáæÍÏÉ Çááí íæÇÒí ãÊÌå ÇáÑÄíÉ 
	//æåæ ÇáãÊÌå ÇáãÊÌå ãä ÅÊÌÇå ÇáßÇãíÑÇ Çáì ÇáÓØÍ 
	//æåæ ÈÇáÊÃßíÏ íÓÇæí ÍÇÕá ØÑÍ ÇáãÊÌåíä 
	//Phase No 1: Directional Lighting
	vec3 result = CalcDirLight(dirLight,norm,ViewDir);
	//ŞãäÇ ÈÍÓÇÈ ÇáÖæÄ ÇáãÈÇÔÑ 
	//æãä Ëã äÍÊÇÌ áÍÓÇÈ ÇáÖÄ ÇáäŞØí 
	//æäãÊáß İí ÍÇáÊäÇ ÇÑÈÚÉ ÇÖæÇÁ 
	//ÍíË ßáãÇ ÍÓÈäÇ äÇÊÌ ÃÖİäÇå Úáì ÇáäÇÊÌ ÇááĞí ŞÈáå
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
	//ÃæáÇ äŞæã ÈÊÍÏíÏ ÅÊÌÇå ÇáÖæÁ ãä ÇáÓØÍ Çáì ÇáÖæÁ æáĞáß äÚßÓå 
	// Ëã äÍæáå Çáì ãÊÌå æÍÏå
	vec3 lightDir = normalize(-light.direction);
	//äŞæã ÈÍÓÇÈ ÇáÖæÁ ÇáãÔÊÊ 
	//æåæ íÓÇæí ÍÇÕá ÇáÖÑÈ ÇáŞíÇÓí áãÊÌå ÇáæÍÏå ÇáÚãæÏí Úáì ÇáÓØÍ
	//ãÚ ãÊÌå ÅÊÌÇå ÇáÖæÁ ãä ÇáÓØÍ Çáì ãÕÏÑ ÇáÖÄ æåæ íÓÇæí ÇíÖÇ ÌíÈ ÊãÇã ÇáÒÇæíÉ
	//ÈíäåãÇ áÃä ßáÇåãÇ ãÊÌå æÍÏÉ
	//Ëã äÓÊÎÏã ÏÇáÉ ÇáŞíãÉ ÇáŞÕæì áãäÚ ÇáÇáæÇä ÇáÓÇáÈÉ
	float diff = max(dot(normal,lightDir),0.0);
	//äæÌÏ ÅÊÌÇå ÅäÚßÇÓ ÇáÖæÁ ÈÅÓÊÎÏÇã ÏÇáÉ ÇáÚßÓ
	// æÇááÊí ÊÃÎĞ ÇáãÊÌå ÇáæÇÕá ãä ÇáÓØÍ Çáì ÇáÖÄ Çí ÓÇáÈ ÇáãÊÌå ãä ÇáÖÄ ááÓØÍ
	//æÇáãÏÎá ÇáËÇäí åæ ÇáãÊÌå ÇáÚãæÏí Úáì ÇáÓØÍ
	//æÊÚíÏ ÇáÏÇáÉ ÇáãÊÌå ÇááĞí íÚÈÑ Úä ÅäÚßÇÓ ÇáÖæÁ 
	vec3 reflectDir = reflect(-lightDir, normal);
	//äæÌÏ ŞíãÉ ÇáæåÌ ÇáãÊßæäÉ ãä ÇáÖÄ spec
	//ÍíË Çä ŞæÉ ÇáåÌ ÊÊæŞİ Úáì ÇáŞæÉ Çæ ÇáÇÓ ÇááĞí 
	//ÊÑİÚ áå ÇáŞíãÉ ÇáäÇÊÌÉ ãä ÇáÖÑÈ ÇáŞíÇÓí áãÊÌå ÇáäÇÙÑ ãÚ ãÊÌå 
	//ÇáÖÄ ÇáãäÚßÓ
	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
	//æÇáÇä äæÌÏ ÇáŞíã ÇáİÚáíÉ ááÃáæÇä ÈÚÏ ÊÃËÑåÇ ÈÇáÖæ
	//æĞÇáß Úä ØÑíŞ ÖÑÈ ÇáŞíã ÇáÓÇÈŞÉ ÈÇáŞíã ÇáãäÇÙÑÉ áåÇ İí ÇáÅßÓÇÆÇÊ Çæ ÇáÎÇãÇÊ
	//ÃæáÇ ÇáÖæÁ ÇáãÍíØ æäáÇÍÙ ÇääÇ ÇÓÊÎÏãäÇ ãÚå ÌÒÃ ÇáÎÇãÉ ÇáãÔÊÊ 
	// æåĞÇ áÃäå ÛÇáÈÇ ãÇ Êßæä ÇáÇáæÇä ÇáãÔÊÊÉ æÇáÃáæÇä ÇáãÍíØÉ åí äİÓÓåÇ  
	//ØÈÚÇ ÇÓÊÎÏãäÇ ÏÇáÉ ÇáÅßÓÇÁ 
	//ßãÇ äáÇÍÙ Çäå áÇÊæÌÏ ŞíãÉ ÖæÆíÉ ãÚÏáÉ ááÖæÁ ÇáãÍíØ amb
	vec3 ambient = light.ambient*vec3(texture(material.diffuse,TexCoords));
	//Ëã äŞæã ÈÍÓÇÈ ÇáÊÃËÑ ÈÇáÖÄ ÇáãÔÊÊ 
	//æíäÊÌ ãä ÖÑÈ ŞíãÉ ÇáÖÄ ÇáãÔÊÊ ÇáãÓÊŞÈáÉ ãä ÇáÈÑäÇãÌ
	//ãÚ ŞíãÉ ÇáÖÄ ÇáãÔÊÊ ÇááÊí Êã ÍÓÇÈåÇ åäÇ İí ÇáãÚÌá Ãæ ÇáÔÇÏÑ
	//æíÊã ÖÑÈ ÇáäÇÊÌ İí ÇáãÊÌå ÇáÎÇÕ ÈÇáÅßÓÇÁ æÇááĞí íÚÊãÏ İí Êáæíäå
	//Úáì ŞíãÉ  ÇáÇáæÇä ÇáãÔÊÊÉ ÇáŞÇÏãÉ ãä ÇáÈÑäÇãÌ ÇáÎÇÕ ÈÇáÎÇãÇÊ
	vec3 diffuse = light.diffuse*diff*vec3(texture(material.diffuse, TexCoords));
	//æãä Ëã äËæã ÈÍÓÇÈ Çááæä ÇáÈÑÇŞ 
	//æíäÊÌ ãä ÖÑÈ ÇáŞíã ÇáãäÇÓÈÉ áÈÚÖåÇ ßãÇ ÓÈŞ 
	//æåí Şíã ÇáÖÄ ÇáŞÇÏã ãä ÇáÈÑäÇãÌ æŞíã ÇáÖÄ ÇáãÍÓæÈÉ æŞí ÇáæÇä ÇáÇßÓÇÁ ÇáãäÇÓÈÉ
	//áåĞÇ ÇáäæÚ ãä ÇáÖÄ
	vec3 specular = light.specular*spec*vec3(texture(material.specular,TexCoords));
	//äÑÌÚ ãÌãæÚ Şíã ÇáÇáæÇä ÇáËáÇËÉ 
	return (ambient+diffuse+specular);
}
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	
	vec3 lightDir = normalize(light.position-fragPos);
	//ÃæáÇ äæÌÏ ÅÊÌÇå ÇáÖÄ İí Ôßá ãÊÌå æÍÏÉ 
	//æÅÊÌÇåÇ ÇáÖÄ ÇáãŞÕæÏ åæ ÇÊÌÇå ÇáÌÒÃ ÇáÓÇŞØ ãä ÇáÖÄ Úáì ÇáÓØÍ
	//æåæ íÓÇæí ÇáİÑŞ Èíä ãÊÌå ÇáÖÄ æãÊÌå ÇáÓØÍ 
	//Çí ÇáãÊÌå ÇáãæÇÒí ááÓØÍ
	//Diffuse Shading
	float diff = max(dot(normal, lightDir), 0.0);
	//ÇæÌÏäÇ ŞíãÉ ÇáÖÁ ÇáãÍíØ ÇáÓÇŞØ Úáì ÇáÓØÍ ÇáãÖÇÁ
	//æåæíÓÇæí ÍÇÕá ÇáÖÑÈ ÇáŞíÇÓí ááãÊÌå ÇáÚãæÏí Úáì ÇáÓØÍ normal
	//ãÚ ÇáãÊÌå ÇááĞí íÚÈÑ Úä ÇÊÌÇå ÇáÖÄ ÇáÍŞíŞí ÇáÓÇŞØ Úáì ÇáÓØÍ
	//æØÈÚÇ ÏÇáÉ ÇáŞíãÉ ÇáŞÕæì áãäÚ ÇáÇáæÇä ÇáÓÇáÈÉ
	//æááÊäæíå İäÍä áã äŞã ÈÊÍæíá ÇáäÇÊÌ Çáì ãÊÌå æÍÏÉ áÇä åĞÇ ÖÑÈ ŞíÇÓí áÇíäÊÌ Úäå ãÊÌå
	//ßãÇ áã äÍæá ÇáãÏÎáÇÊ ßãÊÌåÇÊ æÍÏÉ áÇä ÍÇÕá ÇáÖÑÈ áÇíÎÊáİ 
	//ÅáÇ ÅĞÇ ßÇä ÇÍÏåãÇ ãÊÌå æÍÏå æÇáÇÎÑ áÇ 
	//Specular Shading
	vec3 reflectDir = reflect(-lightDir, normal);
	//Ãæá ÎØæÉ İí ÍÓÇÈ ÇáæåÌ ÇáäÇÔÆ Úä ÇáÖÄ åí ÍÓÇÈ ÅÊÌÇå ÇáÖÄ ÇáãäÚßÓ
	//æĞÇáß íßæä Úä ØÑíŞ ÇÓÊÎÏÇã ÏÇáÉ ÇáÚßÓ æÇááÊí ÊÃÎĞ ÅÊÌÇå ÇáÖÄ ÇáİÚáí ÇáÓÇŞØ
	//Úáì ÇáÓØÍ æáÇßäå ÊÃÎĞå ãä ÇáÓØÍ Çáì ÇáÖÄ æÈÇáÊÇáí ÓäÚßÓå ÈÇáÇÔÇÑÉ ÇáÓÇáÈÉ
	//æÇáãÏÎá ÇáËÇäí åæÇ ÇáãÊÌå ÇáÚãæÏí Úáì ÇáÓØÍ 
	//æáÇääÓÇ Çä ßáÇåãÇ ãÊÌå æÍÏÉ
	//æãÚ ĞÇáß İÇáäÇÊÌ áíÓ ãÊÌå æÍÏÉ
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	//ŞãäÇ ÈÍÓÇÈ ŞíãÉ ÇáæåÌ æĞÇáß Úä ØÑíŞ ÇáÖÑÈ ÇáŞíÇÓí áãÊÌå ÇáÑÄíÉ 
	//ãÚ ãÊÌå ÇáÅäÚßÇÓ 
	//æØÈÚÇ äÑİÚ ÇáäÇÊÌ áÃÓ Ãæ ŞæÉ ÊÓÇæí ŞíãÉ ÇááãÚÇä Çæ ÇáÈÑíŞ ÇáãæÌæÏ İí ÎæÇÕ ÇáãÇÏÉ
	//Attenuation
	float distance = length(light.position - fragPos);
	//Çæá ÎØæÉ İí ÍÓÇÈ ÇáÊæåíä åí Çä äŞæã ÈÍÓÇÈ Øæá ÇáÎØ ÇáæÇÕá 
	//ãä ãæŞÚ ãÑßÒ ÇáÖÄ ÇáÍÇáí Çáì ÇáäŞØÉ ÇááÊí ÓÊÊã ÅÖÇÆÊåÇ 
	//æĞÇáß Úä ØÑíŞ ÇáÏÇáÉ ÇáØæáíÉ ÇááÊí ÊŞæã ÈÍÓÇÈ Øæá ÇáãÊÌå 
	//æÇáØÑíŞÉ Óåáå æåí ÊÓÇæí ÇáÌĞÑ ÇáÊÑÈíÚí áãÌãæÚ ãÑÈÚÇÊ íã ÇáãÍÇæÑ
	float attenuation = 1.0f/(light.constant+light.linear+distance+light.quadratic*(distance*distance));
	//ÇáÎØæÉ ÇáËÇäíÉ æåí ÍÓÇÈ ŞíãÉ ÇáÊæåíä æĞÇáß Úä ØÑíŞ ãÚÇÏáÉ ÚÇãæ æÖÚåÇ ÚáãÇÁ ÇáÈÕÑíÇÊ
	//æåí ßãÇ åí ãÚØÇÉ
	//Combine Results  ÇáÇä äŞæã ÈÖã ÇáäæÇÊÌ Çáì ÈÚÖåÇ 
	vec3 ambient = light.ambient*vec3(texture(material.diffuse, TexCoords));
	//ŞãäÇ ÈÍÓÇÈ ÇáÊÃËíÑ ÇáÍÇÏË Úáì ÇáÇáæÇä ÌÑÇÁ ÓŞæØ ÇáÖÄ ÇáãÍíØ ÚáíåÇ 
	//æĞÇáß ÈÖÑÈ ßá ÌÒÃ ãä ÇáäæÇÊÌ ÇáÓÇÈŞÉ ááÖÄ İí ÇáÌÒÃ ÇáãäÇÙÑ áå İí ÇáŞíã
	//ÇáãÚØÇÉ ãä ÇáÈÑäÇãÌ ÇáÑÃíÓí ááÖÄ æßĞÇáß ãÚ ÇáŞíã ÇáÎÇÕÉ ÈÇáÇßÓÇÁ æÇáÎÇãÇÊ
	vec3 diffuse = light.diffuse*diff*vec3(texture(material.diffuse,TexCoords));
	vec3 specular = light.specular*spec*vec3(texture(material.specular, TexCoords));
	//æãä Ëã ÓäŞæã ÇáÇä ÈÍÓÓÇÈ ÇáÊÃËíÑ ÇáÍÇÏË İí ßá ŞíãÉ ÈÓÈÈ ÇáÊæåíä 
	//ÍíË ÊÖÑÈ ßá ŞíãÉ İí ŞíãÉ ÇáÊæåíä
	//áĞÇáß äŞÓã æÇÍÏ İí ŞÇäæä ÇáÊæåíä Úáì ÌãíÚ ÇáŞíã 
	//æĞÇáß ÍÊì áÇäÖØÑ ÈÚÏ ĞÇáß ááŞÓãÉ æÅäãÇ äÖÑÈ ãÈÇÔÑÉ 
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	//æäÑÌÚ ÇáãÊÌå ÇááĞí íÍæí ãÌãæÚ åĞå ÇáŞíã ÇáËáÇË
	return(ambient+diffuse+specular);
}










