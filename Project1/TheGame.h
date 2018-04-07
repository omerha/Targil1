#pragma once

#include "io_utils.h"
#include "Player.h"
#define QUIET_MODE -1
#define SHOWALL_MODE 2
#define TIE 0
class TheGame
{
	int numOfPlayers = 2; //Guy- we need this?
	Player p[2];
	//Player p[2] = {Player("test.txt","testmove.txt",1),Player("test2.txt","",2)}; //need to get the fileName
	int winner;
	Piece gameBoard[N+1][M+1]; //need to check if we actually need this board
	Reason res;
	int showMode = 2;
	int delayTime = 50;
	bool showOnlyKnownInfo = false;
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
	void movePiece(const int& oldX, const int& oldY, const int& newX, const int& newY,int playerNum);
	void drawPiece(const int & oldX, const int & oldY, const int & newX, const int & newY, int playerNum, int fightResult);
	void drawGameBoard();
	void createOutputFile();
	//void printToScreen();
	void setShowMode(int whoToShow)// 2 is all 1 is player 2 0 is player 1 and -1 is none aka quiet.
	{
		showMode= whoToShow - 1;
	}
	void setDelayMode(int sDelay)
	{
		delayTime = sDelay;
	}
	void setUnkownInfoMode(bool unkownInfoMode)
	{
		showOnlyKnownInfo = unkownInfoMode;
	}
};