#pragma once

/*
	CInput.h
	CInput class with information about whish key is pressed and whish mouse button is pressed
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CInput
{
public:	
	bool up = false;			// W key
	bool left = false;			// A key
	bool right = false;			// D key
	bool down = false;			// S key
	bool shoot = false;
	bool die = false;			// Space bar

	bool leftMouseDown = false;
	int iLeftMouseDownPositionX = 0;
	int iLeftMouseDownPositionY = 0;

	bool rigthMouseDown = false;
	int iRightMouseDownPositionX = 0;
	int iRightMouseDownPositionY = 0;


	/* 
		Constructor 
	*/
	CInput() {}
};