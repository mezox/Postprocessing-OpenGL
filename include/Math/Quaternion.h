#pragma once

#include <pp_types.h>

#define M_PI           3.14159265358979323846

class Quaternion
{
public:
	Quaternion();
	Quaternion(float, float, float, float);
	Quaternion(const Vec3& n, float a);

	Quaternion& Set(float, float, float, float);
	Quaternion& Copy(const Quaternion &q);
	Quaternion& SetFromVector(const Vec3& v);
	Quaternion& SetFromAngle(float angle, const Vec3& axis);
	Quaternion& Normalize();

	static float Dot(const Quaternion& q, const Quaternion& r);

	float Dot(const Quaternion& q) const;
	float Length() const;
	float Norm() const;

	Quaternion Inverse() const;
	Quaternion Unit() const;

	
	//assign
	inline Quaternion& operator= (const Quaternion& rhs)
	{
		w = rhs.w;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;

		return *this;
	}

	//Logical
	inline bool operator== (const Quaternion& rhs)
	{
		return (
			(w == rhs.w) &&
			(x == rhs.x) &&
			(y == rhs.y) &&
			(z == rhs.z)
		);
	}

	inline bool operator!= (const Quaternion& rhs)
	{
		return !(*this == rhs);
	}

	//Access
	float	operator[] (const size_t i) const;
	float&	operator[] (const size_t i);

	//Arithmetic
	Quaternion operator- (void) const;
	Quaternion operator+ (const Quaternion& rhs) const;
	Quaternion operator+ (float s) const;
	Quaternion operator- (const Quaternion& rhs) const;
	Quaternion operator- (float s) const;
	Quaternion operator* (const Quaternion& rhs) const;
	Quaternion operator* (float s) const;
	Quaternion& operator+= (const Quaternion& rhs);
	Quaternion& operator+= (float s);
	Quaternion& operator-= (const Quaternion& rhs);
	Quaternion& operator-= (float s);
	Quaternion& operator*= (const Quaternion& rhs);
	Quaternion& operator*= (float s);

private:
	inline float ToRadians(float a) { return ((a / 360)*(float)M_PI * 2); }

public:
	static const Quaternion Identity;
	static const Quaternion Zero;

public:
	float w;
	float x;
	float y;
	float z;
};