#pragma once

#include <vector>

#include "Thing.h"

struct Instructions
{
	bool jump = false;
	struct Move
	{
		bool left = false;
		bool right = false;
	} move;
};

void engineMain(std::vector<Thing>& things, const Instructions& instructions);
