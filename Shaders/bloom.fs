#version 150 core

in vec2 vUV;

uniform sampler2D tex;

out vec4 fColor;

float xStep = 1.0f / 1280.0f;
float yStep = 1.0f / 720.0f;

void main() 
{
	vec4 sum = vec4(0);
	for(int y = -2; y <= 2; y++)
	{
		for(int x = -2; x <= 2; x++)
		{
		    vec2 offset = vec2(x * xStep, y * yStep);
			sum += texture2D(tex, vUV + offset);
        }    
    }

	vec4 original = texture2D(tex, vUV);
	fColor = vec4(sum.xyz / 25.0f + original.xyz, 1.0);
}