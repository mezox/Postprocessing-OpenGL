#version 150 core

in vec3 position;
in vec2 UV;

out vec2 vUV;

void main() 
{
	gl_Position = vec4(position, 1.0);
	vUV = UV;
}