#pragma once
#include <SFML/Graphics.hpp>
#include <string>

/*
	CFontConfig.h
	CFontConfig class for different configurations for the font
	@author Oscar Andersson
	@date 2022-11-13
	@version 1.0 
*/
class CFontConfig
{
private:
	std::string m_strFontFileName = "Fonts/sansation.ttf";	// Name and path to the font file
	int m_iFontSize = 18;									// Font size
	sf::Color m_FontColor;									// Color of the text that uses this font
	bool m_bHasFont = false;								// true if we have a font in this class. Otherwise false

public:
	// get/set methods 

	/*
		Method return reference to string path and filenamn of the font
		@return Reference to string with Path and filename of the font
	*/
	const std::string& getFontFileName() { return m_strFontFileName; }

	/*
		Method return the font size
		@return Font size
	*/
	int getFontSize() { return m_iFontSize; }

	/*
		Method return a reference to the color of text that use this font
		@return Reference to a Color of text that uses font
	*/
	const sf::Color& getFontColor() { return m_FontColor; }

	/*
		Method return true if we data about a font saved in this class. Otherwise false
		@return true if we have data about a font. Otherwise we return false
	*/
	bool HasFont() { return m_bHasFont; }


	// set methods

	/*
		Method set string path and filenamn of the font
		@param strFileName string with Path and filename of the font
	*/
	void setFontFileName(std::string strFileName) { m_strFontFileName = strFileName; }

	/*
		Method set the font size
		@param iFontSize Font size
	*/
	void setFontSize(int iFontSize) { m_iFontSize = iFontSize; }

	/*
		Method set a sf::Color with the color
		@param fontColor sf::Color with the color
	*/
	void setFontColor(sf::Color fontColor) { m_FontColor = fontColor; }

	/*
		Method set true if we data about a font saved in this class. Otherwise false
		@param bHasFont true if we have data about a font. Otherwise we return false
	*/
	void HasFont(bool bHasFont) { m_bHasFont = bHasFont; }
};

