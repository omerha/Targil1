//Written by:
//Omer Harel- 204059331
//Guy Bronshtein- 301002762


#include <windows.h>
#include <iostream>
using namespace std;

#include "Arguments.h"
#include "TheGame.h"
#include "Player.h"


int main(int argc,char* argv[])
 {
	TheGame game;
	argumentsToMain(argc, argv, game);
	
	game.run();
}

//Output Examples:

/*
-----Example number 1------
Output in the consul:
The Errors of player number 1: The format of line 13 in the input file is invalid
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Positioning input file for player 1 line 13
*/


/*
-----Example number 2------
Output in the consul:
The Errors of player number 1: The coordinates in line:9 in the input file are not in the range of the board
The Errors of player number 2: The format of line 7 in the input file is invalid

Output in the file:
Winner: 0
Reason: Bad Positioning input files for both players- player 1: line 9, player 2: line 7
*/


/*
-----Example number 3------
Output in the consul:
The Errors of player number 1: The format of line 5 in the input file is invalid
The Errors of player number 2: Unknow piece was inserted for joker in line:5 in the input file

Output in the file:
Winner: 0
Reason: Bad Positioning input files for both players- player 1: line 5, player 2: line 5
*/

/*
-----Example number 4------
Output in the consul:
The Errors of player number 1: Unknown piece was inserted in line:4 in the input file
The Errors of player number 2: The format of line 8 in the input file is invalid

Output in the file:
Winner: 0
Reason: Bad Positioning input files for both players- player 1: line 4, player 2: line 8
*/


/*
-----Example number 5------
Output in the consul:
The Errors of player number 1: Too many pieces of the same type were inserted in the input file
The Errors of player number 2: Too many pieces of the same type were inserted in the input file

Output in the file:
Winner: 0
Reason: Bad Positioning input files for both players- player 1: line 0, player 2: line 0
*/

/*
-----Example number 6------
Output in the consul:
The Errors of player number 1: No flag was inserted in the input file
The Errors of player number 2: No flag was inserted in the input file

Output in the file:
Winner: 0
Reason: Bad Positioning input files for both players- player 1: line 0, player 2: line 0
*/

/*
-----Example number 7------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |  |P |P |  |  |  |  |  |S |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |  |  |  |  |  |  |

4 |  |  |  |S |  |  |  |  |  |  |

5 |  |  |  |  |  |  |  |  |P |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |B |  |  |  |  |S |  |  |  |

8 |  |  |  |  |  |  |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|  |P |  |R |  |  |  |  |  |P |


The Errors of player number 1: There are no errors for this player
The Errors of player number 2: There is a piece in the place that inserted in line:7 in the move file

Output in the file:
Winner: 1
Reason: Bad Moves input file for player 2 line 7

|    | P  | P  |    |    |    |    |    | s  |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    | s  |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    | p  |    |
|    |    |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    | S  |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | p  |    | r  |    |    |    |    |    | p  |

*/

/*
-----Example number 8------
Output in the consul:
The Errors of player number 1: The coordinates inserted in line:4 in the input file already have a piece in the board
The Errors of player number 2: The coordinates inserted in line:5 in the input file already have a piece in the board

Output in the file:
Winner: 0
Reason: Bad Positioning input files for both players- player 1: line 4, player 2: line 5
*/

/*
-----Example number 9------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |P |P |P |  |  |  |  |F |S |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |B |  |  |  |  |  |

4 |  |P |R |P |  |P |  |  |  |  |

5 |  |  |  |  |  |  |  |R |  |P |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |B |  |  |  |  |S |  |  |  |

8 |  |  |  |  |  |F |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|R |  |  |R |  |  |  |  |  |P |


The Errors of player number 1: The format of row 4 in the move file is invalid
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 4

| p  | P  | P  |    |    |    |    | F  | s  |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    | b  |    |    |    |    |    |
|    | j  | R  | P  |    | P  |    |    |    |    |
|    |    |    |    |    |    |    | J  |    | p  |
|    |    |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    | S  |    |    |    |
|    |    |    |    |    | f  |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
| j  |    |    | r  |    |    |    |    |    | p  |

*/

/*
-----Example number 10------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |P |P |P |  |  |  |  |F |  |  |

2 |  |  |  |  |  |  |R |B |P |  |

3 |  |  |  |  |B |  |  |  |S |  |

4 |  |P |R |P |  |P |  |  |  |  |

5 |  |  |  |  |  |  |  |R |  |P |

6 |  |  |  |P |  |  |  |  |  |  |

7 |  |B |  |P |  |  |P |S |  |  |

8 |  |  |  |  |  |F |  |B |R |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|R |  |  |R |  |  |  |  |  |P |


The Errors of player number 1: The format of row 1 in the move file is invalid
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 1

| p  | P  | P  |    |    |    |    | F  |    |    |
|    |    |    |    |    |    | r  | B  | J  |    |
|    |    |    |    | b  |    |    |    | s  |    |
|    | j  | R  | P  |    | P  |    |    |    |    |
|    |    |    |    |    |    |    | J  |    | p  |
|    |    |    | P  |    |    |    |    |    |    |
|    | B  |    | p  |    |    | p  | S  |    |    |
|    |    |    |    |    | f  |    | b  | R  |    |
|    |    |    |    |    |    |    |    |    |    |
| j  |    |    | r  |    |    |    |    |    | p  |


*/

/*
-----Example number 11------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |P |P |P |  |  |  |  |F |S |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |B |  |  |  |  |  |

4 |  |P |R |P |  |P |  |  |  |  |

5 |  |  |  |  |  |  |  |R |  |P |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |B |  |  |  |  |S |  |  |  |

8 |  |  |  |  |  |F |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|R |  |  |R |  |  |  |  |  |P |


The Errors of player number 1: Joker has changed in line 4 in the move file into a piece that didn't exist
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 4

| p  | P  | P  |    |    |    |    | F  | s  |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    | b  |    |    |    |    |    |
|    | j  | R  | P  |    | P  |    |    |    |    |
|    |    |    |    |    |    |    | J  |    | p  |
|    |    |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    | S  |    |    |    |
|    |    |    |    |    | f  |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
| j  |    |    | r  |    |    |    |    |    | p  |

*/

/*
-----Example number 12------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |P |P |P |  |  |  |  |F |S |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |B |  |  |  |  |  |

4 |  |P |R |P |  |P |  |  |  |  |

5 |  |  |  |  |  |  |  |R |  |P |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |B |  |  |  |  |S |  |  |  |

8 |  |  |  |  |  |F |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|R |  |  |R |  |  |  |  |  |P |


The Errors of player number 1: The format of line 4 in the move file is invalid
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 4

| p  | P  | P  |    |    |    |    | F  | s  |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    | b  |    |    |    |    |    |
|    | j  | R  | P  |    | P  |    |    |    |    |
|    |    |    |    |    |    |    | J  |    | p  |
|    |    |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    | S  |    |    |    |
|    |    |    |    |    | f  |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
| j  |    |    | r  |    |    |    |    |    | p  |

*/


/*
-----Example number 13------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |P |P |P |  |  |  |  |F |S |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |B |  |  |  |  |  |

4 |  |P |R |P |  |P |  |  |  |  |

5 |  |  |  |  |  |  |  |R |  |P |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |B |  |  |  |  |S |  |  |  |

8 |  |  |  |  |  |F |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|R |  |  |R |  |  |  |  |  |P |


The Errors of player number 1: Joker does not exist in the place that inserted in line 4 in the move file
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 4

| p  | P  | P  |    |    |    |    | F  | s  |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    | b  |    |    |    |    |    |
|    | j  | R  | P  |    | P  |    |    |    |    |
|    |    |    |    |    |    |    | J  |    | p  |
|    |    |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    | S  |    |    |    |
|    |    |    |    |    | f  |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
| j  |    |    | r  |    |    |    |    |    | p  |

*/

/*
-----Example number 14------
Output in the consul:


   1  2  3  4  5  6  7  8  9  10
1 |F |  |  |  |  |  |  |  |  |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |  |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |  |  |  |  |  |  |  |  |  |

9 |  |  |  |  |  |  |  |  |R |  |

10|  |  |  |  |  |  |  |  |  |B |


The Errors of player number 1: All the moving pieces were eaten
The Errors of player number 2: All the flags were caught

Output in the file:
Winner: 1
Reason: All flags of the opponent are captured

| f  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    | R  |    |
|    |    |    |    |    |    |    |    |    | j  |

*/

/*
-----Example number 15------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |F |  |  |  |  |  |  |  |  |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |  |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |  |  |  |  |  |  |  |  |  |

9 |  |  |  |  |  |  |  |  |B |  |

10|  |  |  |  |  |  |  |  |  |F |


The Errors of player number 1: There are no errors for this player
The Errors of player number 2: All the moving pieces were eaten

Output in the file:
Winner: 1
Reason: All moving PIECEs of the opponent are eaten

| f  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    | j  |    |
|    |    |    |    |    |    |    |    |    | F  |
*/

/*
-----Example number 16------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |F |  |  |  |  |  |  |  |  |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |  |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |  |  |  |  |  |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |F |


The Errors of player number 1: All the moving pieces were eaten
The Errors of player number 2: All the moving pieces were eaten

Output in the file:
Winner: 0
Reason: A tie - both Moves input files done without a winner

| f  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    | F  |

*/

/*
-----Example number 17------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |  |  |  |  |  |  |  |  |  |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |  |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |  |  |  |  |  |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: All the flags were caught
The Errors of player number 2: All the flags were caught

Output in the file:
Winner: 0
Reason: A tie - both Moves input files done without a winner

|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |

*/

/*
-----Example number 18------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |  |R |  |  |  |  |  |  |  |  |

2 |  |F |  |  |  |  |  |  |  |  |

3 |  |  |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |  |  |  |  |  |  |  |  |  |

6 |  |  |  |  |P |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |  |  |  |  |  |  |  |  |  |

9 |  |  |  |F |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1:  The player's moves have ended
The Errors of player number 2:  The player's moves have ended

Output in the file:
Winner: 0
Reason: A tie - both Moves input files done without a winner

|    | R  |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    | p  |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    | F  |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
*/

/*
-----Example number 19------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |F |  |  |  |  |  |  |  |  |  |

2 |  |  |  |  |  |  |  |  |  |  |

3 |  |  |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |  |  |  |S |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |  |  |  |  |  |  |  |  |  |

9 |  |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |F |


The Errors of player number 1: All the moving pieces were eaten
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: All moving PIECEs of the opponent are eaten

| f  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    | S  |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    | F  |
*/

/*
-----Example number 20------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |R |  |  |  |  |  |  |  |  |  |

2 |R |B |  |  |  |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |P |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |F |  |  |  |  |  |  |  |  |

9 |F |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: Move a piece in an illegal way in line 1 in the move file
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 1

| r  |    |    |    |    |    |    |    |    |    |
| r  | B  |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | P  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    |    |    |    |    |
| F  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
*/

/*
-----Example number 21------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |R |  |  |  |  |  |  |  |  |  |

2 |B |B |  |  |  |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |P |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |F |  |  |  |  |  |  |  |  |

9 |F |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: There are no errors for this player
The Errors of player number 2: Move a piece in an illegal way in line 1 in the move file

Output in the file:
Winner: 1
Reason: Bad Moves input file for player 2 line 1

| r  |    |    |    |    |    |    |    |    |    |
| b  | B  |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | P  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    |    |    |    |    |
| F  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |

*/

/*
-----Example number 22------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |R |  |  |  |  |  |  |  |  |  |

2 |B |B |  |  |  |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |P |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |F |  |  |  |  |  |  |  |  |

9 |F |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: There are no errors for this player
The Errors of player number 2: The bomb in line:1 in the move file can't move

Output in the file:
Winner: 1
Reason: Bad Moves input file for player 2 line 1

| r  |    |    |    |    |    |    |    |    |    |
| b  | B  |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | P  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    |    |    |    |    |
| F  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
*/

/*
-----Example number 23------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |R |  |  |  |  |  |  |  |  |  |

2 |B |S |  |  |  |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |P |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |F |  |  |  |  |  |  |  |  |

9 |F |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: There are no errors for this player
The Errors of player number 2: Joker does not exist in the place that inserted in line 1 in the move file

Output in the file:
Winner: 1
Reason: Bad Moves input file for player 2 line 1

| r  |    |    |    |    |    |    |    |    |    |
| b  | S  |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | P  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    |    |    |    |    |
| F  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |

*/


/*
-----Example number 24------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |R |  |  |  |  |  |  |  |  |  |

2 |B |S |  |  |  |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |P |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |F |  |  |  |  |  |  |  |  |

9 |F |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: There is a piece in the place that inserted in line:1 in the move file
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 1

| r  |    |    |    |    |    |    |    |    |    |
| b  | S  |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | P  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    |    |    |    |    |
| F  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
*/

/*
-----Example number 25------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |R |  |  |  |  |  |  |  |  |  |

2 |B |S |  |  |  |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |P |  |  |  |  |  |  |  |  |

6 |  |  |  |  |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |F |  |  |  |  |  |  |  |  |

9 |F |  |  |  |  |  |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: The flag in line:1 in the move file can't move
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 1

| r  |    |    |    |    |    |    |    |    |    |
| b  | S  |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | P  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    |    |    |    |    |
| F  |    |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
*/

/*
-----Example number 26------
Output in the consul:

   1  2  3  4  5  6  7  8  9  10
1 |  |  |  |  |  |  |  |  |  |  |

2 |  |S |  |  |B |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |  |  |  |  |  |  |  |

5 |  |P |  |R |  |  |  |  |  |  |

6 |  |  |  |P |  |  |  |  |  |  |

7 |  |  |  |  |  |  |  |  |  |  |

8 |  |F |  |  |  |  |S |  |  |  |

9 |F |  |  |  |  |R |  |  |  |  |

10|  |  |  |  |  |  |  |  |  |  |


The Errors of player number 1: Joker has changed in line 1 in the move file into a piece that didn't exist
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 1

|    |    |    |    |    |    |    |    |    |    |
|    | S  |    |    | b  |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | P  |    | r  |    |    |    |    |    |    |
|    |    |    | j  |    |    |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |
|    | f  |    |    |    |    | s  |    |    |    |
| F  |    |    |    |    | r  |    |    |    |    |
|    |    |    |    |    |    |    |    |    |    |

*/

/*
-----Example number 27------
Output in the consul:
The Errors of player number 1: There are no errors for this player
The Errors of player number 2: The coordinates inserted in line:8 in the input file already have a piece in the board

Output in the file:
Winner: 1
Reason: Bad Positioning input file for player 2 line 8
*/

/*
-----Example number 28------
Output in the consul:
   1  2  3  4  5  6  7  8  9  10
1 |R |  |  |  |S |  |  |  |  |  |

2 |R |B |  |  |  |  |  |  |  |  |

3 |  |B |  |  |  |  |  |  |  |  |

4 |  |  |  |P |  |  |  |  |  |  |

5 |R |  |  |  |  |  |  |R |  |P |

6 |  |P |B |P |  |  |  |  |  |  |

7 |  |  |  |  |  |  |F |  |  |  |

8 |  |  |  |  |  |  |  |F |  |  |

9 |B |  |  |  |  |S |  |R |  |  |

10|  |  |  |P |  |  |  |  |  |  |


The Errors of player number 1: There is no piece in the place that inserted in line 1 in the move file
The Errors of player number 2: There are no errors for this player

Output in the file:
Winner: 2
Reason: Bad Moves input file for player 1 line 1

| r  |    |    |    | s  |    |    |    |    |    |
| r  | B  |    |    |    |    |    |    |    |    |
|    | B  |    |    |    |    |    |    |    |    |
|    |    |    | J  |    |    |    |    |    |    |
| j  |    |    |    |    |    |    | R  |    | j  |
|    | J  | b  | P  |    |    |    |    |    |    |
|    |    |    |    |    |    | f  |    |    |    |
|    |    |    |    |    |    |    | F  |    |    |
| b  |    |    |    |    | S  |    | R  |    |    |
|    |    |    | P  |    |    |    |    |    |    |
*/