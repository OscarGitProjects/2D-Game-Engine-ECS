#pragma once

/*
	CSpecialWeapon.h
	CSpecialWeapon class with information about shooting of the special weapon
	@author Oscar Andersson
	@date 2022-11-29
	@version 1.0
*/
class CSpecialWeapon
{
public:
	int numberOfFramesBetweenBullets = 30;		// Number of frames between bullets
	int numberOfBullets = 10;					// Total number of bullets we want to shoot
	float angle = 0.0f;							// Angle between bullets
	int bulletCount = 0;						// Number of bullets we have shot

	float currentAngle = 0.0f;
	int iFrameCount = 0;

	/* 
		Constructor 
		@param iNumberOfFramesBetweenBullets Number of frames between bullets
		@param fAngle Angle between bullets direction
		@param iNumberOfBullets Number of bullets we shall shoot
	*/
	CSpecialWeapon(int iNumberOfFramesBetweenBullets, float fAngle, int iNumberOfBullets)
		: numberOfFramesBetweenBullets(iNumberOfFramesBetweenBullets), angle(fAngle), numberOfBullets(iNumberOfBullets)
	{}
};

