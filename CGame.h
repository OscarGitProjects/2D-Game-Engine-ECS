#pragma once

#include <SFML/Graphics.hpp>
#include "Configuration/CConfiguration.h"
#include "Entity/CEntityManager.h"
#include "Components/CCollision.h"
#include "Helpers/CCollisionHelpers.h"
#include "Entity/CEntityCreation.h"
#include "Resources/CFontResources.h"

/*
	CGame.h
	CGame class that handles the game functions
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CGame
{
private:
	sf::Text m_ScoreText;							// sf::Text Players score
	sf::Text m_NumberOfDeathsText;					// sf::Text Number of time the players has been killed
	sf::Text m_YouAreKilledMessageText;				// sf::Text Mesage when you are killed. We show this in the center of the screen
	sf::Text m_NumberOfKilledText;					// sf::Text Number of killed enemies
	sf::RenderWindow m_Window;						// Window

	std::shared_ptr<CEntity> m_Player = nullptr;	// Pointer to the player

	bool m_bPaused = false;							// True if game is paused
	bool m_bRunning = true;

	unsigned int m_uiCurrentFrame = 0;
	int m_iLastEnemySpawnTime = 0;
	bool m_bSpawnNewEnemy = false;					// True if we shall spawn a new player.

	int m_PlayerNumberOfTimeKilled = 0;				// Number of time player has been killed
	
	CEntityManager m_EntityManager;					// Entity manager object
	CConfiguration m_Configuration;					// Configurations
	CCollisionHelpers m_CollisionHelpers;			// Helper class for collision detection
	CHelpers m_Helpers;								// Helper class with methods for creating random numbers and for convert enum Type_of_Entity to a std::string
	CEntityCreation m_EntityCreation;				// Class where i create entities

	CFontResources m_FontResources;					// Object with a map of fonts

public:
	sf::Font m_Font;

	/* Constructor */
	CGame(){}

	/* 
		Constructor 
		@param strConfigFileName Name of the configuration file 
	*/
	CGame(const std::string & strConfigFileName);

	/*
		Constructor
		@param strConfigFileName Name of the configuration file
		@param strFontFileName Name and path of the fonts file
	*/
	CGame(const std::string& strConfigFileName, const std::string& strFontFileName);

	/*
		Is game paused or not
		@return true if game is paused. Otherwise we return false
	*/
	bool isPaused() { return m_bPaused; }

	/*
		Is game paused or not
		@bPaused true if game is paused. Otherwise we return false
	*/
	void isPaused(bool bPaused) { m_bPaused = bPaused; }

	/*
		Is game running or not
		@return true if game is still running. Otherwise we return false and the game ends
	*/
	bool isRunning() { return m_bRunning; }


	/*
		Method get the number of time the player has been killed
		@return Number of timeplayer has been killed
	*/
	int getPlayerNumberOfTimeKilled() { return this->m_PlayerNumberOfTimeKilled; }

	/*
		Method set the number of time the player has been killed
		@param iPlayerNumberOfTimeKilled Number of timeplayer has been killed
	*/
	void setPlayerNumberOfTimeKilled(int iPlayerNumberOfTimeKilled) { this->m_PlayerNumberOfTimeKilled = iPlayerNumberOfTimeKilled; }


	/***** Methods *****/

	/* Method run the game */
	void run();

	/* Method initialize the game */
	void initialize();

	/* 
		Method that initialize the game 
		@param strConfigFileName Name of the configuration file 
	*/
	void initialize(const std::string& strConfigFileName);

	/*
		Method initialize the game
		@param strConfigFileName Name of the configuration file
		@param strFontFileName Name and path of the fonts file
	*/
	void initialize(const std::string& strConfigFileName, const std::string& strFontFileName);

	/* Method create a player and adds it to the entities vector */
	void createPlayer();

	/*
		Method create a bullet moving from entity position to mousePosition
		@param shootingEntity Reference to entity with a position that is the starting point for the bullet
		@param mousePosition Point where the bullet shall go
	*/
	void createBullet(std::shared_ptr<CEntity>& shootingEntity, const sf::Vector2i& mousePosition);

	/*
		Method create a special weapon effect moving from entity position to mousePosition
		@param shootingEntity Reference to entity with a position that is the starting point for the special weapon effect
		@param mousePosition Point where the special weapons effect shall go
	*/
	void createSpecialWeapon(std::shared_ptr<CEntity>& shootingEntity, const sf::Vector2i& mousePosition);

	/* Method create a new enemy */
	void createEnemy();

	/* Method create  GUI entities */
	void createGui();

	/* Method respawn the player */
	void respawnPlayer();


	/***** System *****/

	/* System method that render objects to the screen */

	/* System method that handles updates of the gui */
	void sGuiHandling();

	/* System method that handle player actions respan, create bullets and create special effects */
	void sPlayerHandling();

	/* System method that handle creation of enemies */
	void sEnemyCreation();			// System: Handles the creation of new enemies

	/* System method that handles entities with a lifespan added to them */
	void sLifespan();				// Sysstem: Handles enteties with a lifespan

	/* System method that update entities position before rendering */
	void sMovement();				// System: Entity position and movement update

	/* System method that render objects to the screen */
	void sRender();					// System. Render obejcts

	/* System method that handles input from mouse and the keyboard */
	void sUserInput();				// System. Input from mouse and keyboard

	/* System method that handles collision with the window borders and otehr enteties in the game */
	void sCollision();				// System: Collision

};

