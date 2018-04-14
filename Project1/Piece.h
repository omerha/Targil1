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
	bool revealType;
	bool revealJoker;
public: 

	Piece()
	{
		revealJoker = true;
		revealType = false;
		x = y = 0;
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
	void setRevealJokerStatus(bool jokerStatus)
	{
		revealJoker = jokerStatus;
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
	bool getPieceJokerRevealStatus()
	{
		return revealJoker;
	}
	void setRevealType(bool nRevealType)
	{
		revealType = nRevealType;
	}
	bool getRevealType()
	{
		return revealType;
	}


	void drawPiece(int xL,int yL);
	void removePiece(int xL, int yL);
	void drawPiece(Color color, int xL, int yL);
	void drawUnknownPiece(Color color, int xL, int yL);
};