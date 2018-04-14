#pragma once

enum Error
{
	noError = 0,
	notInRange = 1,
	sameLocation = 2,
	tooManyPieces = 3,
	noFlag = 4,
	unKnownPiece = 5,
	tooManyRows = 6,
	wrongFormatRowInputFile = 7,
	wrongFrormatRowMoveFile = 8,
	notExistPiece = 9,
	notExistJoker = 10,
	wrongInputJoker = 11,
	emptyFile = 12,
	moveIllegal = 13,
	notExistFile=14,
	unKnownPieceForJoker=15,
	jokerNotInRange=16,
	bombCantMove=17,
	flagCantMove=18,
	errorFile=19
};