#ifndef VEC3_H
#define VEC3_H

#include <math.h>

template <class T>

class vec3
{
public:

	T x, y, z;

	vec3() {}

	vec3(T i, T j, T k)
	{
		x = i;
		y = j;
		z = k;
	}

	vec3(const vec3& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	~vec3() {}

public:
	
	vec3 operator+ (const vec3 vec) const 
	{
		vec3 ret;

		ret.x = x + vec.x;
		ret.y = y + vec.y;
		ret.z = z + vec.z;

		return ret;
	}

	vec3 operator- (const vec3 vec) const 
	{
		vec3 ret;

		ret.x = x - vec.x;
		ret.y = y - vec.y;
		ret.z = z - vec.z;

		return ret;
	}

	void operator+= (const vec3 vec) const 
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}

	void operator-= (const vec3 vec) const 
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}

	void operator= (const vec3 vec) const 
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	bool operator== (const vec3 vec) const 
	{
		return vec.x == x && vec.y == y && vec.z == z;
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

	bool is_zero() 
	{
		return x == 0 && y == 0 && z == 0;
	}

	T distance_to( const vec3 vec) 
	{
		return sqrt((vec.x - x)*(vec.x - x) + (vec.y - y)*(vec.y - y) + (vec.z - z)*(vec.z - z));
	}

};

#endif // VEC3_H