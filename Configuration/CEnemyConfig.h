#pragma once
#include <SFML/Graphics.hpp>

/*
	CPlayerConfig.h
	CPlayerConfig class for different configurations for the enemies
	@author Oscar Andersson
	@date 2022-11-13
	@version 1.0 
*/
class CEnemyConfig
{
private:
	int m_iShapeRadius = 20;			// Radius of the enemy shape
	int m_iCollisionBoxRadius = 20;		// Radius of bounding box/circle that surrounds the enemy shape
	
	float m_fMinSpeed = 1.0f;			// Min speed for enemy
	float m_fMaxSpeed = 10.0f;			// Max speed for enemy

	//sf::Color m_FillColor;			// No fill color. We use random fill color

	sf::Color m_OutlineColor;			// Outline color for the enemy shape
	int m_iOutlineThickness = 2;		// Outline thickness

	int m_iMinNumberOfVerticesForShape = 3;	// Min number of vertices for this shape
	int m_iMaxNumberOfVerticesForShape = 8;	// Max number of vertices for this shape

	int m_iSmallEnemyShapeLifeSpan = 90;	// Number of frames that a small shape shall live
	int m_iSpawnInterval = 60;				// Spawn interval in muber of frames

	float m_fRotationSpeed = 2.0f;		// The speed that we rotate the shape with

	int m_iMinHealth = 50;				// Min health for a enemy
	int m_iMaxHealth = 255;				// Max health for a enemy	

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
		Method return min speed
		@return Min Speed
	*/
	float getMinSpeed() { return m_fMinSpeed; }

	/*
		Method return max speed
		@return Max Speed
	*/
	float getMaxSpeed() { return m_fMaxSpeed; }

	/*
		Method return the OutlineColor for the enemy shape
		@return Reference to OutlineColor for the enemy shape
	*/
	sf::Color& getOutlineColor() { return m_OutlineColor; }

	/*
		Method return OutlineThickness for the enemy shape
		@return Outline thickness for the enemy shape
	*/
	int getOutlineThickness() { return m_iOutlineThickness; }

	/*
		Method return min number of vertices for the shape
		@return Min number of vertices for the shape
	*/
	int getMinNumberOfVerticesForShape() { return m_iMinNumberOfVerticesForShape; }

	/*
		Method return max number of vertices for the shape
		@return Max number of vertices for the shape
	*/
	int getMaxNumberOfVerticesForShape() { return m_iMaxNumberOfVerticesForShape; }

	/* 
		Method return number of frames a small enemy shall live 
		@return Number of frames a small enemy shall live 
	*/
	int getSmallEnemyShapeLifeSpan() { return m_iSmallEnemyShapeLifeSpan; }

	/* 
		Method return number of frames between spawn of new enemy 
		@return Number of frames between spawn of new enemy
	*/
	int getSpawnInterval() { return m_iSpawnInterval; }

	/*
		Method return the speed that we rotate the shape with
		@return Speed we rotate the shape with
	*/
	float getRotationSpeed() { return m_fRotationSpeed; }

	/*
		Method return the min health for a enemy
		@return Mix health
	*/
	int getMinHealth() { return m_iMinHealth; }

	/* 
		Method return the max health for a enemy 
		@return Max health
	*/
	int getMaxHealth() { return m_iMaxHealth; }


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
		Method set min speed
		@param fMinSpeed Min Speed
	*/
	void setMinSpeed(float fMinSpeed) { m_fMinSpeed = fMinSpeed; }

	/*
		Method set max speed
		@param fMaxSpeed Max Speed
	*/
	void setMaxSpeed(float fMaxSpeed) { m_fMaxSpeed = fMaxSpeed; }

	/*
		Method set the OutlineColor for the enemy shape
		@param outlineColor OutlineColor for the enemy shape
	*/
	void setOutlineColor(sf::Color outlineColor) { m_OutlineColor = outlineColor; }

	/*
		Method set OutlineThickness for the enemy shape
		@return iOutlineThickness Outline thickness for the enemy shape
	*/
	void setOutlineThickness(int iOutlineThickness) { m_iOutlineThickness = iOutlineThickness; }

	/*
		Method set min number of vertices for the shape
		@param iMinNumberOfVerticesForShape Min number of vertices for the shape
	*/
	void setMinNumberOfVerticesForShape(int iMinNumberOfVerticesForShape) { m_iMinNumberOfVerticesForShape = iMinNumberOfVerticesForShape; }

	/*
		Method set max number of vertices for the shape
		@param iMaxNumberOfVerticesForShape Max number of vertices for the shape
	*/
	void setMaxNumberOfVerticesForShape(int iMaxNumberOfVerticesForShape) { m_iMaxNumberOfVerticesForShape = iMaxNumberOfVerticesForShape; }

	/*
		Method set number of frames a small enemy shall live
		@return iSmallEnemyShapeLifeSpan Number of frames a small enemy shall live
	*/
	void setSmallEnemyShapeLifeSpan(int iSmallEnemyShapeLifeSpan) { m_iSmallEnemyShapeLifeSpan = iSmallEnemyShapeLifeSpan; }

	/*
		Method set number of frames between spawn of new enemy
		@return iSpawnInterval Number of frames between spawn of new enemy
	*/
	void setSpawnInterval(int iSpawnInterval) { m_iSpawnInterval = iSpawnInterval; }

	/*
		Method set the speed that we rotate the shape with
		@param fRotationSpeed Speed we rotate the shape with
	*/
	void setRotationSpeed(float fRotationSpeed) { m_fRotationSpeed = fRotationSpeed; }

	/*
		Method set the min health for a enemy
		@param iMinHealth Min health
	*/
	void setMinHealth(int iMinHealth) { m_iMinHealth = iMinHealth; }

	/*
		Method set the max health for a enemy
		@param iMaxHealth Max health
	*/
	void setMaxHealth(int iMaxHealth) { m_iMaxHealth = iMaxHealth; }
};

