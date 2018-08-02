#pragma once

#include <iosfwd>

struct Vec2
{
	float x, y;

	Vec2(const float x, const float y)
		: x{ x }, y{ y }
	{}

	Vec2& operator+=(const Vec2& other);


};

Vec2 operator+(Vec2 l, const Vec2& r);