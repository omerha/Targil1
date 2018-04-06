#include <windows.h>
#include <iostream>
using namespace std;

#include "TheGame.h"
#include "Player.h"


void main(int argc,char* argv[])
 {
	
	int i;
	bool quiet=false, showAll=false, showInfo=false, showPlayer=false, delay=false;
	int playerShow=0, timeToDelay=0;
	bool legal = true;
	for (i = 1; i < argc && legal; i++)
	{
		
		if (argv[i] == "-quiet")
			quiet = true;
		else if (argv[i] == "-show-all")
			showAll = true;
		else if (argv[i] == "-show-only-know-info")
			showInfo = true;
		else if (argv[i] == "-show")
		{
			showPlayer = true;
			playerShow = (int)argv[i + 1];
			i++;
		}
		else if (argv[i] == "-delay")
		{
			delay = true;
			timeToDelay = (int)argv[i + 1];
			i++;
		}
	
		else legal = false;
	}
	if (!legal)
		cout << "one of the arguments not legal";
	
	else if (quiet && (showAll || showInfo || showPlayer || delay))
		cout << "You can't insert presentation mode arguments and non-presentation mode arguments together";

	if (!quiet && !showAll && !showInfo && !showPlayer) //	Default presentation mode is show-all
	{
		showAll = true;
		delay = true;
		if (timeToDelay = 0)
			timeToDelay = 50;
	}


	
	TheGame theGame;
	theGame.run();

	

}