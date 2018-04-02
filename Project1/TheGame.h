#pragma once

#include "io_utils.h"
#include "Player.h"

class TheGame
{
	Player p[2];
public:
	void init();
	void run();
};