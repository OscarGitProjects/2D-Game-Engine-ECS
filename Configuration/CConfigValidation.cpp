#include "CConfigValidation.h"

/*
	Method check if a value is between 0 and 255. Inclusive 0 and 255
	@param Value that we want to validate
	@return true if value is ok. Otherwise return false
*/
bool CConfigValidation::IsValidColorValue(int iColorValue)
{
    bool bIsValid = false;

    if (iColorValue >= 0 && iColorValue <= 255)
        bIsValid = true;

    return bIsValid;
}