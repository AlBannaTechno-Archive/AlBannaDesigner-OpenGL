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

//	vec4 mk = vec4(sin(5.0), 0.4, 0.4, 0.9);
//	gl_FragColor = vec4(sin(gl_FragCoord.x*gl_FragCoord.y*gl_FragCoord.x), cos(time)*cos(gl_FragCoord.y), tan(time) - 0.2, 0.8);
	float t = time*time*5.;
	vec2 uv = gl_FragCoord.xy / t;
	vec2 pos = vec2((resolution.x - t*1.45) / t - 400. / t, (resolution.y / t)*.4);
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
		c += 1. / mouse.x;
	}

	gl_FragColor = vec4(fract(c), sin(atan(p.y-5.0, p.x)*c)*sin(time)*0., c*(2. - c), 1.);
}


