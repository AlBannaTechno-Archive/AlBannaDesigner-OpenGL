///this Copied from LightenObject.frag file and to tun it correctly we should copy this file to LightenObject.frag
//#ifndef __STOP_SHADER_H__
//#include"ToShaderBookHighlight.h"
//#endif
#version 330 core
out vec4 Color;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform float time;
in vec3 Normal;
uniform vec3 lightPos;
in vec3 FragPos;
uniform vec3 viewPos;

vec2 mouse;
vec2 resolution = vec2(800, 600);
//////////

#define speed 3.
#define k2PI 2.0*3.14159265359
#define kStarDensity .1
#define kMotionBlur 0.6
#define kNumAngles 200.


void main()
{

	vec3 norm = normalize(Normal);
	vec3 LightDir = normalize(lightPos - FragPos);
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
	/////////////////
	vec3 position = viewPos;
	mouse = vec2(800 * sin(time), 600 * cos(time));
	float A = atan(position.y, position.x);
	float angle0 = A / k2PI;
	float angle = fract(angle0 + .1*time);
	float rad = length(position);
	float angleFract = fract(angle*kNumAngles);
	float angleStep = floor(angle*kNumAngles);
	float angleToRandZ = 10.*fract(angleStep*fract(angleStep*.7535)*45.1);
	float angleSquareDist = fract(angleStep*fract(angleStep*.82657)*13.724);
	float t = speed * time - angleToRandZ;
	float angleDist = (angleSquareDist + 0.1);
	float adist = angleDist / rad*kStarDensity;
	float dist = abs(fract((t*.1 + adist)) - .5);
	float white1 = max(0., 1.0 - dist * 100.0 / (kMotionBlur*speed + adist));
	float white2 = max(0., (.5 - .5*cos(k2PI * angleFract))*1. / max(0.6, 2.*adist*angleDist));
	float white = white1*white2;
	vec3 color;

	color.r = .03*white1 + white*(0.3 + 5.0*angleDist);
	color.b = white*(0.1 + .5*angleToRandZ);
	color.g = 1.5*white;

	float nebD1 = 0.2;
	float nebD2 = 0.1;
	float R1 = 1.0 * rad * (1.0 + sin(0.3 + 3.0*A + 2.4 * cos(0.2 + 3.0*A)*sin(2.1 + 0.42*(nebD1 + speed*time)) + sin(2.0*6.283*position.x)));
	float R2 = 1.0 * rad * (1.0 + sin(1.1 + 4.0*A + 3.2 * cos(0.7 + 4.0*A)*sin(1.7 + 0.27*(nebD2 + speed*time)) + cos(3.0*6.283*position.y)));
	float P1 = 0.5 + .5*sin(5.7*position.x + .22*(speed*time));
	float P2 = 0.5 + .5*sin(4.44*position.y + .17*(speed*time));
	color.r += 0.2 + R1*0.2;
	color.b += 0.3*R1 + 0.8*R2 + .1*P2*R1;
	color.g += 1.1*R1*R2*P2;

	result += color;
	Color = vec4(result, 1.0f);

}
//	vec3 result = ambient * objectColor*vec3(sin(Time),cos(Time),tan(Time-cos(Time)))*Scolar;
//	float Scolar = sin(Time) - cos(Time);
