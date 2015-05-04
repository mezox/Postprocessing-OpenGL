#version 150 core

in vec2 vUV;

uniform sampler2D tex;
uniform float time;

out vec4 fColor;


void main() 
{
	vec2 offset = vec2(0.005f, 0);
	vec4 color1 = texture2D(tex, vUV + offset);
	vec4 color2 = texture2D(tex, vUV - offset);
	vec4 color3 = texture2D(tex, vUV);
	fColor = vec4(color1.r, color3.g, color2.b, color3.a);
}