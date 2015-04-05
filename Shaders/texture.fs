#version 150 core

in vec2 vUV;

uniform sampler2D tex;

out vec4 fColor;

void main() 
{
	fColor = texture2D(tex, vUV);
}