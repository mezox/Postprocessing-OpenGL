#include <Quaternion.h>
#include <cassert>

Quaternion::Quaternion(const Vec3& n, float a)
{
	a = ToRadians(a);

	w = cos(a / 2);

	x = n.x*sin(a / 2);
	y = n.y*sin(a / 2);
	z = n.z*sin(a / 2);
}

Quaternion::Quaternion()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Quaternion::Quaternion(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

const Quaternion Quaternion::Identity(1.0f, 0.0f, 0.0f, 0.0f);
const Quaternion Quaternion::Zero(0.0f, 0.0f, 0.0f, 0.0f);

Quaternion& Quaternion::Set(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;

	return *this;
}

Quaternion& Quaternion::Copy(const Quaternion& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;

	return *this;
}

Quaternion& Quaternion::SetFromVector(const Vec3& v)
{
	float c = M_PI / 360,
		x = v.x * c,
		y = v.y * c,
		z = v.z * c,

		c1 = std::cos(y),
		s1 = std::sin(y),
		c2 = std::cos(-z),
		s2 = std::sin(-z),
		c3 = std::cos(x),
		s3 = std::sin(x),

		c1c2 = c1 * c2,
		s1s2 = s1 * s2;

	w = c1c2 * c3 - s1s2 * s3;
	x = c1c2 * s3 + s1s2 * c3;
	y = s1 * c2 * c3 + c1 * s2 * s3;
	z = c1 * s2 * c3 - s1 * c2 * s3;

	return *this;
}

Quaternion& Quaternion::SetFromAngle(float angle, const Vec3 &axis)
{
	float halfAngle = angle / 2,
		s = std::sin(halfAngle);

	x = axis.x * s;
	y = axis.y * s;
	z = axis.z * s;
	w = std::cos(halfAngle);

	return *this;
}

float Quaternion::Length() const
{
	return std::sqrt(x*x + y*y + z*z + w*w);
}

Quaternion& Quaternion::Normalize()
{
	float l = Length();
	assert(l != 0);

	return (*this) *= 1.0f/l;
}

float Quaternion::Dot(const Quaternion& q, const Quaternion& r)
{
	return (
		(q.w * r.w) +
		(q.x * r.x) +
		(q.y * r.y) +
		(q.z * r.z)
	);
}

float Quaternion::Dot(const Quaternion& q) const
{
	return (
		(q.w * w) +
		(q.x * x) +
		(q.y * y) +
		(q.z * z)
	);
}

float Quaternion::operator[] (const size_t i) const
{
	assert(i < 4); //only 3 members

	return *(&x + i);
}

float& Quaternion::operator[] (const size_t i)
{
	assert(i < 4); //only 3 members

	return *(&x + i);
}

Quaternion Quaternion::operator- (void) const
{
	return Quaternion(-w, -x, -y, -z);
}

Quaternion Quaternion::operator+ (const Quaternion& rhs) const
{
	return Quaternion(w + rhs.w, x + rhs.x, y + rhs.y, z + rhs.z);
}

Quaternion Quaternion::operator+ (float s) const
{
	return Quaternion(w + s, x + s, y + s, z + s);
}

Quaternion Quaternion::operator- (const Quaternion& rhs) const
{
	return Quaternion(w - rhs.w, x - rhs.x, y - rhs.y, z - rhs.z);
}

Quaternion Quaternion::operator- (float s) const
{
	return Quaternion(w - s, x - s, y - s, z - s);
}

Quaternion Quaternion::operator* (float s) const
{
	return Quaternion(w*s, x*s, y*s, z*s);
}

Quaternion Quaternion::operator* (const Quaternion& rhs) const
{
	float _w = 0.0f;
	float _x = 0.0f;
	float _y = 0.0f;
	float _z = 0.0f;

	//calculate new w
	_w = (rhs.w * w) -
		(rhs.x * x) -
		(rhs.y * y) -
		(rhs.z * z);

	//calculate new x
	_x = (rhs.w * x) +
		(rhs.x * w) -
		(rhs.y * z) +
		(rhs.z * y);

	//calculate new y
	_y = (rhs.w * y) +
		(rhs.x * z) +
		(rhs.y * w) -
		(rhs.z * x);

	//calculate new z
	_z = (rhs.w * z) -
		(rhs.x * y) +
		(rhs.y * x) +
		(rhs.z * w);

	return Quaternion(_w, _x, _y, _z);
}

Quaternion& Quaternion::operator*= (const Quaternion& rhs)
{
	*this = *this * rhs;

	return *this;
}

Quaternion& Quaternion::operator*= (float s)
{
	*this = *this * s;

	return *this;
}