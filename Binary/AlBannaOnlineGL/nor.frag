#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable


uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main()
{
	gl_FragColor=vec4(sin(time*gl_FragCoord.y),sin(gl_FragCoord.x*sin(time)),sin(gl_FragCoord.y),0.5);
}