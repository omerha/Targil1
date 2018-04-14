#pragma once

#include "io_utils.h"
#include "Player.h"
#define QUIET_MODE -1
#define SHOWALL_MODE 2
#define TIE 0
class TheGame
{
	int numOfPlayers;
	Player p[2];
	int winner;
	Piece gameBoard[N+1][M+1]; //need to check if we actually need this board
	int showMode;
	int delayTime;
	bool showOnlyKnownInfo;
	bool over;
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
		numOfPlayers = 2;
		over = false;
		showMode = 2;
		delayTime = 50;
		showOnlyKnownInfo = false;
	};
	void move(int moveNum);
	void movePiece(const int& oldX, const int& oldY, const int& newX, const int& newY,const int& playerNum,const int& jokerX,const int& jokerY,const char& newJokerType);
	void drawPiece(const int & oldX, const int & oldY, const int & newX, const int & newY, int playerNum, int fightResult);
	void drawGameBoard();
	void createOutputFile();
	void drawBoardToFile(ofstream& outfile);
	void printToScreen(bool start);
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
	void drawBoardLines();
};