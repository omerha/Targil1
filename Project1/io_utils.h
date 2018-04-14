#pragma once

// you must have a config file, both for windows and for compiling on Linux (MAMA)
// BUT, you need to change the content of the config!
#include "config.h"
#include "Color.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
class OriginalColors
{
	HANDLE hConsoleHandle;
	CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo;
	WORD saveOriginalColors;
public:
	OriginalColors()
	{
		HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
		GetConsoleScreenBufferInfo(hConsoleHandle, ConsoleInfo);
		saveOriginalColors = ConsoleInfo->wAttributes;
	}
	~OriginalColors()
	{
		SetConsoleTextAttribute(hConsoleHandle, saveOriginalColors);
	}
};
void gotoxy(int x, int y);
void setTextColor(Color color);
void setTextbBackground(Color colorToSet);
void hideCursor();
void clear_screen();
void setTextRemoveColor(Color color);
#ifndef WINDOWS	
	int _getch(void);
	int _kbhit(void);
	void Sleep(unsigned long);
#else
	#include <stdlib.h>
	#include <conio.h>
	#include <windows.h>
#endif