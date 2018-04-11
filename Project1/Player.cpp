#include "Player.h"

using namespace std;


Player::Player() //Constructor
{
	status = noReason;
	for (int i = 0; i < 6; i++)
		counterPieces[i] = 0;
	error = noError;
	errorLine = 0;
}

void Player::checkForCorrectType(char type, int numOfRow)
{
	if ((type != 'R') && (type != 'P') && (type != 'S') && (type != 'B') && (type != 'F'))
	{
		setPlayerStatus(badPosition, unKnownPiece, numOfRow);
	}
}
string* Player::parseLine(string line, int& size,int lineNum,Error error)
{
	string tmpRead, temp;
	istringstream tempCh(line);
	int inputIndex = 0;
	string getInput[20] = { "0" };
	while (getline(tempCh, temp, ' '))
	{
		if(!(temp.empty()))
		getInput[inputIndex++] = temp;
	}
	if (inputIndex)
	{
		string* out = new string[inputIndex];
		for (int i = 0; i < inputIndex; i++)
		{
			if (getInput[i].length() >= 2)
			{
				if (getInput[i].length() > 2 || (!(isdigit(getInput[i][0]) && isdigit(getInput[i][1])) && getInput[i][0] != 'J'))
					setPlayerStatus(badPosition, error, lineNum);
			}
			else if (getInput[i].empty())
				setPlayerStatus(badPosition, error, lineNum);
			out[i] = getInput[i];
		}
		size = inputIndex;
		return out;
	}
	else
		return nullptr;
}
void Player::putMovesFileInStringArr()
{
	bool illegalFile = false;
	int numOfRows = 0;
	string tmpReadFile;
	ifstream inFile(this->movesFile);
	if (inFile.fail())
	{
		//need to check if its legal to not having moves file.
		illegalFile = true;
	}
	while (!inFile.eof() && !illegalFile)
	{
		if (getline(inFile, tmpReadFile))
		{
			if(!(tmpReadFile.empty()))
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
		currInput = parseLine(movesArr[moveNum], numOfIndex, moveNum, wrongFrormatRowMoveFile);
		if (numOfIndex < 4 || numOfIndex>8)
		{
			setPlayerStatus(badMoves, wrongFrormatRowMoveFile, moveNum); //error - too many or too few arguments in line.
			return false;
		}
		if (isdigit(currInput[0][0]) && isdigit(currInput[1][0]) && isdigit(currInput[2][0]) && isdigit(currInput[3][0]))
		{
			currX = stoi(currInput[0]);
			currY = stoi(currInput[1]);
			newX = stoi(currInput[2]);
			newY = stoi(currInput[3]);
		}
		else
		{
			setPlayerStatus(badMoves, wrongFrormatRowMoveFile, moveNum); 
			return false;
		}
		if (!(checkXYInRange(currX, 'X') && checkXYInRange(newX, 'X') && checkXYInRange(newY, 'Y') && checkXYInRange(currY, 'Y')))
		{
			setPlayerStatus(badMoves, notInRange, moveNum); //error x y not in range.
			return false;
		}
		if (checkMoveisLegal(currX, currY, newX, newY, playerBoard[currX][currY].getPieceType()))
		{
			setPlayerStatus(badMoves, moveIllegal, moveNum);
			return false;
		}
		if (playerBoard[currX][currY].getPieceType() == '-')
		{
			setPlayerStatus(badMoves, notExistPiece, moveNum); //error the player is trying to move a piece that does not exist.
			return false;
		}
		if (numOfIndex > 6)//means there is a move for the joker. 
		{
			if (currInput[4].length() == 2)
			{
				if (currInput[4][0] == 'J')
				{
					int xJoker = stoi(currInput[5]);
					int yJoker = stoi(currInput[6]);
					char nJokerType = currInput[7][0];
					if (!(checkXYInRange(xJoker, 'X') || checkXYInRange(yJoker, 'Y')))//Something is wrong with joker xy. //Guy- this mean joker not in range?
					{
						setPlayerStatus(badMoves, notInRange, moveNum);
						return false;
					}
					else if (playerBoard[currX][currY].getPieceJoker())
					{
						if ((nJokerType != 'P') && (nJokerType != 'R') && (nJokerType != 'S') && (nJokerType != 'B'))
						{
							setPlayerStatus(badMoves, wrongInputJoker, moveNum);
							return false;
						}
						else
						{
						//	playerBoard[newX][newY].setPieceJoker(true);
						//	playerBoard[xJoker][yJoker].setPieceType(nJokerType);
							jokerXLocation = xJoker;
							jokerYLocation = yJoker;
							newJokerType = nJokerType;
						}

					}
					else
					{
						setPlayerStatus(badMoves, notExistJoker, moveNum); //Error- not exit joker in this location
						//movePlayerError(moveNum);
						return false;
					}
				}
				else //The wrong is for example: "K:" insted of "J:"
				{
					setPlayerStatus(badMoves, wrongFrormatRowMoveFile, moveNum);
					return false;
				}
			}
			else //The wrong, for example: "J::" insted of "J:"
			{
				setPlayerStatus(badMoves, wrongFrormatRowMoveFile, moveNum);
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
	delete[] currInput;
}


void Player::setPlayerStatus(Reason reason, Error theError, int line) 
{
	status = reason;
	error = theError;
	errorLine = line;
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
	if (inFile.fail())
	{
		setPlayerStatus(badPosition, notExistFile, 0);
		illegalFile = true;
		return;
	}
	while (!inFile.eof() && !illegalFile )
	{
		numOfRows++;
		if (numOfRows > K)
		{
			setPlayerStatus(badPosition, tooManyRows, 0);
			illegalFile = true;
			return;
		}
		else if (getline(inFile, tmpRead))
		{
			inputIndex = 0;
			getInput = parseLine(tmpRead, inputIndex, numOfRows, wrongFormatRowInputFile);
			if ((inputIndex == 3) || (inputIndex == 4))
			{

				type = getInput[0][0];
				if (isdigit(getInput[1][0]) && isdigit(getInput[2][0]))
				{
					xLocation = stoi(getInput[1]);
					yLocation = stoi(getInput[2]);
				}
				else
				{
					setPlayerStatus(badPosition, wrongFormatRowInputFile, numOfRows);
					return;
				}
				if (!(checkXYInRange(yLocation, 'Y') && checkXYInRange(xLocation, 'X')))
				{
					setPlayerStatus(badPosition, notInRange, numOfRows);
					return;
				}
				if (this->playerBoard[xLocation][yLocation].getPieceType() != '-') // There is a piece in this location
				{
					setPlayerStatus(badPosition, sameLocation, numOfRows);
					return;
				}
				this->playerBoard[xLocation][yLocation].setPieceX(xLocation);
				this->playerBoard[xLocation][yLocation].setPieceY(yLocation);
			}
			else
			{
				if (inputIndex) {
					setPlayerStatus(badPosition, wrongFormatRowInputFile, numOfRows); // the length line isn't 3 or 4 chars
					return;
				}
			}
			if (inputIndex == 4)
			{
				if (getInput[0][0] == 'J')
				{
					playerBoard[xLocation][yLocation].setPieceJoker(true);
					countPieces('J');
					type = getInput[3][0];
					if ((type != 'P') && (type != 'R') && (type != 'S') && (type != 'B'))
					{
						setPlayerStatus(badPosition, unKnownPieceForJoker, numOfRows);
						return;
					}
					else playerBoard[xLocation][yLocation].setPieceType(type);

				}
				else
				{
					setPlayerStatus(badPosition, unKnownPiece, numOfRows);
					return;

				}
			}
			else if(inputIndex == 3)
			{
				checkForCorrectType(type, numOfRows);
				if (status == noReason)
				{
					playerBoard[xLocation][yLocation].setPieceType(type);
					countPieces(type);
				}
				else // //If the piece type isn't one of the pieces in the game
				{
					setPlayerStatus(badPosition, unKnownPiece, numOfRows);
					return;
				}

			}
			if ((inputIndex == 0) && (numOfMoves == 1)) /////////////////Not working!
			{
				setPlayerStatus(badPosition, emptyFile, numOfRows); //File is empty 
				return;
			}

				
				
	

		}

	}

	if (numOfRows == 0)
			setPlayerStatus(badPosition, wrongFormatRowInputFile, numOfRows); // error input
	if (!tmpRead.empty())
		delete[] getInput;
}






void Player::checkValidityiPieces()
{
	//The print is just for checking how many pieces each type there is for the each player
	//cout << "CounterPieces P:" << counterPieces[P] << " R:" << counterPieces[R] << " B:" << counterPieces[B] << " S:" << counterPieces[S] << " F:" << counterPieces[F] << " J:" << counterPieces[J] << "\n";
	if (counterPieces[P] > NUM_OF_PAPER || counterPieces[R] > NUM_OF_ROCK || counterPieces[B] > NUM_OF_BOMB || counterPieces[J] > NUM_OF_JOKER ||
		counterPieces[S] > NUM_OF_SCISSORS || counterPieces[F] > NUM_OF_FLAG)
	{
		setPlayerStatus(badPosition, tooManyPieces, 0); //-	A PIECE type appears in file more than its number

	}
	if (counterPieces[F] < 1)
	{
		setPlayerStatus(badPosition, noFlag, 0); // Missing flag
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
			//status = badPosition;
			return false;
		}
	}
	if (cord == 'Y')
	{
		if (num < 1 || num>10) // X coordinate isn't inrange
		{
			//status = badPosition;
			return false;
		}
	}
	return true;
}

void Player::printError()
{
	switch (error)
	{
	case 1:
		if (status == badPosition)
			cout << "The coordinates in line:" << errorLine << " in the input file not in the range of the board\n";
		else
			cout << "The coordinates in line:" << errorLine << " in the input file not in the range of the board\n";
		break;
	case 2:
		cout << "The coordinates that inseted in line:" << errorLine << " in the input file already have a piece in the board\n";
		break;
	case 3:
		cout << "Too many pieces of the same type were inserted in the input file\n";
		break;
	case 4:
		cout << "No flag was inserted in the input file\n";
		break;
	case 5:
		cout << "Unknow piece was inserted in line:" << errorLine << " in the input file\n";
		break;
	case 6:
		cout << "Too many rows inserted in the input file in line:" << errorLine << "\n";
		break;
	case 7:
		cout << "The format of row " << errorLine << " in the input file is invalid\n";
		break;
	case 8:
		cout << "The format of row " << errorLine << " in the move file is invalid\n";
		break;
	case 9:
		cout << "Piece not exist in the place that inserted in line " << errorLine << " in the move file\n";
		break;
	case 10:
		cout << "Joker not exist in the place that inserted in line " << errorLine << " in the move file\n";
		break;
	case 11:
		cout << "Joker changed in row" << errorLine << " into a piece that didn't exist in the move file \n";
		break;
	case 12:
		cout << "The input file is empty\n";
		break;
	case 13:
		cout << "Move a piece in an illegal way in line " << errorLine << " in the move file \n";
		break;
	case 14:
		cout << "Not exsit file";
		break;
	case 15:
		cout << "Unknow piece was inserted for joker in line:" << errorLine << " in the input file\n";
		break;
	default:
		cout << "Not exsit errors to this player\n";
		break;
	}
}

string Player::returnReason()
{
	switch (status)
	{
	case noReason:
		return "No reason";
		break;
	case flagsCaptured:
		return "All flags of the opponent are captured";
		break;
	case allEaten:
		return "All moving PIECEs of the opponent are eaten";
		break;
	case badPosition:
		return "Bad Positioning input file for ";
		break;
	case badMoves:
		return "Bad Moves input file for ";
		break;
	default:
		return "No reason";
		break;
	}
}

void Player::hideJoker()
{
	int counterJoker = 0;
	for (int i = 1; i <= N && counterJoker < counterPieces[J]; i++)
	{
		for (int j = 1; j <= M && counterJoker < counterPieces[J]; j++)
		{
			if (playerBoard[i][j].getPieceJoker())
			{
				playerBoard[i][j].setRevealJokerStatus(false);
				counterJoker++;
			}
		}
	}
}

bool Player::checkMoveisLegal(const int & currX, const int & currY, const int & newX, const int & newY,const char& type)
{
	if ((abs(currX - newX) > 1) || (abs(currY - newY) > 1))
		return true;
	else if (((abs(currX - newX) == 1) && (abs(currY - newY) == 1)) && ((currX != newX) && (currY != newY))) // check for cross
		return true;
	else if (type == 'B')
		return true;
	else
		return false;
}
