#pragma once

/*
	CConfigValidation.h
	CConfigValidation class with methods for validation of data from the configuration file
	@author Oscar Andersson
	@date 2022-11-13
	@version 1.0 
*/
class CConfigValidation
{
private:
public:
	/*
		Method check if a value is between 0 and 255. Inclusive 0 and 255
		@param Value that we want to validate
		@return true if value is ok. Otherwise return false
	*/
	bool IsValidColorValue(int iColorValue);

};