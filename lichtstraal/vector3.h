/* Ray tracer. */

#pragma once
#include <cmath>

class vector3;
typedef vector3 point;
typedef vector3 normal;


class vector3
{
public:
	float x, y, z;

public:
	vector3(float xyz = 0)
	{
		x = y = z = xyz;
	}

	vector3(float xx, float yy, float zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}

	float magnitude()
	{
		return std::sqrtf(x * x + y * y + z * z);
	}

	vector3 operator+(vector3 v)
	{
		return vector3(x + v.x, y + v.y, z + v.z);
	}

	vector3 operator-(vector3 v)
	{
		return vector3(x - v.x, y - v.y, z - v.z);
	}

	static vector3 normalize(vector3 v)
	{
		float m = v.magnitude();
		return vector3(v.x / m, v.y / m, v.z / m);
	}

	static float distance(vector3 v, vector3 w)
	{
		return std::sqrtf((v.x * w.x) * (v.x * w.x) +
						  (v.y * w.y) * (v.y * w.y) +
			              (v.z * w.z) * (v.z * w.z));
	}

	static float dot(vector3 v, vector3 w)
	{
		return v.x * w.x + v.y * w.y + v.z * w.z;
	}

	static vector3 cross(vector3 v, vector3 w)
	{
		return vector3(v.y * w.z - v.z * w.y, 
			           v.z * w.x - v.x * w.z, 
					   v.x * w.y - v.y * w.x);
	}
};

vector3 operator*(vector3 v, float s)
{
	return vector3(v.x * s, v.y * s, v.z * s);
}

vector3 operator*(float s, vector3 v)
{
	return vector3(s * v.x, s * v.y, s * v.z);
}

