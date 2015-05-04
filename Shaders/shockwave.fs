#version 150 core

in vec2 vUV;

uniform sampler2D tex;
uniform float time;

out vec4 fColor;


void main() 
{
	float distanceFromCenter = distance(vUV, vec2(0.5f, 0.5f));
	vec4 resultColor = vec4(0,0,0,0);
	float shockwaveWidth = 0.2f;
	float shockwaveRadius = mod(time, 1.0f);
	if (shockwaveRadius > 0 && shockwaveRadius < 1.5f &&
		distanceFromCenter >= shockwaveRadius - shockwaveWidth &&
		distanceFromCenter <= shockwaveRadius + shockwaveWidth)
	{
		float pointInCircle = distanceFromCenter - shockwaveRadius;
		pointInCircle /= shockwaveWidth;//3.333f;
		float displacementMagnitude = 1.0f - (pointInCircle * pointInCircle);
		vec2 displacement = -normalize(vUV - vec2(0.5f, 0.5f));
		displacement = displacement * displacementMagnitude * 0.1f;
		resultColor = texture2D(tex, vUV + displacement);
	}
	else
	{
		resultColor = texture2D(tex, vUV);
	}
	
	fColor = resultColor;
}