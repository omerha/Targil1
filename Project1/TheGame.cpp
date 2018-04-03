#include "TheGame.h"

void TheGame::init()
{

	//loop for
	p[0].readFromFile;
	if (p[0].status == noReason) // NO Bad Positioning input file for player <player> - line <bad line number>
	{
		p[0].checkValidityiPieces;
		if (p[0].status == noReason) // NO Bad Positioning input file for player <player> - line <bad line number>
		{
			p[0].setBoard;
		}
	}
	p[1].readFromFile;
	if (p[1].status == noReason) // NO Bad Positioning input file for player <player> - line <bad line number>
	{
		p[1].checkValidityiPieces;
		if (p[1].status == noReason) // NO Bad Positioning input file for player <player> - line <bad line number>
		{
			p[1].setBoard;
		}
	}
	if ((p[0].status == badPosition) && (p[1].status == badPosition))
	{
		//write in the output file: Bad Positioning input file for both players - player 1: line <X>, player 2: line <Y>
	}
	
	if (p[0].status == badPosition)
	{
		//player2 win
		//Bad Positioning input file for player <player1> -line <bad line number>
	}

	if (p[1].status == badPosition)
	{
		//player1 win
		//Bad Positioning input file for player <player2> -line <bad line number>
	}
	else //((p[0].status == noReason) && (p[1].status == noReason))
	{
		fight;
		if ((p[0].numPieces == 0) && (p[1].numPieces == 0))
		{
			winner = 0; //Both Positioning files are analyzed at the same “stage” - so if both are bad the result is 0 (no winner).
		}
		else if (p[0].numPieces == 0)
		{
			winner = 2; //Player 2 win
			res = allEaten; // All moving PIECEs of the opponent are eaten
		}
		else if (p[1].numPieces == 0)
		{
			winner = 1; //Player 1 win
			res= allEaten;// All moving PIECEs of the opponent are eaten
		}
	}
}
void TheGame::fight()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if ((p[0].playerBoard[i][j] != '-')&&(p[1].playerBoard[i][j] != '-'))
			{
				//check who is more power and erase the secound
			}
		}
	}
}

void TheGame::run()
{

}