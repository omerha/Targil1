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

Player::Player(string vFileName, int nPlayer) //Constructor
{

	status = noReason;
	fileName = vFileName;
	// Need to complete numOfMovingPieces =
	//playerNum = nPlayer;
	for (int i = 0; i < 6; i++)
		counterPieces[i] = 0;
	error= noError;
	errorLine = 0;
}

void Player::readFromFile()
{
	bool illegalFile = false;
	int numOfRows = 1;
	string tmpRead, temp;
	ifstream inFile(this->fileName);
	istringstream tempCh(tmpRead);  //what's the meaning of this?
	char type;
	int xLocation, yLocation;


	while (!inFile.eof()&& ! illegalFile)
	{
		if (numOfRows > K)
		{
			this->status = badPosition;
			error = tooManyRows;
			illegalFile = true;
			return;
		}
		else 
		{
			getline(inFile, tmpRead);

			//inFile.getline(temp, 128); //why this isn't working??

			/////////////////////////////////////////////
			getline(tempCh, temp, ' ');
			type = temp[0];


			getline(tempCh, temp, ' ');
			xLocation = stoi(temp);
			if (xLocation < 1 && xLocation>10) // X coordinate isn't inrange
			{
				status = badPosition;
				errorLine = numOfRows;
				return;
			}
			getline(tempCh, temp, ' ');
			yLocation = stoi(temp);
			if (yLocation < 1 && yLocation>10) // Y coordinate isn't inrange
			{
				status = badPosition;
				errorLine = numOfRows;
				return;
			}

			if (this->playerBoard[xLocation][yLocation].getPieceType != '-') // There is a piece in this location
			{
				status = badPosition;
				errorLine = numOfRows;
				return;
			}
			this->playerBoard[xLocation][yLocation].setPieceX(xLocation);
			this->playerBoard[xLocation][yLocation].setPieceY(yLocation);

			if (type == 'J')
			{
				playerBoard[xLocation][yLocation].setPieceJoker(true);
				getline(tempCh, temp, ' ');
				type = temp[0];

			}


			//If the piece type isn't one of the pieces in the game
			if ((type != 'R') && (type != 'P') && (type != 'S') && (type != 'B') && (type != 'F'))
			{
				status = badPosition;
				error = unKnownPiece;
				errorLine = numOfRows;
				return;
			}
			this->playerBoard[xLocation][yLocation].setPieceType(type);


			//this->playerPieces[numOfPieces].setPiecePlayerNum(this->playerNum);

			counterPieces[type]++; //if this isn't work- we need to do switch case
			numOfRows++;
		}


	}
	
}





void Player::checkValidityiPieces()
{


	if (counterPieces[P] > NUM_OF_PAPER || counterPieces[R] > NUM_OF_ROCK ||  counterPieces[B] > NUM_OF_BOMB || counterPieces[J] > NUM_OF_JOKER ||
		counterPieces[S] > NUM_OF_SCISSORS || counterPieces[F] > NUM_OF_FLAG)
	{
		this->status = badPosition; //-	A PIECE type appears in file more than its number
		error = tooManyPieces;
		
	}
	if (counterPieces[F] != 1)
	{
		this->status = badPosition;// missing flag
		error = noFlag;
	}
	

	return;
}

void removePiece()
{

}