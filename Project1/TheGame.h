#pragma once

#include "io_utils.h"
#include "Player.h"

class TheGame
{
	int numOfPlayers = 2;
	Player p[2] = {Player("test.txt","testmove.txt",1),Player("test2.txt","",2)}; //need to get the fileName
	int winner;
	Piece gameBoard[N][M];
	Reason res;

public:
	void init();
	void initStartBoard();
	void run();
	void checkForWinner();
	int pieceFight(int i, int j);
	TheGame()
	{
		winner = 0;
	};
	void move();
};