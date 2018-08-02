// std
#include <thread>
#include <future>
#include <iostream>

#include <unordered_map>

// Third party
#include "SFML/Graphics.hpp"

// Project
#include "Thing.h"
#include "engine.h"

int main()
{
	auto window_settings = sf::ContextSettings{ };
	window_settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(16 * 100, 9 * 100), "SFML works!", sf::Style::Default, window_settings);
	auto shape = sf::CircleShape{ 100.f };
	shape.setFillColor(sf::Color::Green);

	// name/value pairs
	auto textures = std::unordered_map<std::string, sf::Texture>{};
	textures.emplace(std::string{ "REEE" }, sf::Texture{ [] () { auto t = sf::Texture{}; t.loadFromFile("resources/REEE.bmp"); return t; }() });
	textures.emplace(std::string{ "SCREE" }, sf::Texture{ []() { auto t = sf::Texture{}; t.loadFromFile("resources/SCREE.bmp"); return t; }() });

	auto things = std::vector<Thing>{};
	things.push_back(Thing
		{
			Entity{ Vec2{ 800, 0 }, Vec2{ 0, 0 } },
			sf::Sprite{ textures.at("REEE") },
			true
		});
	things.push_back(Thing
		{
			Entity{ Vec2{ 200, 0 }, Vec2{ 0, 0 } },
			sf::Sprite{ textures.at("SCREE") }
		});
	auto instructions = Instructions{};

	while (window.isOpen())
	{
		auto engine_cycle = std::async(std::launch::async, [&] { engineMain(things, instructions); });
		auto event = sf::Event{};
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					instructions.move.right = true;
					break;
				case sf::Keyboard::Left:
					instructions.move.left = true;
					break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					instructions.move.right = false;
					break;
				case sf::Keyboard::Left:
					instructions.move.left = false;
					break;
				}
				break;
			}
		}

		window.clear(sf::Color::Black);
		for (auto& thing : things)
		{
			window.draw(thing.sprite);
		}
		window.display();
		engine_cycle.wait();
	}

	return 0;
}