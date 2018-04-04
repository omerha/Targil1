#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Piece
{
	int x, y;
	char pieceType;
	bool joker;
	int playerNum;
public:

	void initPiece(std::string line);
	Piece()
	{
		x = y = 0;
		playerNum = -1;
		joker = false;
		pieceType = '-';
	}
	int getPieceX()
	{
		return x;
	}
	int getPieceY()
	{
		return y;
	}
	char getPieceType()
	{
		return pieceType;
	}
	bool getPieceJoker()
	{
		return joker;
	}
	int getPiecePlayerNum()
	{
		return playerNum;
	}
	void setPieceX(int pX)
	{
		x = pX;
	}
	void setPieceY(int pY)
	{
		y = pY;
	}
	void setPieceType(char pPieceType)
	{
		pieceType = pPieceType;
	}
	void setPieceJoker(bool pJoker)
	{
		joker = pJoker;
	}
	void setPiecePlayerNum(int pPlayerNum)
	{
		playerNum = pPlayerNum;
	}


	//void draw(char ch); // not implemented yet
	//void move(); // not implemented yet
	//void move(int direction); // not implemented yet
};