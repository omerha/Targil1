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

Player::Player(string vStartGameFile, string vMovesFile, int nPlayer) //Constructor
{

	status = noReason;
	startGameFile = vStartGameFile;
	movesFile = vMovesFile;
	// Need to complete numOfMovingPieces =
	//playerNum = nPlayer;
	for (int i = 0; i < 6; i++)
		counterPieces[i] = 0;
	putMovesFileInStringArr();
	error = noError;
	errorLine = 0;
	win = false;
}

void Player::checkForCorrectType(char type)
{
	if ((type != 'R') && (type != 'P') && (type != 'S') && (type != 'B') && (type != 'F'))
	{
		status = badPosition;
		error = unKnownPiece;
	}
}
string* Player::parseLine(string line, int& size)
{
	string tmpRead, temp;
	istringstream tempCh(line);
	int inputIndex = 0;
	string getInput[20] = { "0" };
	while (getline(tempCh, temp, ' '))
	{
		getInput[inputIndex++] = temp;
		//splitLineStatus = true;
	}
	string* out = new string[inputIndex];
	for(int i=0;i<inputIndex;i++)
		out[i] = getInput[i];
	
	size = inputIndex;
	return out;
}
void Player::putMovesFileInStringArr()
{
	int numOfRows = 0;
	string tmpReadFile;
	ifstream inFile(this->movesFile);
	while (!inFile.eof() && inFile)
	{
		if (getline(inFile, tmpReadFile))
		{
			movesArr[numOfRows++] = tmpReadFile;
		}
		else
		{
			cout << "error in moves file";
			//TODO: add relevant error;
		}
	}
	numOfMoves = numOfRows;
}
bool Player::move(int moveNum, int& newXLocation, int& newYLocation, int& oldXLocation, int& oldYLocation, int& jokerXLocation, int& jokerYLocation, char& newJokerType)
{
	string* currInput = nullptr;
	int numOfIndex = 0;
	int currX = 0, currY = 0, newX = 0, newY = 0;
	if (moveNum < numOfMoves)
	{
		currInput = parseLine(movesArr[moveNum], numOfIndex);
		if (numOfIndex < 3 || numOfIndex>7)
		{
			error = errorInMoveFiles;//TODO: error - too many or too few arguments in line.
			errorLine = moveNum;
			return false;
		}
		currX = stoi(currInput[0]);
		currY = stoi(currInput[1]);
		newX = stoi(currInput[2]);
		newY = stoi(currInput[3]);
		if (!(checkXYInRange(currX, 'X') || checkXYInRange(newX, 'X') || checkXYInRange(newY, 'Y') || checkXYInRange(currY, 'Y')))
		{
			movePlayerError(moveNum);//TODO:error x y not in range.
			return false;
		}
		if (playerBoard[currX][currY].getPieceType() == '-')
		{
			movePlayerError(moveNum);//TODO:error the player is trying to move a piece that does not exist.
			return false;
		}
		if (numOfIndex > 6)//means there is a move for the joker.
		{
			if (currInput[4].length() == 2)
			{
				if (currInput[4][1] == 'J')
				{
					int xJoker = stoi(currInput[5]);
					int yJoker = stoi(currInput[6]);
					char nJokerType = currInput[7][0];
					if (!(checkXYInRange(xJoker, 'X') || checkXYInRange(yJoker, 'Y')))//Something is wrong with joker xy.
					{
						movePlayerError(moveNum);
						return false;
					}
					else if (playerBoard[xJoker][yJoker].getPieceJoker())
					{
						playerBoard[xJoker][yJoker].setPieceType(nJokerType);
						jokerXLocation = xJoker;
						jokerYLocation = yJoker;
						newJokerType = nJokerType;
					}
					else
					{
						movePlayerError(moveNum);
						return false;
					}
				}
				else
				{
					movePlayerError(moveNum);
					return false;
				}
			}
			else// I am assuming that the joker is written like this - [J:
			{
			movePlayerError(moveNum);//TODO:something is wrong with the line..
			return false;
			}
		}
		playerBoard[newX][newY].setPieceType(playerBoard[currX][currY].getPieceType());
		playerBoard[currX][currY].setPieceType('-');
		oldXLocation = currX;
		oldYLocation = currY;
		newXLocation = newX;
		newYLocation = newY;
		return true;
	}
	else {
		error = errorInMoveFiles;
	}
	delete[] currInput;
}
void Player::movePlayerError(int lineNum)
{
	error = errorInMoveFiles;
	errorLine = lineNum;
}

void Player::readFromFile()
{
	bool illegalFile = false;
	int numOfRows = 0, inputIndex = 0;
	string tmpRead;
	string* getInput =nullptr;
	ifstream inFile(this->startGameFile);
	int xLocation, yLocation;
	char type;
	while (!inFile.eof() && !illegalFile && inFile)
	{
		numOfRows++;
		if (numOfRows > K)
		{
			this->status = badPosition;
			error = tooManyRows;
			illegalFile = true;
			return;
		}
		else if (getline(inFile, tmpRead))
		{
			inputIndex = 0;
		    getInput = parseLine(tmpRead, inputIndex);
			if (inputIndex>=3)
			{
				type = getInput[0][0];
				xLocation = stoi(getInput[1]);
				
				yLocation = stoi(getInput[2]);
				
				if (!(checkXYInRange(yLocation, 'Y') || checkXYInRange(xLocation, 'X')))
				{
					errorLine = numOfRows;
					return;
				}
				if (this->playerBoard[xLocation][yLocation].getPieceType() != '-') // There is a piece in this location
				{
					status = badPosition;
					errorLine = numOfRows;
					return;
				}
				this->playerBoard[xLocation][yLocation].setPieceX(xLocation);
				this->playerBoard[xLocation][yLocation].setPieceY(yLocation);

				if (getInput[0][0] == 'J')
				{
					if (inputIndex == 4)
					{
						playerBoard[xLocation][yLocation].setPieceJoker(true);
						type = getInput[3][0];
					}
					else
					{
						status = badPosition;
						errorLine = numOfRows;
						return;//wrong input of joker
					}
				}
				checkForCorrectType(type);
				//If the piece type isn't one of the pieces in the game
				if (status != noReason)
				{
					errorLine = numOfRows;
					return;
				}
				this->playerBoard[xLocation][yLocation].setPieceType(type);
				//this->playerPieces[numOfPieces].setPiecePlayerNum(this->playerNum);
				countPieces(type);
			}
			else
				cout << "error input";
			//error spliting line
		}
		else
			cout << "error input";
		//error input
		delete[] getInput;
	}
	if (numOfRows == 0)
	{
		//File is empty = add relevatn error.
	}
}





void Player::checkValidityiPieces()
{


	if (counterPieces[P] > NUM_OF_PAPER || counterPieces[R] > NUM_OF_ROCK || counterPieces[B] > NUM_OF_BOMB || counterPieces[J] > NUM_OF_JOKER ||
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
}

void removePiece()
{

}
void Player::countPieces(char type)
{
	switch (type)
	{
	case 'R':
		counterPieces[R] += 1;
		break;
	case 'P':
		counterPieces[P] += 1;
		break;
	case 'B':
		counterPieces[B] += 1;
		break;
	case 'J':
		counterPieces[J] += 1;
		break;
	case 'F':
		counterPieces[F] += 1;
		break;
	case 'S':
		counterPieces[S] += 1;
		break;
	}

}

bool Player::checkXYInRange(int num,char cord)
{
	if (cord == 'X')
	{
		if (num < 1 || num>10) // X coordinate isn't inrange
		{
			status = badPosition;
			return false;
		}
	}
	if (cord == 'Y')
	{
		if (num < 1 || num>10) // X coordinate isn't inrange
		{
			status = badPosition;
			return false;
		}
	}
	return true;
}
