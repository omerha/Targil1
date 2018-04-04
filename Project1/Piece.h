#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Piece
{
	
public:
	int x, y;
	char pieceType;
	bool joker;
	int playerNum;
	void initPiece(std::string line);
	//void draw(char ch); // not implemented yet
	//void move(); // not implemented yet
	//void move(int direction); // not implemented yet
};