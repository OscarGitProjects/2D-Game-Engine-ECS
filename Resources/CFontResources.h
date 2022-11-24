#pragma once
#include <map>
#include <string>

#include <SFML/Graphics.hpp>


/*
	CFontResources.h
	CFontResources class with a map of fonts
	@author Oscar Andersson
	@date 2022-11-24
	@version 1.0
*/
class CFontResources
{
public:
	std::map<std::string, sf::Font> m_FontMap;

	/* Destructor */
	~CFontResources();
};

