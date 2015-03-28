#pragma once

#include <pp_types.h>

class Object3D
{
public:
	Object3D();

	//Setters
	void SetPosition(const Vec3&);
	void SetRotation(const Vec3&);
	void SetScale(const Vec3&);
	void UpdateMatrix();

	void Rotate(const Vec3&);
	void RotateX(float);
	void RotateY(float);
	void RotateZ(float);

	void Translate(const Vec3&);
	void TranslateX(float);
	void TranslateY(float);
	void TranslateZ(float);

	void TranslateRel(float, Vec3);
	void TranslateRelX(float);
	void TranslateRelY(float);
	void TranslateRelZ(float);
	

	//Getters
	Mat4& Matrix();
	Vec3& Position();
	Vec3& Scale();

protected:
	Mat4	m_modelMAtrix;
	Vec3	m_position;
	Vec3	m_rotation;
	Vec3	m_scale;
	bool	m_visible;
	bool	m_update;
};