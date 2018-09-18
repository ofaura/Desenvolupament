#ifndef _VEC3_H
#define _VEC3_H

#include <math.h>

template <class T>

class vec3
{
public:

	T x, y, z;

	vec3() {}

	vec3(T x, T y, T z) :x(x), y(y), z(z) {}

	vec3(const vec3& vector) : x(vector.x), y(vec.y), z(vector.z) {}

	~vec3() {}

public:
	
	vec3 operator+ (const vec3 vector) const
	{
		return vec3(x + vector.x, y + vector.y, z + vector.z);
	}

	vec3 operator- (const vec3 vector) const
	{
		return vec3(x - vector.x, y - vector.y, z - vector.z);
	}

	vec3 operator+= (const vec3 &vector) 
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;

		return *this;
	}

	vec3 operator-= (const vec3 &vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;

		return *this;
	}

	void operator= (const vec3 vector) const
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}

	bool operator== (const vec3 vector) const
	{
		return vector.x == x && vector.y == y && vector.z == z;
	}

public:

	void normalize() 
	{
		T m = sqrt(x*x + y*y + z*z);

		x = x / m;
		y = y / m;
		z = z / m;
	}

	void zero() 
	{
		x = y = z = 0;
	}

	bool is_zero const() 
	{
		return x == 0 && y == 0 && z == 0;
	}

	T distance_to( const vec3 vector)
	{
		return sqrt((vector.x - x)*(vector.x - x) + (vector.y - y)*(vector.y - y) + (vector.z - z)*(vector.z - z));
	}

};

#endif // _VEC3_H












//JA! deez nuts 