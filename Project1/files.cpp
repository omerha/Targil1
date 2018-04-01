#include "files.h"

using namespace std;
void Player::readFromFile()
{
	//bool fEOF = false;
	int illegalFile = 0;
	int numOfPieces = 0;
	string tmpRead;
	ifstream inFile(fileName);
	while (illegalFile == 0)
	{
		getline(inFile, tmpRead);
		initBoard(tmpRead, illegalFile);
		if (inFile.eof() && illegalFile != 0)//Checking if we got any other error from initboard function.
		{
			illegalFile= 1; // ERROR - reach to end of file
		}

		numOfPieces++;

	}
	//TODO: create function that checking if there is flag- else return reasun
	
}
void Player::initBoard(string line, int& illegalFile)
{
	istringstream tempCh(line);
	int xLocation;
	int yLocation;
	char pieceType;
	string temp;
	//TODO: change to get from one long string without spaces. -- Leave as it is for now.
	getline(tempCh, temp, ' ');
	pieceType = temp[0];
	if (checkNumOfPieces(illegalFile, pieceType))
		return;
	getline(tempCh, temp, ' ');
	xLocation = stoi(temp);
	getline(tempCh, temp, ' ');
	yLocation = stoi(temp);

	//TODO chack if x and y is between 1-10- else return reasun
	if (board[xLocation-1][yLocation-1] != '-')
	{
		illegalFile = 2;//Bad Positioning input file for player <player> - line <bad line number>
		//------- Need to add param for the position of the error

		return;
	}
	board[xLocation-1][yLocation-1] = pieceType;
		//TODO: string check to make sure all the chars are valid + add joker
		
	
}



Player::Player(string vFileName)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			board[i][j] = '-';
		}
	}
	for( i = 0;i<counter;i++)
	{
		nPieces[i] = 0;
	}
	fileName = vFileName;
}

bool Player::checkNumOfPieces(int& illegalFile,char type)
{
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
	if (nPieces[P] > MAX_PAPER || nPieces[R] > MAX_ROCK || nPieces[B] > MAX_BOMB || nPieces[J] > MAX_JOKER ||
		nPieces[S] > MAX_SCISSORS || nPieces[F] > MAX_FLAG)
	{
		illegalFile = 3;
		error = "Too many pieces from the same type";
		return true;
	}
	return false;
}