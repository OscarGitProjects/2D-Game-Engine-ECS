#pragma once
#include "../enums.h"

/*
	CDirection.h
	CDirection class. I use this to show direction of collision as return value from method CCollisionHelpers.IsCollision between window and a entity.
	@author Oscar Andersson
	@date 2022-11-20
	@version 1.0
*/
class CDirection
{
public:
	Direction HorizontalDirection = DIRECTION_NO;
	Direction VerticalDirection = DIRECTION_NO;

	/* Constructor */
	CDirection() 
		: HorizontalDirection(DIRECTION_NO), VerticalDirection(DIRECTION_NO) 
	{}
};

