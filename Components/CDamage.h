#pragma once

/*
	CDamage.h
	CDamage class with information about the damage a bullet has
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CDamage
{
public:
	int damage = 0;

	/* 
		Constructor 
		@param iDamage Damage
	*/
	CDamage(int iDamage)
		:damage(iDamage)
	{}
};

