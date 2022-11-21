#pragma once
#include <string>
#include <time.h>
#include "../enums.h"


/*
	CHelpers.h
	CHelpers class with helper methods
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CHelpers
{
public:

	/* Constructor */
	CHelpers();


	/* 
		Method convert enum Type_of_Entity to a std::string 
		@return enum Type_of_Entity as a std::string
	*/
	std::string Type_of_Entity_ToString(Type_of_Entity type);


	/* 
		Method return a random value between Min and Max. Including Min and Max 
		@param iMin Min value of the range 
		@param iMax Max value of the range
	*/
	int getRandomNumber(int iMin, int iMax);
};

