#pragma once

#include "Piece.h"
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
	R,
	P,
	B,
	J,
	F,
	S,
	counter
};

class Player
{
	Piece playerPieces[K];
	int nPieces[counter];
	char playerBoard[N][M];
	std::string fileName;
	std::string error;
public:
	void readFromFile();
	void initBoard(std::string line, int& illegalFile);
	bool checkNumOfPieces(int& illegalFile,char type);
	Player(std::string vFileName);
};