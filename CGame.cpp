#include "CGame.h"

/*
	Constructor
	@param strConfigFileName Name of the configuration file
*/
CGame::CGame(const std::string& strConfigFileName)
{
	m_Configuration.setConfigFileName(strConfigFileName);	
}


/*
    Constructor
    @param strConfigFileName Name of the configuration file
    @param strFontFileName Name and path of the fonts file
*/
CGame::CGame(const std::string& strConfigFileName, const std::string & strFontFileName)
{
    m_Configuration.setConfigFileName(strConfigFileName);
    m_Configuration.setFontFileName(strFontFileName);
}


/***** Methods *****/

/* Method run the game */
void CGame::run()
{
	// Set up sf::Font for the framerate text
	m_Configuration.getFontConfig().HasFont(false);
	bool bHasFont = false;

	// FIX. Problem with reference to sf::Font. I load it here and it works
	// Load font from harddrive
	sf::Font font;
	if (font.loadFromFile(m_Configuration.getFontConfig().getFontFileName()))
	{
		m_Configuration.getFontConfig().HasFont(true);

		m_ScoreText.setFont(font);
		m_NumberOfDeathsText.setFont(font);
		m_YouAreKilledMessageText.setFont(font);
		m_NumberOfKilledText.setFont(font);

		bHasFont = true;
	}

	// Position the You are killed message in the window
	sf::FloatRect fRect = m_YouAreKilledMessageText.getGlobalBounds();
	sf::Vector2u vecWindowSize = m_Window.getSize();

	float fTextXPos = ((float)(vecWindowSize.x / 2)) - (fRect.width / 2.0f);
	float fTextYPos = ((float)(vecWindowSize.y / 2)) - (fRect.height / 2.0f);
	m_YouAreKilledMessageText.setPosition(fTextXPos, fTextYPos);

	// Position the number of times you have been killed in the window
	fRect = m_NumberOfDeathsText.getGlobalBounds();
	fTextXPos = ((float)(vecWindowSize.x / 2)) - (fRect.width / 2.0f);
	fTextYPos = 5.0f;
	m_NumberOfDeathsText.setPosition(fTextXPos, fTextYPos);

	createGui();

	createPlayer();

	createEnemy();

	while (isRunning())
	{
		// Update entities in the entitymanager
		m_EntityManager.update();

		if (!this->isPaused())
		{
			sPlayerHandling();
			sEnemyCreation();
			sCollision();
			sLifespan();
			sMovement();
		}

		sGuiHandling();
		sUserInput();
		sRender();
	}

	m_Window.close();
}


#pragma region initialize of game


/* Method initialize the game */
void CGame::initialize()
{
    // Load configurations from config file
    m_Configuration.LoadConfigurations();

	// Set up text for score
	m_ScoreText.setString("Score");
	m_ScoreText.setFillColor(m_Configuration.getFontConfig().getFontColor());
	m_ScoreText.setCharacterSize(m_Configuration.getFontConfig().getFontSize());
	m_ScoreText.setPosition(10.0f, 5.0f);

	// Set up text for number of killed enemies
	m_NumberOfKilledText.setString("You have killed");
	m_NumberOfKilledText.setFillColor(m_Configuration.getFontConfig().getFontColor());
	m_NumberOfKilledText.setCharacterSize(m_Configuration.getFontConfig().getFontSize());
	m_NumberOfKilledText.setPosition(10.0f, 5.0f);

	// Set up text for number of times player has been killed
	m_NumberOfDeathsText.setString("You have been killed " + std::to_string(this->m_PlayerNumberOfTimeKilled) + " times");
	m_NumberOfDeathsText.setFillColor(m_Configuration.getFontConfig().getFontColor());
	m_NumberOfDeathsText.setCharacterSize(m_Configuration.getFontConfig().getFontSize());
	m_NumberOfDeathsText.setPosition(300, 5.0f);

	// Set up text for when player has been killed
	m_YouAreKilledMessageText.setString("You are dead. Wait for respawn of player");
	m_YouAreKilledMessageText.setFillColor(sf::Color::Red);
	m_YouAreKilledMessageText.setCharacterSize(24);
	m_YouAreKilledMessageText.setPosition(300, 300);


	// Get the window mode. Fullscreen or windowed mode
	int iWindowMode = m_Configuration.getWindowConfig().getWindowMode();
		
    // Set up the window
    m_Window.create(sf::VideoMode(m_Configuration.getWindowConfig().getWindowWidth(),
        m_Configuration.getWindowConfig().getWindowHeight()),
		m_Configuration.getWindowConfig().getProgramName(), iWindowMode == 1 ? sf::Style::Fullscreen : sf::Style::Default);

    m_Window.setVerticalSyncEnabled(true);
    m_Window.setFramerateLimit(m_Configuration.getWindowConfig().getFramerateLimit());
}


/*
	Method initialize the game
	@param strConfigFileName Name of the configuration file
*/
void CGame::initialize(const std::string& strConfigFileName)
{
	m_Configuration.setConfigFileName(strConfigFileName);
	initialize();
}


/*
    Method initialize the game
    @param strConfigFileName Name of the configuration file
    @param strFontFileName Name and path of the fonts file
*/
void CGame::initialize(const std::string& strConfigFileName, const std::string& strFontFileName)
{
    m_Configuration.setConfigFileName(strConfigFileName);
    m_Configuration.setFontFileName(strFontFileName);
    initialize();
}

#pragma endregion	// End of region initialize of game


#pragma region Create and respawn methods


/* Method create a player */
void CGame::createPlayer()
{
	std::cout << "Create player" << std::endl;

	// Create new player
	std::shared_ptr<CEntity> entity = m_EntityCreation.createPlayer(m_Window, m_EntityManager, m_Configuration);

	m_Player = entity;
}


/*
	Method create a bullet moving from entity position to mousePosition
	@param shootingEntity Reference to entity with a position that is the starting point for the bullet
	@param mousePosition Point where the bullet shall go
*/
void CGame::createBullet(std::shared_ptr<CEntity>& shootingEntity, const sf::Vector2i& mousePosition)
{
	// Create a new bullet
	m_EntityCreation.createBullet(m_Window, m_EntityManager, m_Configuration, shootingEntity, mousePosition);
}


/*
	Method create a special weapon effect moving from entity position to mousePosition
	@param shootingEntity Reference to entity with a position that is the starting point for the special weapon effect
	@param mousePosition Point where the special weapons effect shall go
*/
void CGame::createSpecialWeapon(std::shared_ptr<CEntity>& shootingEntity, const sf::Vector2i& mousePosition)
{
	// TODO Special weapon is a upcoming function
}


/* Method create a new enemy entity */
void CGame::createEnemy()
{
	std::cout << "Create enemy" << std::endl;

	m_bSpawnNewEnemy = false;

	// Create new enemy
	m_EntityCreation.createEnemy(m_Window, m_EntityManager, m_Configuration, m_Player);

	m_iLastEnemySpawnTime = m_uiCurrentFrame;
}


/* Method create  GUI entities */
void CGame::createGui()
{
	sf::Vector2u vecWindowSize = m_Window.getSize();

	int iNumberOfBoxes = vecWindowSize.x / 50;

	int iStartPos = 0;
	for (int i = 0; i <= iNumberOfBoxes; i++)
	{
		auto entity = m_EntityManager.addEntity(GUI);

		// Create the shape
		//								   CShape(float fRadius, int iPoints, const sf::Color fillColor, const sf::Color outlineColor, float fOutlineThickness)
		entity->cShape = std::make_shared<CShape>(50.0f, 4, sf::Color(28, 128, 187, 100), sf::Color(40, 40, 40), 0.0f);

		entity->cShape->getShape().setPosition((float)iStartPos, 0);

		// Add a transform component to the enemy
	    //                                     CTransform(const sf::Vector2f& pos, const sf::Vector2f& vel, float fAngle, float fRotationSpeed)
		entity->cTransform = std::make_shared<CTransform>(sf::Vector2f((float)iStartPos, 0.0f), sf::Vector2f(0.0f, 0.0f), 45.0f, 0.0f);

		iStartPos += 70;
	}
}


/* Method respawn the player */
void CGame::respawnPlayer()
{
	if (m_Player != nullptr)
	{
		if (m_Player->isDead() && m_Player->getRespawn())
		{// Respawn the player. 

			// Clear input before respawn the player
			m_Player->cInput->leftMouseDown = false;
			m_Player->cInput->rigthMouseDown = false;
			m_Player->cInput->up = false;
			m_Player->cInput->down = false;
			m_Player->cInput->left = false;
			m_Player->cInput->right = false;
			m_Player->cInput->die = false;

			float fRadius = m_Player->cShape->getShape().getRadius();
			m_Player->cShape->getShape().setOrigin(fRadius, fRadius);

			float fRotationSpeed = m_Configuration.getPlayerConfig().getRotationSpeed();
			m_Player->cTransform->rotationSpeed = fRotationSpeed;

			// Move player to random position in the screen
			sf::Vector2u vecSize = m_Window.getSize();
			int iCollisionBoxRadius3 = m_Configuration.getPlayerConfig().getCollisionBoxRadius() * 3;

			int iRandomX = m_Helpers.getRandomNumber(0 + iCollisionBoxRadius3, vecSize.x - iCollisionBoxRadius3);
			int iRandomY = m_Helpers.getRandomNumber(0 + iCollisionBoxRadius3, vecSize.y - iCollisionBoxRadius3);

			m_Player->cShape->getShape().setPosition(sf::Vector2f((float)iRandomX, (float)iRandomY));
			m_Player->cTransform->position = sf::Vector2f((float)iRandomX, (float)iRandomY);

			// Move player to the center of the screen
			//sf::Vector2u vecSize = m_Window.getSize();
			//float fCenterX = vecSize.x / 2.0f;
			//float fCenterY = vecSize.y / 2.0f;
			//m_Player->cTransform->position = sf::Vector2f(fCenterX, fCenterY);

			float fSpeed = m_Configuration.getPlayerConfig().getSpeed();
			m_Player->cTransform->velocity = sf::Vector2f(fSpeed, fSpeed);
			m_Player->cTransform->angle = 0.0f;

			m_Player->cShape->getShape().setFillColor(m_Configuration.getPlayerConfig().getFillColor());
			m_Player->cShape->getShape().setOutlineColor(m_Configuration.getPlayerConfig().getOutlineColor());

			m_Player->cLifespan = nullptr;

			m_Player->setRespawn(false);
			m_Player->isDead(false);

			std::cout << "Respawn player" << std::endl;
		}
	}
}

#pragma endregion	// End of region Create and respawn methods


#pragma region System methods

/***** System methods *****/

/* System method that handles updates of the gui */
void CGame::sGuiHandling()
{
	std::string strTimes = this->m_PlayerNumberOfTimeKilled == 1 ? " time" : " times";
	m_NumberOfDeathsText.setString("You have been killed " + std::to_string(this->m_PlayerNumberOfTimeKilled) + strTimes);

	sf::Vector2u vecWindowSize = m_Window.getSize();

	// Position the number of times you have been killed in the window
	sf::FloatRect fRect = m_NumberOfDeathsText.getGlobalBounds();
	float fTextXPos = ((float)(vecWindowSize.x / 2)) - (fRect.width / 2.0f);
	float fTextYPos = 5.0f;

	m_NumberOfDeathsText.setPosition(fTextXPos, fTextYPos);

	if (m_Player->cScore != nullptr)
		m_ScoreText.setString("Score " + std::to_string(m_Player->cScore->score));


	// Position the number of kills messages
	strTimes = m_Player->cScore->numberOfKills == 1 ? " enemy" : " enemies";
	m_NumberOfKilledText.setString("You have killed " + std::to_string(m_Player->cScore->numberOfKills) + strTimes);

	fRect = m_NumberOfKilledText.getGlobalBounds();
	fTextXPos = (((float)vecWindowSize.x) - fRect.width - 10.0f);
	fTextYPos = 5.0f;
	m_NumberOfKilledText.setPosition(fTextXPos, fTextYPos);
}


/* System method that handle player actions respan, create bullets and create special effects */
void CGame::sPlayerHandling()
{
	if (m_Player != nullptr)
	{
		if (m_Player->isDead() && m_Player->getRespawn())
		{// Respawn the player. 
			respawnPlayer();
		}
		else
		{
			if (m_Player->cInput->leftMouseDown)
			{
				// std::cout << "Left mouse button clicked at (" << m_Player->cInput->iLeftMouseDownPositionX << ", " << m_Player->cInput->iLeftMouseDownPositionY << ")" << std::endl;

				if(!m_Player->isDead())
					createBullet(m_Player, sf::Vector2i(m_Player->cInput->iLeftMouseDownPositionX, m_Player->cInput->iLeftMouseDownPositionY));

				m_Player->cInput->leftMouseDown = false;
			}

			if (m_Player->cInput->rigthMouseDown)
			{
				// std::cout << "Right mouse button clicked at (" << m_Player->cInput->iRightMouseDownPositionX << ", " << m_Player->cInput->iRightMouseDownPositionY << ")" << std::endl;

				if (!m_Player->isDead())
					createSpecialWeapon(m_Player, sf::Vector2i(m_Player->cInput->iRightMouseDownPositionX, m_Player->cInput->iRightMouseDownPositionY));

				m_Player->cInput->rigthMouseDown = false;
			}
		}		
	}	
}


/* System method that handle creation of enemies 
	System: Handles the creation of new enemies
*/
void CGame::sEnemyCreation()			
{
	if (m_bSpawnNewEnemy)
	{
		if((m_uiCurrentFrame - m_iLastEnemySpawnTime) > 120)
			createEnemy();
	}
}


/* System method that handles enteties that has a lifespan added to them */
void CGame::sLifespan()
{
	if (m_Player != nullptr)
	{
		if (m_Player->isDead())
		{// Player is dead. Change transparency of shape until the respawn time ends

			if (m_Player->cLifespan != nullptr)
			{
				if (m_Player->cLifespan->remaining > 0)
				{
					m_Player->setRespawn(false);

					sf::Color color = m_Player->cShape->getShape().getFillColor();
					color.a = color.a > 2 ? color.a - 2 : color.a = 0;
					m_Player->cShape->getShape().setFillColor(color);
				}
			}
		}
	}


	// Update all entities
	for (auto& entity : m_EntityManager.getEntities())
	{
		if (!entity->getDestroy())
		{
			if (entity->cLifespan != nullptr)
			{// We have a entity with lifespan. Is it time to destroy it or not

				entity->cLifespan->remaining--;

				if (entity->cLifespan->remaining <= 0)
				{
					entity->cLifespan = nullptr;

					if (entity->getTypeOfEntity() == PLAYER)	// I dont want to destroy PLAYER. We shall respawn that entity
					{
						m_Player->setRespawn(true);
					}
					else
					{
						m_EntityManager.m_NumberOfEntitiesToBeRemoved++;
						entity->isDead(true);
						entity->destroy();
					}
				}
			}
		}
	}
}


/* System method that update entities position before rendering */
void CGame::sMovement()
{
	if (m_Player != nullptr)
	{
		float fPlayerSpeed = m_Configuration.getPlayerConfig().getSpeed();

		// If player is moving. We update it here
		m_Player->cTransform->velocity = { 0.0f, 0.0f };

		if (m_Player->cInput->up)
			m_Player->cTransform->velocity.y = -fPlayerSpeed;

		if (m_Player->cInput->down)
			m_Player->cTransform->velocity.y = fPlayerSpeed;

		if (m_Player->cInput->left)
			m_Player->cTransform->velocity.x = -fPlayerSpeed;

		if (m_Player->cInput->right)
			m_Player->cTransform->velocity.x = fPlayerSpeed;

		if (m_Player->cInput->die)
		{
			m_Player->cLifespan = std::make_shared<CLifespan>(this->m_Configuration.getPlayerConfig().getRespawnInterval());
			m_Player->isDead(true);
		}
	}


	// Update all entities
	for (auto& entity : m_EntityManager.getEntities())
	{
		if (!entity->getDestroy() && !entity->isDead() && entity->getTypeOfEntity() != GUI)
		{// We shall update the entity. Update its position

			entity->cTransform->position += entity->cTransform->velocity;
			entity->cShape->getShape().setPosition(entity->cTransform->position);
		}
	}
}


/* System method that render objects to the screen */
void CGame::sRender()
{
	int iHealth = 0;
	sf::Color fillColor;

	// Clear backbuffer
	m_Window.clear();

	// draw to backbuffer
	for (auto& entityEnemy : m_EntityManager.getEntities("ENEMY"))
	{
		if (!entityEnemy->getDestroy())
		{// We shall draw this entity

			fillColor = entityEnemy->cShape->getShape().getFillColor();
			iHealth = entityEnemy->cHealth->health;
			fillColor.a = iHealth;
			entityEnemy->cShape->getShape().setFillColor(fillColor);

			// Rotate shape
			entityEnemy->cTransform->angle += entityEnemy->cTransform->rotationSpeed;

			if (entityEnemy->cTransform->angle > 360.0f)
				entityEnemy->cTransform->angle = 0.0f;

			entityEnemy->cShape->getShape().setRotation(entityEnemy->cTransform->angle);
			m_Window.draw(entityEnemy->cShape->getShape());
		}
	}

	for (auto& entityBullet : m_EntityManager.getEntities("BULLET"))
	{
		if (!entityBullet->getDestroy())
		{// We shall draw this entity
			m_Window.draw(entityBullet->cShape->getShape());
		}
	}


	// Draw player
	// Rotate shape
	m_Player->cTransform->angle += m_Player->cTransform->rotationSpeed;

	if (m_Player->cTransform->angle > 360.0f)
		m_Player->cTransform->angle = 0.0f;

	m_Player->cShape->getShape().setRotation(m_Player->cTransform->angle);
	m_Window.draw(m_Player->cShape->getShape());


	// Draw gui entities
	for (auto& entityGUI : m_EntityManager.getEntities("GUI"))
	{// We shall draw this entity
		entityGUI->cShape->getShape().setRotation(entityGUI->cTransform->angle);
		m_Window.draw(entityGUI->cShape->getShape());
	}

	// Show text with information
	m_Window.draw(m_ScoreText);

	m_Window.draw(m_NumberOfDeathsText);

	if (m_Player->isDead())
		m_Window.draw(m_YouAreKilledMessageText);

	m_Window.draw(m_NumberOfKilledText);

    // show backbuffer
	m_Window.display();

	m_uiCurrentFrame++;
}


/* System method that handles input from mouse and the keyboard */
void CGame::sUserInput()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_bRunning = false;
			//m_Window.close();
		}

		if (m_Player == nullptr)
		{// We have no player. Only accept escape key

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						m_bRunning = false;
						break;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						m_bRunning = false;
						break;
				}
			}

			return;
		}


		// this event is triggered when a key is pressed
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_bRunning = false;
				break;
			case sf::Keyboard::W:
				// std::cout << "Key W was presses" << std::endl;
				m_Player->cInput->up = true;
				break;
			case sf::Keyboard::S:
				// std::cout << "Key S was presses" << std::endl;
				m_Player->cInput->down = true;
				break;
			case sf::Keyboard::A:
				// std::cout << "Key A was presses" << std::endl;
				m_Player->cInput->left = true;
				break;
			case sf::Keyboard::D:
				// std::cout << "Key D was presses" << std::endl;
				m_Player->cInput->right = true;
				break;
			case sf::Keyboard::P:
				// Pause game
				this->isPaused(!this->isPaused());
				break;
			case sf::Keyboard::Space:
				m_Player->cInput->die = true;
				break;
			}
		}


		// this event is triggered when a key is released
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				// std::cout << "Key W was released" << std::endl;
				m_Player->cInput->up = false;
				break;
			case sf::Keyboard::S:
				// std::cout << "Key S was released" << std::endl;
				m_Player->cInput->down = false;
				break;
			case sf::Keyboard::A:
				// std::cout << "Key A was released" << std::endl;
				m_Player->cInput->left = false;
				break;
			case sf::Keyboard::D:
				//std::cout << "Key D was released" << std::endl;
				m_Player->cInput->right = false;
				break;
			case sf::Keyboard::Space:
				m_Player->cInput->die = false;
				break;
			}
		}

		if (!this->isPaused())
		{
			// this event is triggered when a mousebutton is pressed
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//std::cout << "Left mouse button clicked at (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
					m_Player->cInput->leftMouseDown = true;
					m_Player->cInput->iLeftMouseDownPositionX = event.mouseButton.x;
					m_Player->cInput->iLeftMouseDownPositionY = event.mouseButton.y;
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					//std::cout << "Rigth mouse button clicked at (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
					m_Player->cInput->rigthMouseDown = true;
					m_Player->cInput->iRightMouseDownPositionX = event.mouseButton.x;
					m_Player->cInput->iRightMouseDownPositionY = event.mouseButton.y;
				}
			}
		}
	}
}


/* System method that handles collision with the window borders and otehr enteties in the game */
void CGame::sCollision()
{
	CDirection directionToCollision;

	if (m_Player != nullptr)
	{
		// Check if player collided with the windows border
		directionToCollision = this->m_CollisionHelpers.IsCollision(m_Window, m_Player);

		if (directionToCollision.HorizontalDirection == LEFT)
			m_Player->cInput->left = false;
		else if (directionToCollision.HorizontalDirection == RIGHT)
			m_Player->cInput->right = false;

		if (directionToCollision.VerticalDirection == UP)
			m_Player->cInput->up = false;
		else if (directionToCollision.VerticalDirection == DOWN)
			m_Player->cInput->down = false;
	}


	// Now check collisions between player and enemies and enemies and the window border
	for (auto& entityEnemy : m_EntityManager.getEntities("ENEMY"))
	{
		if (entityEnemy->cCollision != nullptr)
		{
			if (m_Player != nullptr && !m_Player->isDead())
			{// Check collision between player and enemy

				if (this->m_CollisionHelpers.IsCollision(m_Player, entityEnemy))
				{// We have a collision

					this->m_PlayerNumberOfTimeKilled++;
					m_Player->isDead(true);
					m_Player->cLifespan = std::make_shared<CLifespan>(this->m_Configuration.getPlayerConfig().getRespawnInterval());

					m_EntityManager.m_NumberOfEntitiesToBeRemoved++;
					entityEnemy->isDead(true);
					entityEnemy->destroy();
					// std::cout << "Player collided with enemy (" << entityEnemy->getId() << ")" << std::endl;

					m_bSpawnNewEnemy = true;
					m_iLastEnemySpawnTime = m_uiCurrentFrame;
				}
			}

			// Check if enemy collided with a window border
			directionToCollision = this->m_CollisionHelpers.IsCollision(m_Window, entityEnemy);

			if (directionToCollision.HorizontalDirection == LEFT)
				entityEnemy->cTransform->velocity.x *= -1;
			else if (directionToCollision.HorizontalDirection == RIGHT)
				entityEnemy->cTransform->velocity.x *= -1;

			if (directionToCollision.VerticalDirection == UP)
				entityEnemy->cTransform->velocity.y *= -1;
			else if (directionToCollision.VerticalDirection == DOWN)
				entityEnemy->cTransform->velocity.y *= -1;
		}
	}// End of for entityEnemy


	// Now we check if a bullet has collided with something
	for (auto& entityBullet : m_EntityManager.getEntities("BULLET"))
	{ 
		if (entityBullet->cCollision != nullptr && !entityBullet->isDead())
		{
			if (!entityBullet->isDead())
			{// We have a bullet. now we do collision detection with a enemy entities

				for (auto& entityEnemy : m_EntityManager.getEntities("ENEMY"))
				{
					if (this->m_CollisionHelpers.IsCollision(entityBullet, entityEnemy))
					{// We have a collision

						m_EntityManager.m_NumberOfEntitiesToBeRemoved++;
						entityEnemy->cHealth->health -= entityBullet->cDamage->damage;
						m_Player->cScore->score += entityBullet->cDamage->damage;

						if (entityEnemy->cHealth->health <= 0)
						{							
							m_Player->cScore->numberOfKills += 1;
							entityEnemy->isDead(true);
							entityEnemy->destroy();

							// TODO First version. We only have one enemy
							m_bSpawnNewEnemy = true;
							m_iLastEnemySpawnTime = m_uiCurrentFrame;
						}

						m_EntityManager.m_NumberOfEntitiesToBeRemoved++;
						entityBullet->isDead(true);
						entityBullet->destroy();

						// std::cout << "Bullet (" << entityBullet->getId() << ") collided with a Enemy (" << entityEnemy->getId() << ")" << std::endl;
					}
				}// End of for entityEnemy 
			}
		}
	}// End of for entityBullet
}

#pragma endregion	//End of region System methods