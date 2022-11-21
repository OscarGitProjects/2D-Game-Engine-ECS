#pragma once
#include <SFML/Graphics.hpp>

/*
	CBulletConfig.h
	CBulletConfig class for different configurations for the bullets
	@author Oscar Andersson
	@date 2022-11-13
	@version 1.0 
*/
class CBulletConfig
{
private:
	int m_iShapeRadius = 10;				// Radius of the bullet shape
	int m_iCollisionBoxRadius = 14;			// Radius of bounding box/circle that surrounds the bullet shape
	float m_fSpeed = 20.0f;					// Bullet speed
	sf::Color m_FillColor;					// Fill color for the bullet shape
	sf::Color m_OutlineColor;				// Outline color for the bullet shape
	int m_iOutlineThickness = 2;			// Outline thickness
	int m_iNumberOfVerticesForShape = 20;	// Number of verctices that the bullet shape has.
	int m_iLifespan = 90;					// Number of frames before bullet will be destroyed
	int m_iDamage = 50;						// The damage a bullet causes on another entity

public:
	// get/set methods
	// get methods


	/*
		Method return radius of this shape
		@return Radius of this shape
	*/
	int getShapeRadius() { return m_iShapeRadius; }

	/*
		Method return radius of this shapes bounding box/circle
		@return Radius of this shapes bounding box/circle
	*/
	int getCollisionBoxRadius() { return m_iCollisionBoxRadius; }

	/*
		Method return speed
		@return Speed
	*/
	float getSpeed() { return m_fSpeed; }

	/*
		Method return the fill color for bullet shape
		@return Reference to Fill color for bullet shape
	*/
	sf::Color& getFillColor() { return m_FillColor; }

	/*
		Method return the OutlineColor for the bullet shape
		@return Reference to OutlineColor for the bullet shape
	*/
	sf::Color& getOutlineColor() { return m_OutlineColor; }

	/*
		Method return OutlineThickness for the bullet shape
		@return Outline thickness for the bullet shape
	*/
	int getOutlineThickness() { return m_iOutlineThickness; }

	/*
		Method return Number of vertices for bullet shape
		@return Number of vertices for bullet shape
	*/
	int getNumberOfVerticesForShape() { return m_iNumberOfVerticesForShape; }

	/*
		Method return number of frames before bullet will be destroyed
		@return Number of frames before bullet will be destroyed
	*/
	int getLifespan() { return m_iLifespan; }

	/* 
		Method return the level of damage a bullet causes on another entity 
		@return Level of damage 
	*/
	int getDamage() { return m_iDamage; }


	// set methods


	/*
		Method set radius of this shape
		@param iShapeRadius Radius of this shape
	*/
	void setShapeRadius(int iShapeRadius) { m_iShapeRadius = iShapeRadius; }

	/*
		Method set radius of this shapes bounding box/circle
		@param iCollisionBoxRadius Radius of this shapes bounding box/circle
	*/
	void setCollisionBoxRadius(int iCollisionBoxRadius) { m_iCollisionBoxRadius = iCollisionBoxRadius; }

	/*
		Method set speed
		@param fSpeed Speed
	*/
	void setSpeed(float fSpeed) { m_fSpeed = fSpeed; }

	/*
		Method set the fill color for bullet shape
		@param fillColor Fill color for bullet shape
	*/
	void setFillColor(sf::Color fillColor) { m_FillColor = fillColor; }

	/*
		Method set the OutlineColor for the bullet shape
		@param outlineColor OutlineColor for the bullet shape
	*/
	void setOutlineColor(sf::Color outlineColor) { m_OutlineColor = outlineColor; }

	/*
		Method set OutlineThickness for the bullet shape
		@return iOutlineThickness Outline thickness for the bullet shape
	*/
	void setOutlineThickness(int iOutlineThickness) { m_iOutlineThickness = iOutlineThickness; }

	/*
		Method set Number of vertices for bullet shape
		@param iNumberOfVerticesForShape Number of vertices for bullet shape
	*/
	void setNumberOfVerticesForShape(int iNumberOfVerticesForShape) { m_iNumberOfVerticesForShape = iNumberOfVerticesForShape; }

	/*
		Method set number of frames before bullet will be destroyed
		@param iLifespan Number of frames before bullet will be destroyed
	*/
	void setLifespan(int iLifespan) { m_iLifespan = iLifespan; }

	/*
		Method return the level of damage a bullet causes on another entity
		@param iDamage Level of damage
	*/
	void setDamage(int iDamage) { m_iDamage = iDamage; }
};
