#include <GLCamera3D.h>

GLCamera3D::GLCamera3D()
{
	m_projection = Mat4(1.0f);
	m_view = Mat4(1.0f);

	m_position = Vec3(0.0f);
	m_direction = Vec3(0.0f, 0.0f, -1.0f);
	m_up = Vec3(0.0f,1.0f,0.0f);
	m_right = Vec3(0.0f,0.0f,1.0f);

	m_fov = 67.0f;
	m_aspect = 1.0f;
	m_near = 1.0f;
	m_far = 1000.f;
}


const Mat4 & GLCamera3D::Projection() const
{
	return m_projection;
}

const Mat4 & GLCamera3D::View() const
{
	return m_view;
}

const Vec3 & GLCamera3D::Position() const
{
	return m_position;
}

const Vec3 & GLCamera3D::Direction() const
{
	return m_direction;
}

const Vec3 & GLCamera3D::Up() const
{
	return m_up;
}

const Vec3 & GLCamera3D::Right() const
{
	return m_right;
}

const float & GLCamera3D::FieldofView() const
{
	return m_fov;
}

const float & GLCamera3D::Aspect() const
{
	return m_aspect;
}

const float & GLCamera3D::Near() const
{
	return m_near;
}

const float & GLCamera3D::Far() const
{
	return m_far;
}

void GLCamera3D::SetPerspective(float aspect, float fov, float near, float far)
{
	m_aspect = aspect;
	m_fov = fov;
	m_near = near;
	m_far = far;
	m_projection = glm::perspective(m_fov, m_aspect, m_near, m_far);
}

void GLCamera3D::SetProjection(const Mat4& p)
{
	m_projection = p;
}

void GLCamera3D::SetView(const Vec3 & position, const Vec3 & target, const Vec3 & up)
{
	m_position = position;
	m_direction = target;
	m_up = up;

	m_view = glm::lookAt(m_position, m_direction, m_up);
}

void GLCamera3D::Move(CAMERA::MOVE dir)
{
}

void GLCamera3D::Update(float dt)
{
}
