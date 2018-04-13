#pragma once

enum Reason
{
	noReason=0, //No reason
	flagsCaptured=1, //All flags of the opponent are captured
	allEaten=2, //All moving PIECEs of the opponent are eaten
	badPosition=3, //Bad Positioning input file for player <player> -line <bad line number>
	badMoves=4, //Bad Moves input file for player <player> -line <bad line number>
	moveFilesDone=5 //A tie - both Moves input files done without a winner
};