#pragma once

#include <Object3D.h>

class Mesh : public Object3D
{
public:
	Mesh();
	~Mesh();

	void InitVBO();
	void DrawVBO();
	void DebugDrawVBO();
};