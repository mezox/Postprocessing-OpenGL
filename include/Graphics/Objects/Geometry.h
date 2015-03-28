#pragma once

#include <pp_types.h>

class Geometry
{
public:
	static const uint32 TRIANGLES;
	static const uint32 QUADS;
	static const uint32 POINTS;

	Geometry(float* vertices, int* indices, int verticesCnt, int indicesCnt);

	float* Vertices();
	float* Normals();
	float* TexCoords();
	int32* Indices();

	uint32 VerticesCnt();
	uint32 IndicesCnt();
	uint32 TexCoordsCnt();
	uint32 Primitive();

	void SetTexCoords(float* tc);
	void SetNormals(float* n);
	void SetPrimitive(uint32 prim);

	bool HasNormals();
	bool HasTexCoords();
	
private:
	float* m_vertices;
	float* m_normals;
	float* m_texcoords;
	int32* m_indices;

	uint32 m_primitive;

	uint32 m_verticesCnt;
	uint32 m_indicesCnt;
	uint32 m_texCoordsCnt;

	bool m_hasNormals;
	bool m_hasTexCoords;
	
};