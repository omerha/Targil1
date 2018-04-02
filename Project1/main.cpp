#include <windows.h>
#include <iostream>
using namespace std;

#include "TheGame.h"
#include "Player.h"


int main(int argc,char* argv[])
 {
	Player player1("test.txt");
	player1.readFromFile();
}