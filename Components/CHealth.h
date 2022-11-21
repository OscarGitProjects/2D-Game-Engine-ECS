#pragma once

/*
	CHealth.h
	CHealth class with information about a enities health
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CHealth
{
public:
	int health = 0;

	/* 
		Constructor 
		@param iHealth Health 
	*/
	CHealth(int iHealth)
		: health(iHealth)
	{}
};
