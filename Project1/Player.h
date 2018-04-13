#pragma once


#include "Piece.h"
#include "Reason.h"
#include "Error.h"
#include "Color.h"
#define M 10 //colums
#define N 10 // rows
#define K 13 // The num of pieces of each player
#include <string>
#include <fstream>
#include <sstream>
#define NUM_OF_ROCK 2
#define NUM_OF_PAPER 5
#define NUM_OF_SCISSORS 1
#define NUM_OF_BOMB 2
#define NUM_OF_JOKER 2
#define NUM_OF_FLAG 1
enum Pieces
{
	R=0,
	P=1,
	S=2,
	J = 3,
	B=4,
	F=5
};

class Player
{
	friend class TheGame;
	Piece playerBoard[N+1][M+1];
	int counterPieces[6];
	Reason status;
	std::string startGameFile; 
	std::string movesFile; 
	Error error;
	int errorLine;
	string movesArr[100];
	int numOfMoves = 0;
	Color color;
public:
	void readFromFile();
	void checkValidityiPieces();
	void countPieces(char type);
	void removePiece(int i, int j, char type);
	bool checkXYInRange(int num,char cord);
	Player();
	void checkForCorrectType(char type, int numOfRow);
	string* parseLine(string line, int& size,int lineNum,Error error);
	void putMovesFileInStringArr();
	bool move(int moveNum, int& newXLocation, int& newYLocation, int& oldXLocation, int& oldYLocation, int& jokerXLocation, int& jokerYLocation, char& newJokerType);
	//void movePlayerError(int lineNum);  we need this?
	void setPlayerStatus(Reason reason, Error theError, int line);
	void setColor(Color c) {
		color = c;
	}
	void setInputFile(string fileName)
	{
		startGameFile = fileName;
	}
	void setMoveFile(string fileName)
	{
		movesFile = fileName;
	}
	void printError();
	string returnReason();
	void hideJoker();
	bool checkMoveisLegal(const int& currX, const int& currY, const int& newX, const int& newY,const char& type);
};