#include "engine.h"
#include <iostream>

void engineMain(std::vector<Thing>& things, const Instructions& instructions)
{
	for (auto& e : things)
	{
		if (e.is_player_controlled)
		{
			if (instructions.move.right)
			{
				e.Accelerate(Vec2{ 0.05f, 0 });
			}
			if (instructions.move.left)
			{
				e.Accelerate(Vec2{ -0.05f, 0 });
			}
		}
		
		e.Accelerate(Vec2{ 0, -0.01f });

		e.TimeStep();
	}
}