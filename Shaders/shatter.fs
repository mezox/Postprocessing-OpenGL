#version 150 core

in vec2 vUV;

uniform sampler2D tex;
uniform float time;

out vec4 fColor;


void main() 
{
	float t = mod(time, 1.0f);
	t = t < 0.1f ? t / 0.1f : 0;
	vec2 offset = vec2(0.005f * t, 0);
	vec4 color1 = texture2D(tex, vUV + offset);
	vec4 color2 = texture2D(tex, vUV - offset);
	if(mod(vUV.y, 0.05f) < 0.025f)
	{
	    fColor = color1;
    } else
	{
	    fColor = color2;
    }
}