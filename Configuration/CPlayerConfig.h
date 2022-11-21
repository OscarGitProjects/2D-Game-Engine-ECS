#pragma once
#include <SFML/Graphics.hpp>

/*
	CPlayerConfig.h
	CPlayerConfig class for different configurations for the player
	@author Oscar Andersson
	@date 2022-11-13
	@version 1.0 
*/
class CPlayerConfig
{
private:
	int m_iShapeRadius = 20;				// Radius of the player shape
	int m_iCollisionBoxRadius = 24;			// Radius of bounding box/circle that surrounds the player shape
	float m_fSpeed = 5.0f;					// Players speed
	sf::Color m_FillColor;					// Fill color for the players shape
	sf::Color m_OutlineColor;				// Outline color for the players shape
	int m_iOutlineThickness = 1;			// Outline thickness
	int m_iNumberOfVerticesForShape = 4;	// Number of verctices that the players shape has.
	float m_fRotationSpeed = 1.0f;			// The speed that we rotate the shape with
	int m_iRespawnInterval = 100;			// Number of frames before respawn of dead player

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
		Method return the fill color for players shape 
		@return Reference to Fill color for players shape
	*/
	sf::Color& getFillColor() { return m_FillColor; }

	/* 
		Method return the OutlineColor for the players shape 
		@return Reference to OutlineColor for the players shape 
	*/
	sf::Color& getOutlineColor() { return m_OutlineColor; }

	/* 
		Method return OutlineThickness for the players shape 
		@return Outline thickness for the players shape 
	*/
	int getOutlineThickness() { return m_iOutlineThickness; }

	/* 
		Method return Number of vertices for players shape
		@return Number of vertices for players shape 
	*/
	int getNumberOfVerticesForShape() { return m_iNumberOfVerticesForShape; }

	/* 
		Method return the speed that we rotate the shape with 
		@return Speed we rotate the shape with 
	*/
	float getRotationSpeed() { return m_fRotationSpeed; }

	/* 
		Method return number of frames before respawn of player 
		@return Number of frames before respawn 
	*/
	int getRespawnInterval() { return m_iRespawnInterval; }


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
		Method set the fill color for players shape
		@param fillColor Fill color for players shape
	*/
	void setFillColor(sf::Color fillColor) { m_FillColor = fillColor; }

	/*
		Method set the OutlineColor for the players shape
		@param outlineColor OutlineColor for the players shape
	*/
	void setOutlineColor(sf::Color outlineColor) { m_OutlineColor = outlineColor; }

	/*
		Method set OutlineThickness for the players shape
		@return iOutlineThickness Outline thickness for the players shape
	*/
	void setOutlineThickness(int iOutlineThickness) { m_iOutlineThickness = iOutlineThickness; }

	/*
		Method set Number of vertices for players shape
		@param iNumberOfVerticesForShape Number of vertices for players shape
	*/
	void setNumberOfVerticesForShape(int iNumberOfVerticesForShape) { m_iNumberOfVerticesForShape = iNumberOfVerticesForShape; }

	/*
		Method set the speed that we rotate the shape with
		@param fRotationSpeed Speed we rotate the shape with
	*/
	void setRotationSpeed(float fRotationSpeed) { m_fRotationSpeed = fRotationSpeed; }

	/*
		Method set number of frames before respawn of player
		@param iRespawnInterval Number of frames before respawn
	*/
	void setRespawnInterval(int iRespawnInterval) { m_iRespawnInterval = iRespawnInterval; }
};