#include "CHelpers.h"


/* Constructor */
CHelpers::CHelpers()
{
	srand(time(nullptr));
}


/*
	Method convert enum Type_of_Entity to a std::string
	@return enum Type_of_Entity as a std::string
*/
std::string CHelpers::Type_of_Entity_ToString(Type_of_Entity type)
{
	std::string strType = "NA";

	switch (type)
	{
	case BULLET:
		strType = "BULLET";
		break;
	case ENEMY:
		strType = "ENEMY";
		break;
	case PLAYER:
		strType = "PLAYER";
		break;
	case GUI:
		strType = "GUI";
		break;
	}

	return strType;
}


/*
	Method return a random value between Min and Max. Including Min and Max
	@param iMin Min value of the range
	@param iMax Max value of the range
*/
int CHelpers::getRandomNumber(int iMin, int iMax)
{
	int iRange = iMax - iMin + 1;
	return iMin + rand() % iRange;
}
