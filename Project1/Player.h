#pragma once


#include "Piece.h"
#include "Reason.h"
#include "Error.h"

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
	//int playerNum;
	//Piece playerPieces[K];
	friend class TheGame;
	Piece playerBoard[N][M];
	int counterPieces[6];
	Reason status;
	//int numOfMovingPieces;
	//bool flagCaptured = false;
	std::string startGameFile;
	std::string movesFile;
	Error error;
	int errorLine;
	bool win;
	string movesArr[100];
	int numOfMoves = 0;
	//std::string error;
public:
	void readFromFile();//קוראת את הנתונים מהקובץ ומעדכנת את ה- player pieces
	void setBoard();
	void checkValidityiPieces();
	void removePiece();
	void countPieces(char type);
	void checkXYInRange(int num,char cord);
	Player(std::string vStartGameFile,std:: string vMovesFile,int nPlayer);
	void checkForCorrectType(char type);
	string* parseLine(string line, int& size);
	void putMovesFileInStringArr();
};