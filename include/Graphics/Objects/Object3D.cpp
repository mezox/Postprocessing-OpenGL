#include "Object3D.h"

Object3D::Object3D()
{
	m_modelMAtrix = Mat4();
	m_position = Vec3(0.0f);
	m_rotation = Vec3(0.0f);
	m_scale = Vec3(1.0f);

	m_visible = true;
	m_update = false;
}

/// <summary>
/// Sets position of the object.
/// </summary>
/// <param name="position">The position.</param>
void Object3D::SetPosition(const Vec3& position)
{
	m_position = position;
	m_update = true;
}

/// <summary>
/// Sets rotation of the object.
/// </summary>
/// <param name="rotation">The rotation.</param>
void Object3D::SetRotation(const Vec3& rotation)
{
	m_rotation = rotation;
	m_update = true;
}

/// <summary>
/// Sets scale of the object.
/// </summary>
/// <param name="scale">The scale.</param>
void Object3D::SetScale(const Vec3& scale)
{
	m_scale = scale;
	m_update = true;
}

void Object3D::UpdateMatrix()
{
	m_modelMAtrix = Mat4();
	//m_modelMAtrix = glm::rotate(m_modelMAtrix, m_rotation);
	m_modelMAtrix = glm::scale(m_modelMAtrix, m_scale);
	m_modelMAtrix = glm::translate(m_modelMAtrix, m_position);

	m_update = false;
}

/// <summary>
/// Returns model matrix.
/// </summary>
/// <returns>Matrix of the object</returns>
Mat4& Object3D::Matrix()
{
	return m_modelMAtrix;
}

/// <summary>
/// Returns position of the object.
/// </summary>
/// <returns>Position [World space]</returns>
Vec3& Object3D::Position()
{
	return m_position;
}

/// <summary>
/// Returns scale of the object.
/// </summary>
/// <returns>Scale</returns>
Vec3& Object3D::Scale()
{
	return m_scale;
}
