#pragma once

#include "io_utils.h"
#include "Player.h"

class TheGame
{
	int numOfPlayers = 2;
	Player p[2]; //need to get the fileName
	int winner;
	Piece boardPieces[N][M];
	Reason res;

public:
	void init();
	void initStartBoard();
	void run();
	void checkForWinner();
	Piece piecesFight(Piece p1, Piece p2);
};