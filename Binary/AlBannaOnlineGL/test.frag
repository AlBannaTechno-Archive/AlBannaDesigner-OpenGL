#ifdef GL_ES
precision highp float;
#endif

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;
//x^2+Y^2=R
void main(void) {
	vec2 ui=gl_FragCoord.xy;
	float R=1.2;
	float y=sqrt(R-(ui.x*ui.x));
	gl_FragColor=vec4(sin(time),0.4,0.2,0.1);
	gl_FragColor=vec4(0.5);	

}



