#version 330 core
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

//////////me
in vec3 ourColor;
in vec2 TexCoord;
out vec4 colorUseAnyName;
uniform sampler2D shaderUseAnyname;
uniform sampler2D secondshader;
////



void main(void) {
	vec2 pos = ((gl_FragCoord.xy) / resolution.xy *time / 300.0);
	float three = 1.0 - ((pos.x + pos.y) / 2.0);
	vec3 color = vec3(three, pos.x, pos.y);
	vec3 color2 = color;

	pos = gl_FragCoord.xy*time / 10.0*pos.x / (resolution.xy * 0.6 - 10.0) / 6.0;
	color *= abs(5.0 / (sin(pos.y + sin(pos.x + time)*mouse.x * 0.1*time / 300.0) * 10.0));
	color2 *= abs(0.2 / (sin(pos.y + cos(pos.x + time) * 0.3*time / 100.0) * 10.0));
	color += color2;
	color /= 2.0;
	colorUseAnyName = vec4(color, 1.0);
	colorUseAnyName += mix(texture(shaderUseAnyname, TexCoord), texture(secondshader, 1.0f - TexCoord), 0.79);
//	gl_FragColor = vec4(color, 1.0);
//	colorUseAnyName = mix(texture(shaderUseAnyname, TexCoord), texture(secondshader, 1.0f - TexCoord), 0.79);
}