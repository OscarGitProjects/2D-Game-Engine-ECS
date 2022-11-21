#pragma once
#include <SFML/Graphics.hpp>


/*
	CTransform.h
	CTransform class with information about different score that a entity can have
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CTransform
{
public:
	sf::Vector2f position = { 0.0f, 0.0f };		// Entity position
	sf::Vector2f velocity = { 0.0f, 0.0f };		// Entity velocity
	float rotationSpeed = 1.0f;					// Entity rotation speed
	float angle = 0.0f;							// Entity angle

	/* 
		Constructor 
		@param pos Position 
		@param vel Velocity 
		@param fAngle Angle 
		@param fRotationSpeed RotationSpeed 
	*/
	CTransform(const sf::Vector2f& pos, const sf::Vector2f& vel, float fAngle, float fRotationSpeed)
		: position(pos), velocity(vel), angle(fAngle), rotationSpeed(fRotationSpeed) {}
};

