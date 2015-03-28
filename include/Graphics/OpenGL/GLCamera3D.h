#pragma once

#include <pp_types.h>

namespace CAMERA
{
	enum class MOVE
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		Down
	};
}

class GLCamera3D
{
public:
	GLCamera3D();


	//Getters
	const Mat4&		Projection() const;
	const Mat4&		View() const;
	const Vec3&		Position() const;
	const Vec3&		Direction() const;
	const Vec3&		Up() const;
	const Vec3&		Right() const;
	const float&	FieldofView() const;
	const float&	Aspect() const;
	const float&	Near() const;
	const float&	Far() const;

	//Setters
	void	SetPerspective(float m_aspect, float m_fov, float m_near, float m_far);
	void	SetProjection(const Mat4& p);
	void	SetView(const Vec3& position, const Vec3& target, const Vec3& up);
	void	Move(CAMERA::MOVE dir);


	void Update(float dt);
	
private:
	Mat4	m_projection;
	Mat4	m_view;

	Vec3	m_position;
	Vec3	m_direction;
	Vec3	m_up;
	Vec3	m_right;

	float	m_fov;
	float	m_aspect;
	float	m_near;
	float	m_far;
};