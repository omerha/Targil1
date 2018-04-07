#include "Piece.h"
#include "io_utils.h"

/*
Piece::Piece()//constructor
{
	x = y = 0;
	pieceType = '-';
	joker = false;
}

void Piece::initPiece(string line)
{
	istringstream tempCh(line);
	int xLocation;
	int yLocation;
	char pieceType;
	string temp;
////	Piece pieceResult;
	//TODO: change to get from one long string without spaces. -- Leave as it is for now.
	getline(tempCh, temp, ' ');
	pieceType = temp[0];


	getline(tempCh, temp, ' ');
	xLocation = stoi(temp);
	if (xLocation < 1 && xLocation>10) // X coordinate isn't inrange
	{		return;
	}
	getline(tempCh, temp, ' ');
	yLocation = stoi(temp);
	if (yLocation < 1 && yLocation>10) // Y coordinate isn't inrange
	{
		return;
	}

	if (pieceType == 'J')
	{
////		pieceResult.joker = true;
		this->joker = true;
		getline(tempCh, temp, ' ');
		pieceType = temp[0];

	}
	else
	{
////		pieceResult.joker = false;
		this->joker = false;
	}
	//If the piece type isn't one of the pieces in the game
	if ((pieceType != 'R') && (pieceType != 'P') && (pieceType != 'S') && (pieceType != 'B') && (pieceType != 'F')) 	
	{
		return;
	}

////	pieceResult.pieceType = pieceType;
////	pieceResult.x = xLocation;
////	pieceResult.y = yLocation;
	this->pieceType = pieceType;
	this->x = xLocation;
	this->y = yLocation;
////	return pieceResult;
	

}
*/

void Piece::drawPiece(int xL, int yL)
{
	gotoxy(xL*3, yL*2);
	cout << pieceType;


}

void Piece::removePiece(int xL, int yL)
{
	setTextRemoveColor();
	gotoxy(xL * 3, yL * 2);
	cout << " ";
}

void Piece::drawPiece(Color color, int xL, int yL)
{
	if (joker)
	{
		if (revealJoker)
			setTextbBackground(color);
		revealJoker = true;
	}
	
	else
		setTextColor(color);
	gotoxy(xL * 3, yL * 2);
	cout << pieceType;
}

void Piece::drawUnknownPiece(Color color, int xL, int yL)
{
	setTextColor(color);
	gotoxy(xL * 3, yL * 2);
	cout << "U";
}


