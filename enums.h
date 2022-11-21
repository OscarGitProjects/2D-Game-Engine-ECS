#pragma once

/*
	enums.h
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0 
*/


/* enum Type_of_Entity with information about what kind of entity we have */
enum Type_of_Entity
{
	NA = 0,
	PLAYER = 1,
	ENEMY = 2,
	BULLET = 3,
	GUI = 4,
};


/* enum Direction */
enum Direction
{
	DIRECTION_NO = 0,
	LEFT = 1,
	RIGHT = 2,
	UP = 3,
	DOWN = 4,
};
