#version 150 core

in vec2 vUV;

uniform sampler2D tex;

out vec4 fColor;


void main() 
{
	fColor = texture2D(tex, vUV);
	float gray = 0.2126 * fColor.r + 0.7152 * fColor.g + 0.0722 * fColor.b;
	fColor = vec4(gray, gray, gray, fColor.a);
}