#pragma once

/*
	CLifespan.h
	CLifespan class with information about how long a lifespan is
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CLifespan
{
public:
	int remaining = 0;	// Amount of lifespan remaining for the entity
	int total = 0;		// Total lifespan for the entity

	/* 
		Constructor 
		@param iTotalLifespan Total lifespan
	*/
	CLifespan(int iTotalLifespan) 
		: remaining(iTotalLifespan), total(iTotalLifespan) 
	{}
};

