#pragma once

/*
	CScore.h
	CScore class with information about different score that a entity can have
	@author Oscar Andersson
	@date 2022-11-29
	@version 1.0
*/
class CScore
{
public:
	int score = 0;				// Number of points
	int numberOfKills = 0;		// Number of kills

	int scoreCountToSpecialWeapon = 0;	// If this reaches a special value. Player has a special weapon

	/* 
		Constructor 
	*/
	CScore() 
		: score(0), numberOfKills(0)
	{}
};

