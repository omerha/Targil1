#pragma once
#define M 10
#define N 10
#define typePieces 6
#include<string.h>
#include <fstream>
#include <sstream>
enum Pieces
{
	R = 0,
	P = 1,
	S = 2,
	B = 3,
	J = 4,
	F = 5
};

class Player
{

public:
	char** readFromFile(std::string fileName);
	void initBoard(std::string line, char board[N][M], int& illegalFile, int* counterPieces);
	void initilizeBoard(char board[N][M]);
};