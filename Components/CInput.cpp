#include "CInput.h"


/* Method clear all input variables */
void CInput::ClearInput()
{
	up = false;			// W key
	left = false;		// A key
	right = false;		// D key
	down = false;		// S key
	shoot = false;
	die = false;		// Space bar

	leftMouseDown = false;
	iLeftMouseDownPositionX = 0;
	iLeftMouseDownPositionY = 0;

	rigthMouseDown = false;
	iRightMouseDownPositionX = 0;
	iRightMouseDownPositionY = 0;
}