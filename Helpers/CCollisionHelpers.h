#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Entity/CEntity.h"
#include "../enums.h"
#include "CDirection.h"

/*
	CCollisionHelpers.h
	CCollisionHelpers class with methods for collision detection
	@author Oscar Andersson
	@date 2022-11-20
	@version 1.0
*/
class CCollisionHelpers
{
public:
	/* 
		Method detect collision between entity and the windows borders 
		@param Reference to the sf::RenderWindow object
		@param std::shared_ptr to the entity
		@return CDirection class with the Direction which border we collided with
	*/
	CDirection IsCollision(const sf::RenderWindow& window, const std::shared_ptr<CEntity> entity) const;


	/* 
		Method detect collision between two entities 
		@param std::shared_ptr to entity 
		@param std::shared_ptr to entity
		@return true if entities is colliding. Otherwise returns false
	*/
	bool IsCollision(const std::shared_ptr<CEntity> entity1, const std::shared_ptr<CEntity> entity2) const;
};

