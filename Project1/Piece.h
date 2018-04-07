#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Color.h"
using namespace std;

class Piece
{
	int x, y;
	char pieceType;
	bool joker;
	//int playerNum; -- we need this for printing the common board.
public: 

	void initPiece(std::string line);
	Piece()
	{
		x = y = 0;
		//playerNum = -1;
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
	/*
	int getPiecePlayerNum()
	{
		return playerNum;
	}
	*/
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

	void drawPiece(int xL,int yL);
	void removePiece(int xL, int yL);
	void drawPiece(Color color, int xL, int yL);
	void drawUnknownPiece(Color color, int xL, int yL);
	/*
	void setPiecePlayerNum(int pPlayerNum)
	{
		playerNum = pPlayerNum;
	}
	*/


	//void draw(char ch); // not implemented yet
	//void move(); // not implemented yet
	//void move(int direction); // not implemented yet
};