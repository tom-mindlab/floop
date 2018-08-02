#include "Vec2.h"

Vec2 operator+(Vec2 l, const Vec2& r)
{
	l.x += r.x;
	l.y += r.y;
	return l;
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	this->x += other.x;
	this->y += other.y;

	return *this;
}