#pragma once
#include <SFML/Graphics.hpp>


/*
	CShape.h
	CShape class with varaiables and methods for the shape of a entity in the game
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CShape
{
private:
	sf::CircleShape m_CircleShape;

public:
	/* Constructor */
	CShape(float fRadius, int iPoints, const sf::Color fillColor, const sf::Color outlineColor, float fOutlineThickness)
		: m_CircleShape(fRadius, iPoints)
	{
		m_CircleShape.setFillColor(fillColor);
		m_CircleShape.setOutlineColor(outlineColor);
		m_CircleShape.setOutlineThickness(fOutlineThickness);
		m_CircleShape.setOrigin(fRadius, fRadius);
	}

	// get methods

	/* 
		Method return a reference to the shape object 
		@return Reference to the shape object 
	*/
	sf::CircleShape& getShape() { return m_CircleShape; }
};