#include "TheGame.h"

TheGame::TheGame()
{
	winner = 0;
}

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
		if (p[i].status != noReason)
			p[abs(i - 1)].win = true;
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
				if (res == 0) //It means that both players lost
					this->gameBoard[i][j].setPieceType = '-';
				if (res==1) ///It means that player 1 wins in this square
					this->gameBoard[i][j].setPieceJoker = p[0].playerBoard[i][j].getPieceType;
				else if (res==2) //It means that player 1 wins in this square
					this->gameBoard[i][j].setPieceJoker = p[1].playerBoard[i][j].getPieceType;
			}
			else if (p[0].playerBoard[i][j].getPieceType != '-')
				this->gameBoard[i][j].setPieceJoker = p[0].playerBoard[i][j].getPieceType;
			else if (p[1].playerBoard[i][j].getPieceType != '-')
				this->gameBoard[i][j].setPieceJoker = p[1].playerBoard[i][j].getPieceType;

		}
	}
}

int TheGame::pieceFight(int i, int j)
{  // The function gets two indexes and checks which piece is stronger, erases the second piece, 
	//updates the number of tools, returns 0 if a tie, 1 if the first player wins, and 2 if the second player is analyzed
	char typePlayer1 = p[0].playerBoard[i][j].getPieceType;
	char typePlayer2 = p[1].playerBoard[i][j].getPieceType;
	switch (typePlayer1)
	{
	case 'R':
		if (typePlayer2 == 'S')
		{
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[S]--;
			return 1;
		}
		if (typePlayer2 == 'P')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[R]--;
			return 2;
		}
		if (typePlayer2 == 'R')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[R]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[R]--;
			return 0;
		}
		if (typePlayer2 == 'B')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[R]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[B]--;
			return 0;
		}
		if (typePlayer2 == 'F')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[R]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[F]--;
			return 2;
		}
		break;
	case 'S':
		if (typePlayer2 == 'R')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[S]--;
			return 2;
		}
		if (typePlayer2 == 'P')
		{
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[P]--;
			return 1;
		}
		if (typePlayer2 == 'S')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[S]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[S]--;
			return 0;
		}
		if (typePlayer2 == 'B')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[S]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[B]--;
			return 0;
		}
		if (typePlayer2 == 'F')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[S]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[F]--;
			return 2;
		}
		break;
	case 'P':
		if (typePlayer2 == 'S')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[P]--;
			return 2;
		}
		if (typePlayer2 == 'R')
		{
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[R]--;
			return 1;
		}
		if (typePlayer2 == 'P')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[P]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[P]--;
			return 0;
		}
		if (typePlayer2 == 'B')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[P]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[B]--;
			return 0;
		}
		if (typePlayer2 == 'F')
		{
			p[0].playerBoard[i][j].setPieceType = '-';
			p[0].counterPieces[P]--;
			p[1].playerBoard[i][j].setPieceType = '-';
			p[1].counterPieces[F]--;
			return 2;
		}
		break;
	case 'B':
		p[0].playerBoard[i][j].setPieceType = '-';
		p[0].counterPieces[B]--;
		p[1].playerBoard[i][j].setPieceType = '-';
		if (typePlayer2 == 'S')
			p[1].counterPieces[S]--;
		else if (typePlayer2 == 'R')
			p[1].counterPieces[R]--;
		else if (typePlayer2 == 'P')
			p[1].counterPieces[P]--;
		else if (typePlayer2 == 'B')
			p[1].counterPieces[B]--;
		else if (typePlayer2 == 'F')
			p[1].counterPieces[F]--;
		return 0;
		break;
	case 'F':
		p[0].playerBoard[i][j].setPieceType = '-';
		p[0].counterPieces[F]--;
		p[1].playerBoard[i][j].setPieceType = '-';
		if (typePlayer2 == 'S')
			p[1].counterPieces[S]--;
		else if (typePlayer2 == 'R')
			p[1].counterPieces[R]--;
		else if (typePlayer2 == 'P')
			p[1].counterPieces[P]--;
		else if (typePlayer2 == 'B')
			p[1].counterPieces[B]--;
		else if (typePlayer2 == 'F')
		{
			p[1].counterPieces[F]--;
			return 0;
			break;
		}
			
		return 1;
		break;
	}


}

void TheGame::checkForWinner() 
{
	int i,  numPlayer, counter = 0;
	for (numPlayer = 0; numPlayer < 2; numPlayer++)
	{
		counter = 0;
		for (i = 0; i <= 3; i++)
		{
			counter += p[numPlayer].counterPieces[i];
		}

		if ((counter == 0) ||(p[numPlayer].counterPieces[F]==0))
		{
			p[abs(numPlayer - 1)].win = true;
		}

	}
	if (p[0].win &&p[1].win)
		this->winner = 3; //The game is over and the two player win, this mean tie
	else if (p[0].win)
		this->winner = 1; //The game is over and player 1 win
	else if (p[1].win)
		this->winner = 2; //The game is over and player 2 win

}

void TheGame::run()
{
	init();
	checkForWinner();
	while (!winner)
	{
		move();
	}
}

void TheGame::move()
{

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

