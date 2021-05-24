#pragma once
#include "vector3.h"
#include "sphere.h"

class ray
{
public:
	vector3 origin;
	vector3 direction;

public:
	ray(vector3 src, vector3 dir)
	{
		origin = src;
		direction = dir;
	}

	ray(vector3 src, vector3 dst)
	{
		origin = src;
		direction = vector3::normalize(dst - src);
	}
};

static bool intersect(ray r, sphere s, float& t, point& q)
{
	// sphere center to ray origin
	vector3 l = r.origin - s.center;

	float b = vector3::dot(l, r.direction);
	float c = vector3::dot(l, l) - s.radius * s.radius;

	// ray originates outside sphere and points away from sphere
	if (c > 0.0f && b > 0.0f) return false;

	// discriminant
	float d = b*b - c;

	// ray misses sphere
	if (d < 0.0f) return false;

	// t value of intersection
	t = -b - std::sqrtf(d);
	if (t < 0.0f) t = 0.0f;

	// point of intersection
	q = r.origin + t * r.direction;

	return true;
}
