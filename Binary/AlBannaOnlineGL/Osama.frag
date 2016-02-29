#version  330

#ifdef GL_ES
precision highp float;
#endif


uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main(void) {


	gl_FragColor = vec4(sin(mouse.y),cos(time),sin(mouse.x),1.0);
}
