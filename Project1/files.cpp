#include "files.h"

using namespace std;
char** Player::readFromFile(string fileName)
{
	//bool fEOF = false;
	int illegalFile = 0;
	int numOfPieces = 0;
	char board[M][N];
	int counterPieces[typePieces] = {0,0,0,0,0,0};//TODO: initilize outside/
	string tmpRead;
	ifstream inFile(fileName);
	while (illegalFile)
	{
		getline(inFile, tmpRead);
		initBoard(tmpRead, board, illegalFile, counterPieces);
		if (inFile.eof())
		{
			illegalFile= 1; //reach to end of file
		}

		numOfPieces++;

	}
	//TODO: create function that checking if there is flag- else return reasun
	return bo ard;
}
void Player::initBoard(string line, char board[N][M], int& illegalFile, int* counterPieces)
{
	istringstream tempCh(line);
	int xLocation;
	int yLocation;
	char pieceType;
	string temp;
	//TODO: change to get from one long string without spaces.
	getline(tempCh, temp, ' ');
	pieceType = temp[0];
	getline(tempCh, temp, ' ');
	xLocation = stoi(temp);
	getline(tempCh, temp, ' ');
	yLocation = stoi(temp);
	//counterPieces[pieceType +1] = TODO: need to figure out how to count the pieces.


	//ToDo: create funcrion to make sure there arn't extra pices from the same type

	//TODO chack if x and y is between 1-10- else return reasun
	if (board[xLocation][yLocation] != NULL)
	{
		illegalFile = 2;//Bad Positioning input file for player <player> - line <bad line number>
		//------- Need to add param for the position of the error

		return;
	}
	board[xLocation][yLocation] = pieceType;
		//TODO: string check to make sure all the chars are valid + add joker
		
	
}

void Player::initilizeBoard(char board[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			board[N][M] = NULL;
		}
	}
}