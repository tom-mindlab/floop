#include "Thing.h"

#include <iostream>

void Thing::Accelerate(const Vec2 accel)
{
	this->entity.velocity += accel;
}

void Thing::TimeStep()
{
	this->entity.position += this->entity.velocity;
	this->sprite.setPosition(sf::Vector2f{ this->entity.position.x, (-1) * this->entity.position.y });
}

std::ostream& operator<<(std::ostream& ostr, const Vec2& v)
{
	return ostr << "{" << v.x << ", " << v.y << "}";
}