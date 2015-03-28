#include <Geometry.h>
#include <GL\glew.h>

const uint32 Geometry::TRIANGLES = GL_TRIANGLES;
const uint32 Geometry::QUADS = GL_QUADS;
const uint32 Geometry::POINTS = GL_POINTS;

Geometry::Geometry(float * vertices, int * indices, int verticesCnt, int indicesCnt)
{
	m_vertices = new float[verticesCnt];
	m_indices = new int[indicesCnt];

	memcpy(m_vertices, vertices, verticesCnt * sizeof(float));
	memcpy(m_indices, indices, indicesCnt * sizeof(float));

	m_verticesCnt = verticesCnt;
	m_indicesCnt = indicesCnt;

	m_hasNormals = false;
	m_hasTexCoords = false;

	m_primitive = Geometry::TRIANGLES;
}

/// <summary>
/// Returns vertices that define shape of the object.
/// </summary>
/// <returns>Vertices</returns>
float * Geometry::Vertices()
{
	return m_vertices;
}

/// <summary>
/// Returns normals in vertices of the object.
/// </summary>
/// <returns>Normals</returns>
float * Geometry::Normals()
{
	return m_normals;
}

/// <summary>
/// Returns texture coords.
/// </summary>
/// <returns>Texture coords</returns>
float * Geometry::TexCoords()
{
	return m_texcoords;
}

/// <summary>
/// Returns indices.
/// </summary>
/// <returns>Indices</returns>
int32 * Geometry::Indices()
{
	return m_indices;
}

/// <summary>
/// Number of verticeses in vertices array.
/// </summary>
/// <returns>vertices count</returns>
uint32 Geometry::VerticesCnt()
{
	return m_verticesCnt;
}

/// <summary>
/// Number of indices in indices array.
/// </summary>
/// <returns>Indices count</returns>
uint32 Geometry::IndicesCnt()
{
	return m_indicesCnt;
}

/// <summary>
/// Number of texture coords in texture coords array.
/// </summary>
/// <returns>Texture coords count</returns>
uint32 Geometry::TexCoordsCnt()
{
	return m_texCoordsCnt;
}

/// <summary>
/// Returns primitive type.
/// </summary>
/// <returns>Primitives type of the object</returns>
uint32 Geometry::Primitive()
{
	return m_primitive;
}

/// <summary>
/// Assigns tex coords to the object.
/// </summary>
/// <param name="tc">Texture coords array.</param>
void Geometry::SetTexCoords(float * tc)
{
	m_texCoordsCnt = m_verticesCnt / 3 * 2;
	m_texcoords = new float[m_texCoordsCnt];
	memcpy(m_texcoords, tc, m_texCoordsCnt*sizeof(float));
}

/// <summary>
/// Assigns normals to the object.
/// </summary>
/// <param name="n">Normals array.</param>
void Geometry::SetNormals(float * n)
{
	m_normals = new float[m_verticesCnt];
	memcpy(m_normals, n, m_verticesCnt * sizeof(float));
	m_hasNormals = true;
}

/// <summary>
/// Sets the primitive tive.
/// </summary>
/// <param name="prim">Primitive type [GL_TRIANGLES | GL_QUADS | GL_POINTS].</param>
void Geometry::SetPrimitive(uint32 prim)
{
	m_primitive = prim;
}

/// <summary>
/// Determines whether mesh has normals.
/// </summary>
/// <returns></returns>
bool Geometry::HasNormals()
{
	return m_hasNormals;
}

/// <summary>
/// Determines whether mesh has tex coords.
/// </summary>
/// <returns></returns>
bool Geometry::HasTexCoords()
{
	return m_hasTexCoords;
}
