#pragma once
#define M 10
#define N 10
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
	int nPieces[counter];
	char board[N][M];
	std::string fileName;
	std::string error;
public:
	void readFromFile();
	void initBoard(std::string line, int& illegalFile);
	bool checkNumOfPieces(int& illegalFile,char type);
	Player(std::string vFileName);
};