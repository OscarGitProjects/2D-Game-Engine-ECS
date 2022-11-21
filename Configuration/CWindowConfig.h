#pragma once
#include <string>

/*
	CWindowConfig.h
	CWindowConfig class for different configurations for the Window
	Window Name W H FL FS
	@author Oscar Andersson
	@date 2022-11-13
	@version 1.0 
*/
class CWindowConfig
{
private:
	std::string m_strProgramName = "Geometry Wars";		// Name of the program
	int m_iWindowHeight = 768;							// Window height
	int m_iWindowWidth = 1024;							// Window width
	int m_iFrameRateLimit = 30;							// Framerate limit
	int m_iWindowMode = 0;								// Mode of the window. 1 = full screen, 0 = window mode

public:
	// get/set methods

	/* 
		Method return the name of the program 
		@return Name of the program 
	*/
	const std::string& getProgramName() const { return m_strProgramName; }

	/* 
		Method get Window height. Default is 768
		@return Window height
	*/
	int getWindowHeight() { return m_iWindowHeight; }

	/*
		Method get Window width. Default is 1024
		@return Window width
	*/
	int getWindowWidth() { return m_iWindowWidth; }

	/*
		Method get framerate limit value. Default is 30
		@return Framerate limit value
	*/
	int getFramerateLimit() { return m_iFrameRateLimit; }

	/* 
		Method get value for framerate limit. 1 = Fullscreen, 0 = Window mode
		@return Framerate limit value 
	*/
	int getWindowMode() { return m_iWindowMode; }



	// set methods

	/*
		Method set the name of the program
		@param Name of the program
	*/
	void setProgramName(const std::string strProgramName) { m_strProgramName = strProgramName; }

	/*
		Method set Window height. Default is 768
		@param iWindowHeight Window height
	*/
	void setWindowHeight(int iWindowHeight) { m_iWindowHeight = iWindowHeight; }

	/*
		Method set Window width. Default is 768
		@param iWindowWidth Window width
	*/
	void setWindowWidth(int iWindowWidth) { m_iWindowWidth = iWindowWidth; }

	/*
		Method set framerate limit value. Default is 30
		@iFrameRateLimit Framerate limit value
	*/
	void setFramerateLimit(int iFrameRateLimit) { m_iFrameRateLimit = iFrameRateLimit; }

	/*
		Method set value for framerate limit. 1 = Fullscreen, 0 = Window mode
		@param iWindowMode Framerate limit value
	*/
	void setWindowMode(int iWindowMode) { m_iWindowMode = iWindowMode; }
};

