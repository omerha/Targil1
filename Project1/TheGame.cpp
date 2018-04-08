#include "TheGame.h"


void TheGame::init()
{
	p[0].setColor(YELLOW);
	p[1].setColor(RED);




	p[0].setInputFile("player1.rps_board");
	p[0].setMoveFile("player1.rps_moves");
	p[0].putMovesFileInStringArr();
	p[1].setInputFile("player2.rps_board");
	p[1].setMoveFile("player2.rps_moves");
	p[1].putMovesFileInStringArr();
	bool goodToInitBoard = true;

	for (int i = 0; i < this->numOfPlayers; i++)
	{
		goodToInitBoard = true;
		p[i].readFromFile();

		if (p[i].status == noReason) // NO Bad Positioning input file for player <player> - line <bad line number>
		{
			p[i].checkValidityiPieces();
			if (p[i].status != noReason)
				goodToInitBoard = false;
			if (showOnlyKnownInfo)
				p[i].hideJoker();
		}
		else
			goodToInitBoard = false;
	}	
	
	 // The printing is just for checking the status and the error print after reading the input file
	/*
	cout << "Input File: \n";
	cout << "----The player number " << 1 << " -----\n";
	cout << "the status: " << p[0].status << "\n";

	cout << "the error: " << p[0].error << "\n";
	cout << "the error line: " << p[0].errorLine << "\n";
	cout << "----The player number " << 2 << " -----\n";
	cout << "the status: " << p[1].status << "\n";

	cout << "the error: " << p[1].error << "\n";
	cout << "the error line: " << p[1].errorLine << "\n";
	*/
	if (goodToInitBoard)
		initStartBoard();
}

void TheGame::initStartBoard()
{ // The function places the tools of the two players on the board, 
	//if there are two tools on the same slot check who is stronger and flatten the other

	int i, j, res;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			if ((p[0].playerBoard[i][j].getPieceType() != '-') && (p[1].playerBoard[i][j].getPieceType() != '-'))
			{
				
				res = pieceFight(i, j);
				//The printing is just to check whice piece win in the fight
				/*
				cout << "we are fighting in square: " << i << "*" << j << "\n";
				cout << "the winner is: " << res << "\n";
				*/
				setFightResult(res, i, j);
			}
			else if (p[0].playerBoard[i][j].getPieceType() != '-')
				this->gameBoard[i][j].setPieceType(p[0].playerBoard[i][j].getPieceType());
			else if (p[1].playerBoard[i][j].getPieceType() != '-')
				this->gameBoard[i][j].setPieceType(p[1].playerBoard[i][j].getPieceType());

		}
	}
	
}

int TheGame::pieceFight(int i, int j)
{  // The function gets two indexes and checks which piece is stronger, erases the second piece, 
	//updates the number of tools, returns 0 if a tie, 1 if the first player wins, and 2 if the second player is analyzed
	char typePlayer1 = p[0].playerBoard[i][j].getPieceType();
	char typePlayer2 = p[1].playerBoard[i][j].getPieceType();
	bool jokerPlayer1 = p[0].playerBoard[i][j].getPieceJoker();
	bool jokerPlayer2 = p[1].playerBoard[i][j].getPieceJoker();
	switch (typePlayer1)
	{
	case 'R':
		if (typePlayer2 == 'S') //The piece of player 1 win
		{
			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[S]--;
			return 1;
		}
		else if (typePlayer2 == 'P') //The piece of player 2 win
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[R]--;
			return 2;
		}
		else if (typePlayer2 == 'R') //The two pieces lose
		{
			
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else 
				p[0].counterPieces[R]--;

			p[1].playerBoard[i][j].setPieceType('-');

			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[R]--;
			return 0;
		}
		else if (typePlayer2 == 'B') //The two pieces lose
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[B]--;

			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[B]--;
			return 0;
		}
		else if (typePlayer2 == 'F') //Player 1 capture the flag of player 2
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else 
				p[0].counterPieces[R]--;
			p[1].playerBoard[i][j].setPieceType('-');
			p[1].counterPieces[F]--;
			return 1;
		}

		break;
	case 'S':
		if (typePlayer2 == 'R') //The piece of player 2 win
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[S]--;
			return 2;
		}
		else if (typePlayer2 == 'P') //The piece of player 1 win
		{
			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[P]--;
			return 1;
		}
		else if (typePlayer2 == 'S') // The two pieces lose
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[S]--;
			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[S]--;
			return 0;
		}
		else if (typePlayer2 == 'B')//The two pieces lose
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[S]--;
			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[B]--;
			return 0;
		}
		else if (typePlayer2 == 'F') //Player 1 capture the flag of player 2
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[S]--;
			p[1].playerBoard[i][j].setPieceType('-');
			p[1].counterPieces[F]--;
			return 1;
		}
		break;
	case 'P':
		if (typePlayer2 == 'S') //The piece of player 2 win
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[P]--;
			return 2;
		}
		else if (typePlayer2 == 'R') //The piece of player 1 win
		{
			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[R]--;
			return 1;
		}
		else if (typePlayer2 == 'P') //The two pieces lose
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[P]--;
			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[P]--;
			return 0;
		}
		else if (typePlayer2 == 'B') //The two piece lost
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[P]--;
			p[1].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer2)
				p[1].counterPieces[J]--;
			else
				p[1].counterPieces[B]--;
			return 0;
		}
		else if (typePlayer2 == 'F')
		{
			p[0].playerBoard[i][j].setPieceType('-');
			if (jokerPlayer1)
				p[0].counterPieces[J]--;
			else
				p[0].counterPieces[P]--;
			p[1].playerBoard[i][j].setPieceType('-');
			p[1].counterPieces[F]--;
			return 1;
		}
		break;
	case 'B': //The two pieces lose
		p[0].playerBoard[i][j].setPieceType('-');
		if (jokerPlayer1)
			p[0].counterPieces[J]--;
		else
			p[0].counterPieces[B]--;
		p[1].playerBoard[i][j].setPieceType('-');
		if (jokerPlayer2)
			p[1].counterPieces[J]--;
		else if (typePlayer2 == 'S')
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
			return 1;
			break;
		}
		return 0;
		break;
	case 'F': //Player 2 capture the flag of player 1
		p[0].playerBoard[i][j].setPieceType('-');
		p[0].counterPieces[F]--;
		p[1].playerBoard[i][j].setPieceType('-');
		if (jokerPlayer2)
			p[1].counterPieces[J]--;
		else if (typePlayer2 == 'S')
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
			
		return 2;
		break;
	default:
		return -1;
	}


}

void TheGame::setFightResult(int fightResult, int xLoc, int yLoc)
{
	if (fightResult == 0) //It means that both players lost
	{
		this->gameBoard[xLoc][yLoc].setPieceType('-');
		p[0].playerBoard[xLoc][yLoc].setPieceType('-');
		p[1].playerBoard[xLoc][yLoc].setPieceType('-');
	}
	if (fightResult == 1) ///It means that player 1 wins in this square
	{
		this->gameBoard[xLoc][yLoc].setPieceType(p[0].playerBoard[xLoc][yLoc].getPieceType());
		p[1].playerBoard[xLoc][yLoc].setPieceType('-');
	}
	else if (fightResult == 2) //It means that player 2 wins in this square
	{
		this->gameBoard[xLoc][yLoc].setPieceType(p[1].playerBoard[xLoc][yLoc].getPieceType());
		p[0].playerBoard[xLoc][yLoc].setPieceType('-');
	}
}

void TheGame::checkForWinner() 
{
	int i,  numPlayer, counter = 0;
	for (numPlayer = 0; numPlayer < this->numOfPlayers; numPlayer++)
	{
		if (p[numPlayer].status != noReason)
		{
			//p[abs(numPlayer - 1)].win = true;
			over = true;
		}
		counter = 0;
		for (i = 0; i <= 3; i++)
		{
			counter += p[numPlayer].counterPieces[i];
		}

		if (counter == 0)
		{
			p[i].status = allEaten;
			over = true;
			//p[abs(numPlayer - 1)].win = true;
		}
		if (p[numPlayer].counterPieces[F] == 0)
		{
			p[i].status = flagsCaptured;
			over = true;
			//p[abs(numPlayer - 1)].win = true;
		}
	}
	if (over)
	{
		if ((p[0].status != noReason) && (p[1].status != noReason))
		{
			winner = 0;
		}
		if (p[0].status == noReason)
		{
			winner = 1;
		}
		if (p[1].status == noReason)
		{
			winner = 2;
		}
	}
	/*
	if (p[0].win &&p[1].win)
	{
		winner = 0; //The game is over and the two player win, this mean tie
		over = true;
	}
	else if (p[0].win)
	{
		winner = 1; //The game is over and player 1 win
		over = true;
	}
	else if (p[1].win)
	{
		winner = 2; //The game is over and player 2 win
		over = true;
	}
	*/
}

void TheGame::printToScreen()
{
	int i;
	gotoxy(1, 23);
	for (i = 0; i < numOfPlayers; i++)
	{
		cout << "\nThe Errors of player number " << i + 1 << ": ";
		p[i].setColor(WHITE);
		p[i].printError();
	}
}
void TheGame::run()
{
	int moveNum = 0;
	init();
	checkForWinner();
	if (!over)
	{
		drawGameBoard();
	}
	while (over == false)
	{
		move(moveNum++);
		//checkForWinner();
	}
	printToScreen();
	createOutputFile();
}

void TheGame::move(int moveNum)
{
	int i, j;
	int newX = 0, newY = 0, oldX = 0, oldY = 0, jokerX = 0, jokerY = 0;
	char newJokerType = '-';
	//bool isValid = true;
	if ((p[0].numOfMoves < moveNum) && (p[1].numOfMoves < moveNum))
	{
		over = true;
		p[0].status = p[1].status = moveFilesDone;
		//checkForWinner();

	}
	for (i = 0; i < numOfPlayers && !over; i++)
	{
		newJokerType = '-';
		if (p[i].move(moveNum, newX, newY, oldX, oldY, jokerX, jokerY, newJokerType))
		{
			if (newJokerType != '-')//means the player wants to change the joker.
			{
				gameBoard[jokerX][jokerY].setPieceType(newJokerType);
			}
			movePiece(oldX, oldY, newX, newY, i);

		}
		

			checkForWinner();
			//the printing is just for cheaking
			/*
			cout << "\n"<< "Move File" << "\n";
			cout << "----The player number " << 1 << " -----\n";
			cout << "the status: " << p[0].status << "\n";
			cout << "the error: " << p[0].error << "\n";
			cout << "the error line: " << p[0].errorLine << "\n";
			cout << "----The player number " << 2 << " -----\n";
			cout << "the status: " << p[1].status << "\n";
			cout << "the error: " << p[1].error << "\n";
			cout << "the error line: " << p[1].errorLine << "\n";
			*/
		

	}


}

void TheGame::movePiece(const int & oldX, const int & oldY, const int & newX, const int & newY, int playerNum)
{
	int fightRes = -1;
	if (gameBoard[newX][newY].getPieceType() != '-')//there is a piece already in this place - fight!
	{
		fightRes = pieceFight(newX, newY);
		setFightResult(fightRes, newX, newY);
	}
	else
	{
		gameBoard[newX][newY].setPieceType(gameBoard[oldX][oldY].getPieceType());
		gameBoard[oldX][oldY].setPieceType('-');
	}
	if (showMode != QUIET_MODE)
	{
		drawPiece(oldX, oldY, newX, newY, playerNum,fightRes);
	}
}

void TheGame::drawPiece(const int & oldX, const int & oldY, const int & newX, const int & newY, int playerNum,int fightResult)
{
	int secondPlayerIndex = abs(playerNum -1);
	if (showMode == SHOWALL_MODE)
	{
		if (fightResult != -1) {
			if (fightResult == TIE)
			{
				p[playerNum].playerBoard[oldX][oldY].removePiece(oldX, oldY);
				p[secondPlayerIndex].playerBoard[newX][newY].removePiece(newX, newY);
			}
			else if (fightResult - 1 == playerNum)
			{
				p[playerNum].playerBoard[oldX][oldY].removePiece(oldX, oldY);
				p[playerNum].playerBoard[newX][newY].drawPiece(p[playerNum].color, newX, newY);
			}
			else
			{
				p[playerNum].playerBoard[oldX][oldY].removePiece(oldX, oldY);
			}
		}
		else
		{
			p[playerNum].playerBoard[oldX][oldY].removePiece(oldX, oldY);
			p[playerNum].playerBoard[newX][newY].drawPiece(p[playerNum].color, newX, newY);
		}
	}
	else if (showMode == playerNum)
	{
		if (fightResult != -1) {
			if (fightResult - 1 == playerNum)
			{
				p[playerNum].playerBoard[oldX][oldY].removePiece(oldX, oldY);
				p[playerNum].playerBoard[newX][newY].drawPiece(p[playerNum].color, newX, newY);
			}
			else
			{
				p[playerNum].playerBoard[oldX][oldY].removePiece(oldX, oldY);
			}
		}
		else
		{
			p[playerNum].playerBoard[oldX][oldY].removePiece(oldX, oldY);
			p[playerNum].playerBoard[newX][newY].drawPiece(p[playerNum].color, newX, newY);
		}
	}
	else {
		if (!(fightResult - 1 == secondPlayerIndex))
		{
			p[secondPlayerIndex].playerBoard[newX][newY].removePiece(newX, newY);
		}

	}
}

void TheGame::drawGameBoard()
{
	drawBoardLines();
	int player = showMode != 1 ? 0 : 1;
	int maxPlayerToPrint = showMode >= 1 ? numOfPlayers : 1;
	for (; player < maxPlayerToPrint; player++) {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (p[player].playerBoard[i][j].getPieceType() != '-')
				{
					if (showOnlyKnownInfo)
						p[player].playerBoard[i][j].drawUnknownPiece(p[player].color, i, j);
					else
						p[player].playerBoard[i][j].drawPiece(p[player].color, i, j);
				}
			}
		}
	}
}

void TheGame::createOutputFile()
{
	ofstream outfile("output.txt");
	if (outfile.is_open())
	{
		outfile << "Winner: " << winner << "\n";
		outfile << "Reason: " ;
		if (winner == 1)
		{
			outfile << p[1].returnReason();
			if ((p[1].status == badPosition) || (p[1].status == badMoves))
			{
				outfile << "player 2 line " << p[1].errorLine;
			}
		}

		else if (winner == 2)
		{
			outfile << p[1].returnReason();
			if ((p[0].status == badPosition) || (p[0].status == badMoves))
			{
				outfile << "player 1 line " << p[0].errorLine;
			}
		}
		else if (winner == 0)
		{
			if (p[0].status == p[1].status)
			{
				if (p[0].status==badPosition)
					outfile << "Bad Positioning input file for both players- player 1: line" << p[0].errorLine << ", player 2: line " << p[1].errorLine;
				if (p[0].status == moveFilesDone)
					outfile << "A tie - both Moves input files done without a winner";
			}
		
			else
			{
				outfile << p[0].returnReason();
				if ((p[0].status == badPosition) || (p[0].status == badMoves))
				{
					outfile << " player 1 line " << p[0].errorLine;
				}
				outfile << p[1].returnReason();
				if ((p[1].status == badPosition) || (p[1].status == badMoves))
				{
					outfile << " player 2 line " << p[1].errorLine;
				}
			}
		}
		outfile << "\n\n";
		for (int j = 1; j < 11; j++)
		{
			outfile << "|";
			for (int i = 1; i < 11; i++)
			{
				if (gameBoard[i][j].getPieceType() != '-')
				{
					outfile << " " << gameBoard[i][j].getPieceType() << " |";
				}
				else
					outfile << "   |";
			}
			outfile << "\n";
		}
		outfile.close();
	}
	else {
		//file error
	}
}
void TheGame::drawBoardLines()
{
	for (int j = 1; j < 11; j++)
	{
		for (int i = 1; i < 11; i++)
		{
			gotoxy(i * 3 - 2, j * 2);
			cout << "|";
			gotoxy(i * 3 + 2, j * 2);
			cout << "|";
		}
	}
}

