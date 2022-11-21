#pragma once

/*
	CCollision.h
	CCollision class with radios of the bounding circle around a entity
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CCollision
{
public:
	float radius = 0.0f;	// Radius of the bounding circle

	/* 
		Constructor 
		@param iRadius Radius of the bounding circle
	*/
	CCollision(float fRadius)
		:radius(fRadius)
	{}
};
