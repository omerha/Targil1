#include "Piece.h"
#include "io_utils.h"

void Piece::drawPiece(int xL, int yL)
{
	gotoxy(xL*3+3, yL*2+3);
	cout << pieceType;
}

void Piece::removePiece(int xL, int yL)
{
	setTextRemoveColor(BLACK);
	gotoxy(xL * 3+3, yL * 2+3);
	cout << " ";
	revealJoker = false;
	revealType = false;
	setTextRemoveColor(WHITE);
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
	gotoxy(xL * 3+3, yL * 2+3);
	cout << pieceType;
	revealType = true;
}

void Piece::drawUnknownPiece(Color color, int xL, int yL)
{
	setTextColor(color);
	gotoxy(xL * 3+3, yL * 2+3);
	if (revealType)
		cout << pieceType;
	else
		cout << "U";
}


