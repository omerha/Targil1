#pragma once

enum Error
{
	noError=0,
	notInRange=1,
	sameLocation=2,
	tooManyPieces=3,
	noFlag=4,
	unKnownPiece=5,
	tooManyRows=6,
	wrongFormatRowInputFile=7,
	wrongFrormatRowMoveFile=8,
	notExistPiece=9,
	notExistJoker=10
};