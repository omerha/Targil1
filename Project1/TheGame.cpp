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

	
		initStartBoard();

	
}

void TheGame::initStartBoard()
{ // The function places the tools of the two players on the board, 
	//if there are two tools on the same slot check who is stronger and flatten the other

	int i, j, res;
	for (i = 0; i < N; i++)
	{
		for (i = 0; i < M; i++)
		{
			if ((p[0].playerBoard[i][j].getPieceType != '-') && (p[1].playerBoard[i][j].getPieceType != '-'))
			{
				res = pieceFight(i, j);
			}

		}
	}
}

int TheGame::pieceFight(int i, int j)
{  // The function gets two indexes and checks which piece is stronger, erases the second piece, 
	//updates the number of tools, returns 0 if a tie, 1 if the first player wins, and 2 if the second player is analyzed
	char typePlayer1 = p[0].playerBoard[i][j].getPieceType;
	char typePlayer2 = p[1].playerBoard[i][j].getPieceType;
	switch (typePlayer1)
		case 'R':


}
/*void TheGame::initStartBoard()
{
	int i, j;
	int currXPosition, currYPosition;
	for (i = 0; i < numOfPlayers; i++)
	{
		for (j = 1; j <= K&&!winner; j++)//Starting from 1 so it will be easier.
			{
			currXPosition = p[i].playerPieces[j].getPieceX();
			currYPosition = p[i].playerPieces[j].getPieceY();
				if (boardPieces[currXPosition][currYPosition].getPieceType() == '-')
				{
					boardPieces[currXPosition][currYPosition] = p[i].playerPieces[j];//Need to create ctor
				}
				else
				{
					boardPieces[currXPosition][currYPosition] = piecesFight(boardPieces[currXPosition][currYPosition], p[i].playerPieces[j]);
				}
			}
		if (winner)
		{
			//create winner function
			return;
		}
	}
}*/

void TheGame::run()
{

}

void TheGame::checkForWinner() //Leave it like this I'll finish it.
{
	int howManyPlayerWithZeroPiecesLeft = 0;
	int playerNumWithZeroPieceLeft = NULL;
	if (!winner)
	{
		for (int i = 0; i < numOfPlayers; i++)
		{
			if (p[i].numOfMovingPieces == 0)
			{
				howManyPlayerWithZeroPiecesLeft += 1;
				playerNumWithZeroPieceLeft = i + 1;
			}
		}
	}
}

