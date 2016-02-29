#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main( void ) {
	
	float t = time*time*2.;
	vec2 uv = gl_FragCoord.xy / t;
	vec2 pos = vec2((resolution.x-t*1.45)/t-500./t, (resolution.y/t)*.5);
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
		c+= 1./(mouse.x-mouse.y);	
	}

	gl_FragColor = vec4(fract(c), sin(atan(p.y,p.x)*c)*sin(time)*0., c*(2.-c), 1.);
}