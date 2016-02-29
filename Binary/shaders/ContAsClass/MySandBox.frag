//We Need Now To use Old Open GL
/*
‰Õ «Ã ·«” Œœ« «Ê»‰ ÃÌ «· «·ﬁœÌ„ Õ Ï «·«‰ ⁄·Ï «·«ﬁ·
··‰ÃÕ ›Ì  ÿ»Ìﬁ «·”«‰œ »Êﬂ” 
«Ì ·‰ÿ»ﬁ Ã„Ì⁄ «„À· Â 
Êﬂ· ‘∆ Â‰«  Ì⁄„· »«· „«„ Ê«·ﬂ„«· 
Ê«·Õ„œ Ê«·›÷· ··Â ÊÕœÂ
*/
#ifdef GL_ES
precision highp float;
#endif

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main(void) {

//	vec4 mk = vec4(sin(5.0), 0.4, 0.6, 0.9);
//	gl_FragColor = vec4(sin(gl_FragCoord.x*gl_FragCoord.y*gl_FragCoord.x), cos(time)*cos(gl_FragCoord.y), tan(time) - 0.2, 0.8);
	float t = time*time*2.;
	vec2 uv = gl_FragCoord.xy / t;
	vec2 pos = vec2((resolution.x - t*1.45) / t - 500. / t, (resolution.y / t)*.5);
	vec2 p0 = pos - uv;

	vec2 p = vec2(0.);

	float c = 0.;

	for (int i = 0; i < 256; i++)
	{
		if (length(p*sin(time)) > 4.)
			break;
		float _x = p.x*p.x - p.y*p.y + p0.x;
		p.y = 2. * p.x * p.y + p0.y;
		p.x = _x;
		c += 1. / 160.;
	}

	gl_FragColor = vec4(fract(c), sin(atan(p.y, p.x)*c)*sin(time)*0., c*(2. - c), 1.);
	
}

/*

//#include<ToShaderBookHighlight.h>
#version 330 core
out vec4 color;
in vec3 TransColor;//=gl_fragCord
uniform float time;
uniform vec2 mouse;
uniform vec2 screen;
uniform vec2 resolution;
bool po = false;
void main()
{
//	color = vec4(sin(mouse.x), sin(mouse.y), sin(TransColor.x / TransColor.y), 0.6);
	color = vec4(sin(TransColor.x / TransColor.y), sin(TransColor.x / TransColor.y), sin(TransColor.x / TransColor.y), 0.6);
	//	color = vec4(sin(TransColor.x), sin(TransColor.y), cos(resolution.x / resolution.y), 0.8);
}
*/


/*

vec3 p = vec3((TransColor.xy) / (resolution.y), mouse.x);
for (int i = 0; i < 100; i++){
p.xzy = vec3(1.3, 0.999, 0.7)*(abs((abs(p) / dot(p, p) - vec3(1.0, 1.0, mouse.y*0.5))));
}
gl_FragColor.rgb = p; color.a = 5.0;
*/

/*
Very good 

float t = time*time*2.;
vec2 uv = TransColor.xy / t;
vec2 pos = vec2((resolution.x - t*1.45) / t - 500. / t, (resolution.y / t)*.5);
vec2 p0 = pos - uv;

vec2 p = vec2(0.);

float c = 0.;

for (int i = 0; i < 256; i++)
{
if (length(p*sin(time)) > 4.)
break;
float _x = p.x*p.x - p.y*p.y + p0.x;
p.y = 2. * p.x * p.y + p0.y;
p.x = _x;
c += 1. / 256.;
}

color = vec4(fract(c), sin(atan(p.y, p.x)*c)*sin(time)*0., c*(2. - c), 1.);


*/


/*
This The Best

float t = time*time*2.;
vec2 uv = TransColor.xy / t;
vec2 pos = vec2((800 - t*1.45) / t - 50. / t, (600 / t)*.5);
vec2 p0 = pos - uv;

vec2 p = vec2(0.);

float c = 0.;

for (int i = 0; i < 256; i++)
{
if (length(p*sin(time)) > 4.)
break;
float _x = p.x*p.x - p.y*p.y + p0.x;
p.y = 2. * p.x * p.y + p0.y;
p.x = _x;
c += 1. / 2.;
}

color = vec4(fract(c), sin(atan(p.y, p.x)*c)*sin(time)*0., c*(2. - c), 1.);

*/

/*
White And Black 

//	color = vec4(sin(TransColor.x + mouse.x), sin(TransColor.y + mouse.y), sin(TransColor.z), 1.0f);
/*

color = vec4(
sin(
sin(
time)*length(
TransColor.xy - ((mouse.x/mouse.y) / 2.0)
)
+
time*20.)
);
*/
