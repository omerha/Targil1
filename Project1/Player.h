#pragma once

#include "Piece.h"
#include "Reason.h"


#define M 10 //colums
#define N 10 // rows
#define K 10 // The num of pieces of each player
#include <string>
#include <fstream>
#include <sstream>
#define MAX_ROCK 2
#define MAX_PAPER 5
#define MAX_SCISSORS 1
#define MAX_BOMB 2
#define MAX_JOKER 2
#define MAX_FLAG 1
enum Pieces
{
	R=0,
	P=2,
	S=1,
	B=2,
	J=2,
	F=1

};

class Player
{
	Piece playerPieces[K];
	friend class TheGame;
	char playerBoard[N][M];
	Reason status;
	int numPieces;
	std::string fileName;
	std::string error;
public:
	void readFromFile();//קוראת את הנתונים מהקובץ ומעדכנת את ה- player pieces
	void setBoard();
	void checkValidityiPieces();
	Player(std::string vFileName);
};