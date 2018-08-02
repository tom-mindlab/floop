#pragma once

#include <iosfwd>

#include "SFML/Graphics/Sprite.hpp"

#include "Vec2.h"

std::ostream& operator<<(std::ostream& ostr, const Vec2& v);

struct Entity
{
	Vec2 position;
	Vec2 velocity;
};

struct Thing
{
	Entity entity;

	sf::Sprite sprite;

	bool is_player_controlled;


	Thing(sf::Sprite sprite, bool is_player_controlled = false)
		: is_player_controlled{ is_player_controlled }, entity{ { 0, 0 }, { 0, 0 }}, sprite{ sprite }
	{}

	Thing(Entity entity, sf::Sprite sprite, bool is_player_controlled = false)
		: is_player_controlled{ is_player_controlled }, entity{ entity }, sprite{ sprite }
	{}

	void Accelerate(Vec2 accel);
	void TimeStep();

};