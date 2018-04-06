#pragma once

#include "io_utils.h"
#include "Player.h"

class TheGame
{
	int numOfPlayers = 2;
	Player p[2] = {Player("test.txt","testmove.txt",1),Player("test2.txt","",2)}; //need to get the fileName
	int winner;
	Piece gameBoard[N+1][M+1];
	Reason res;

public:
	void init();
	void initStartBoard();
	void run();
	void checkForWinner();
	int pieceFight(int i, int j);
	void setFightResult(int fightResult, int xLoc, int yLoc);
	TheGame()
	{
		winner = 0;
	};
	void move(int moveNum);
	void movePiece(const int& oldX, const int& oldY, const int& newX, const int& newY);
	void drawGameBoard();
};