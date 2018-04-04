#include "Player.h"

using namespace std;

/*
void Player::setBoard()
{
	int i;
	int xCoordinate, yCoordinate;
	char type;

	for (i = 0; i < K; i++)
	{
		xCoordinate = this->playerPieces[i].x;
		yCoordinate = this->playerPieces[i].y;
		type = xCoordinate = this->playerPieces[i].pieceType;
		if (this->playerBoard[xCoordinate - 1][yCoordinate - 1] != '-')
		{
			this->status = badPosition;
			return;
		}
		else this->playerBoard[xCoordinate-1][yCoordinate-1] = type;
	}
	
}
*/

void Player::readFromFile()
{
	bool illegalFile = false;
	int numOfPieces = 0;
	string tmpRead;
	ifstream inFile(this->fileName);
	while (!inFile.eof()&& ! illegalFile)
	{
		if (numOfPieces > 9)
		{
			this->status = badPosition;
			illegalFile = true;
			return;
		}
		else 
		{
			getline(inFile, tmpRead);
			this->playerPieces[numOfPieces].initPiece(tmpRead);

			this->playerPieces[numOfPieces].setPiecePlayerNum(this->playerNum);
			if (this->status != noReason)
				return;
			numOfPieces++;

		}


	}
	
}



Player::Player(string vFileName, int nPlayer) //Constructor
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			playerBoard[i][j] = '-';
		}
	}
	status = noReason;
	fileName = vFileName;
	// Need to complete numOfMovingPieces =
	playerNum = nPlayer;
}

void Player::checkValidityiPieces()
{
	int nPieces[6];
	int i;
	char type;
	for (i = 0; i < K; i++)
	{
		type = this->playerPieces[i].getPieceType();
		nPieces[type] += 1;
		/*
		switch (type)
		{
		case 'R':
			nPieces[R] += 1;
			break;
		case 'P':
			nPieces[P] += 1;
			break;
		case 'B':
			nPieces[B] += 1;
			break;
		case 'J':
			nPieces[J] += 1;
			break;
		case 'F':
			nPieces[F] += 1;
			break;
		case 'S':
			nPieces[S] += 1;
			break;
		}
		*/
	}

	if (nPieces[P] > NUM_OF_PAPER || nPieces[R] > NUM_OF_ROCK || nPieces[B] > NUM_OF_BOMB || nPieces[J] > NUM_OF_JOKER ||
		nPieces[S] > NUM_OF_SCISSORS || nPieces[F] > NUM_OF_FLAG)
	{
		this->status = badPosition; //-	A PIECE type appears in file more than its number or missing flags
		//error = "Too many pieces from the same type" or 
		
	}
	return;
}

void removePiece()
{

}