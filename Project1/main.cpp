#include <windows.h>
#include <iostream>
using namespace std;

#include "TheGame.h"
#include "Player.h"

bool isDigit(char* c);
void main(int argc,char* argv[])
 {
<<<<<<< HEAD
	TheGame theGame;
=======
	TheGame game;
>>>>>>> master
	int i;
	bool  showOnlyKnownInfo=false;
	int playerShow=3, timeToDelay=0;
	bool legal = true;
	for (i = 1; i < argc && legal; i++)
	{
		if (!strcmp(argv[i], "-quiet"))
			playerShow = 0;
		else if (!strcmp(argv[i], "-show-all"))
			playerShow = 3;
		else if (!strcmp(argv[i], "-show-only-know-info"))
			showOnlyKnownInfo = true;
		else if (!strcmp(argv[i], "-show"))
		{
			if (isDigit(argv[i + 1]))
			{
				playerShow = atoi(argv[i + 1]);
				i++;
			}
			else
				legal = false;
		}
		else if (!strcmp(argv[i], "-delay"))
		{
			if (isDigit(argv[i + 1]))
			{
				timeToDelay = atoi(argv[i + 1]);
				i++;
			}
			else
				legal = false;
		}
		else
			legal = false;
	}
	if (!legal)
		cout << "one of the arguments not legal";
	
	else if (!playerShow && (showOnlyKnownInfo || timeToDelay || playerShow))
		cout << "You can't insert presentation mode arguments and non-presentation mode arguments together";
	else
	{
		theGame.setDelayMode(timeToDelay);
		theGame.setShowMode(playerShow);
		theGame.setUnkownInfoMode(showOnlyKnownInfo);
	}
	/*if (!quiet && !showAll && !showInfo && !showPlayer) //	Default presentation mode is show-all
	{
		showAll = true;
		delay = true;
		if (timeToDelay = 0)
			timeToDelay = 50;
<<<<<<< HEAD
	}*/
		
=======
	}


	
	//game.init();
	game.run();
>>>>>>> master

	theGame.run();
}

bool isDigit(char* c)
{
	int len = strlen(c);
	for (int i = 0; i < len; i++)
		if (!('0' <= c[i] && c[i] <= '9'))
			return false;
	return true;
}