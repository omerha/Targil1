#pragma once

#include "io_utils.h"
#include "Player.h"

class TheGame
{
	Player p[2]; //need to get the fileName
	int winner;
	Reason res;

public:
	void init();
	void fight();
	void run();

};