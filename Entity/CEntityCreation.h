#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "CEntity.h"
#include "CEntityManager.h"
#include "../Configuration/CConfiguration.h"
#include "../Helpers/CCollisionHelpers.h"


/*
	CEntityCreation.h
	CEntityCreation class with methods to create entities
	@author Oscar Andersson
	@date 2022-11-21
	@version 1.0
*/
class CEntityCreation
{
private:
	CHelpers m_Helpers;						// Helper class with methods for creating random numbers and for convert enum Type_of_Entity to a std::string
	CCollisionHelpers m_CollisionHelpers;	// Helper class for collision detection

public:
	/* Constructor */
	CEntityCreation() 
	{}
	
	
	/*
		Method create a player entity
		@param window Reference to sf::RenderWindow object
		@param entityManager Reference to entity manager object
		@param configuration Reference to CConfiguration object
		@return std::shared_ptr to the player entity
	*/
	std::shared_ptr<CEntity> createPlayer(sf::RenderWindow & window, CEntityManager & entityManager, CConfiguration & configuration);


	/*
		Method create a enemy entity
		@param window Reference to sf::RenderWindow object
		@param entityManager Reference to entity manager object
		@param configuration Reference to CConfiguration object
		@param std::shared_ptr<CEntity> player Reference to the player object. We use this so that we don't create a enemy where the player is
		@return std::shared_ptr to the enemy entity
	*/
	std::shared_ptr<CEntity> createEnemy(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration, std::shared_ptr<CEntity> player);


	/*
		Method create a bullet entity
		@param window Reference to sf::RenderWindow object
		@param entityManager Reference to entity manager object
		@param configuration Reference to CConfiguration object
		@param shootingEntity Reference to object that is shooting the bullet
		@param mousePosition Reference to point where we want the bullet to go
		@return std::shared_ptr to the bullet entity
	*/
	std::shared_ptr<CEntity> createBullet(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration, std::shared_ptr<CEntity>& shootingEntity, const sf::Vector2i& mousePosition);


	/*
		Method create a bullet entity. For this bullet we use the angle in the CSpecialWeapon for the direction we shall shot the bullet
		@param window Reference to sf::RenderWindow object
		@param entityManager Reference to entity manager object
		@param configuration Reference to CConfiguration object
		@param shootingEntity Reference to object that is shooting the bullet
		@return std::shared_ptr to the bullet entity
	*/
	std::shared_ptr<CEntity> createSpecialWeaponsBullet(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration, std::shared_ptr<CEntity>& shootingEntity);
};
