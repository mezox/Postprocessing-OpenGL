#version 150 core

in vec2 vUV;

uniform sampler2D tex;
uniform float time;

out vec4 fColor;


void main() 
{
	vec4 color = texture2D(tex, vUV);
    color.r = (color.r * 0.393) + (color.g * 0.769) + (color.b * 0.189);
    color.g = (color.r * 0.349) + (color.g * 0.686) + (color.b * 0.168);    
    color.b = (color.r * 0.272) + (color.g * 0.534) + (color.b * 0.131);
	fColor = color;
}