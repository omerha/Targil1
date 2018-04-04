#include "TheGame.h"

void TheGame::init()
{

	//loop for
	for (int i = 0; i < 2; i++)
	{
		p[i].readFromFile();
		if (p[i].status == noReason) // NO Bad Positioning input file for player <player> - line <bad line number>
		{
			p[i].checkValidityiPieces();
			if (p[i].status == noReason) // NO Bad Positioning input file for player <player> - line <bad line number>
			{
				p[i].setBoard();
			}
		}
	}
	if ((p[0].status == badPosition) && (p[1].status == badPosition))
	{
		//write in the output file: Bad Positioning input file for both players - player 1: line <X>, player 2: line <Y>
	}
	
	else if (p[0].status == badPosition)
	{
		//player2 win
		//Bad Positioning input file for player <player1> -line <bad line number>
	}

	else if (p[1].status == badPosition)
	{
		//player1 win
		//Bad Positioning input file for player <player2> -line <bad line number>
	}
	else //((p[0].status == noReason) && (p[1].status == noReason))
	{
		initStartBoard();
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
void TheGame::initStartBoard()
{
	int i, j;
	for (i = 0; i < numOfPlayers; i++)
	{
		for (j = 0; j < K&&!winner; j++)
			{
				if (boardPieces[p[i].playerPieces[j].x - 1][p[i].playerPieces[j].y - 1].pieceType != '-')
				{
					boardPieces[p[i].playerPieces[j].x - 1][p[i].playerPieces[j].y - 1] = p[i].playerPieces[j];//Need to create ctor
				}
				else
				{
					boardPieces[p[i].playerPieces[j].x - 1][p[i].playerPieces[j].y - 1] = piecesFight(boardPieces[p[i].playerPieces[j].x - 1][p[i].playerPieces[j].y - 1], p[i].playerPieces[j]);
				}
			}
		if (winner)
		{
			//create winner function
			return;
		}
	}
}

void TheGame::run()
{

}

void TheGame::checkForWinner()
{
	for (int i = 0; i < numOfPlayers - 1; i++)
	{

	}
}

Piece TheGame::piecesFight(Piece p1, Piece p2)
{
	///fight fight fight

	
}