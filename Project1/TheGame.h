#pragma once

#include "io_utils.h"
#include "Player.h"

class TheGame
{
	int numOfPlayers = 2;
	Player p[2]; //need to get the fileName
	int winner;
	Piece boardPieces[N][M];//This array will start from 1 and instead to be i = 0;i<10 it will be i=1;i<=10
	Reason res;

public:
	void init();
	void initStartBoard();
	void run();
	void checkForWinner();
	int pieceFight(int i, int j);
};