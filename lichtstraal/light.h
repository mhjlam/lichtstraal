#pragma once
#include "vector3.h"

class light
{
public:
	point position;
	float brightness;

public:
	light(point p = point(), float b = 1.0f)
	{
		position = p;
		brightness = b;
	}
};
