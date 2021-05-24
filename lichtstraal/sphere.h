#pragma once
#include "vector3.h"

class sphere
{
public:
	float radius;
	vector3 center;

public:
	sphere()
	{
		radius = 1;
		center = vector3();
	}

	sphere(float r, vector3 c)
	{
		radius = r;
		center = c;
	}
};
