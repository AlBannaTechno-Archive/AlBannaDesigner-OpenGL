#version  330
//We Need Now To use Old Open GL
/*
äÍÊÇÌ áÇÓÊÎÏÇ ÇæÈä Ìí Çá ÇáÞÏíã ÍÊì ÇáÇä Úáì ÇáÇÞá
ááäÌÍ Ýí ÊØÈíÞ ÇáÓÇäÏ ÈæßÓ 
Çí áäØÈÞ ÌãíÚ ÇãËáÊå 
æßá ÔÆ åäÇ  íÚãá ÈÇáÊãÇã æÇáßãÇá 
æÇáÍãÏ æÇáÝÖá ááå æÍÏå
*/
#ifdef GL_ES
precision highp float;
#endif


uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main(void) {

	float xst=gl_FragCoord.x*sqrt(time/2.0);
	float yst=gl_FragCoord.y*sqrt(time/2.0);
	float zst=gl_FragCoord.z*sqrt(time/2.0);
	float a=1.0;//*sin(time);
	float b=2.0;//*sin(time);
	float c=3.0;//*sin(time);
	float z=(((xst*xst)/(a*a))-((yst*yst)/(b*b)))*c;
	float x=((zst/c)+((yst*yst)/(b*b))/(a*a));
	x=sqrt(x);
	float y=-((zst/c)-((xst*xst)/(a*a))/(b*b));
	y=sqrt(y);
	gl_FragColor = vec4(cos(x*time)/sinh(y*time),y,cos(z),0.8);
}
