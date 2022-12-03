#include "CEntityCreation.h"


/*
	Method create a player entity
	@param window Reference to sf::RenderWindow object
	@param entityManager Reference to entity manager object
	@param configuration Reference to CConfiguration object
	@return std::shared_ptr to the player entity
*/
std::shared_ptr<CEntity> CEntityCreation::createPlayer(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration)
{
	auto entity = entityManager.addEntity(PLAYER);

	// Create the shape
	//								   CShape(float fRadius, int iPoints, const sf::Color fillColor, const sf::Color outlineColor, float fOutlineThickness)
	entity->cShape = std::make_shared<CShape>((float)configuration.getPlayerConfig().getShapeRadius(),
		configuration.getPlayerConfig().getNumberOfVerticesForShape(), configuration.getPlayerConfig().getFillColor(),
		configuration.getPlayerConfig().getOutlineColor(), (float)configuration.getPlayerConfig().getOutlineThickness());

	float fRadius = entity->cShape->getShape().getRadius();
	entity->cShape->getShape().setOrigin(fRadius, fRadius);

	float fRotationSpeed = configuration.getPlayerConfig().getRotationSpeed();
	float fSpeed = configuration.getPlayerConfig().getSpeed();

	// Create player in the screen
	sf::Vector2u vecSize = window.getSize();
	int iCollisionBoxRadius3 = configuration.getPlayerConfig().getCollisionBoxRadius() * 3;

	int iRandomX = m_Helpers.getRandomNumber(iCollisionBoxRadius3, vecSize.x - iCollisionBoxRadius3);
	int iRandomY = m_Helpers.getRandomNumber(iCollisionBoxRadius3, vecSize.y - iCollisionBoxRadius3);

	entity->cShape->getShape().setPosition(sf::Vector2f((float)iRandomX, (float)iRandomY));

	// Add a transform component to the player
	//                                     CTransform(const sf::Vector2f& pos, const sf::Vector2f& vel, float fAngle, float fRotationSpeed)
	entity->cTransform = std::make_shared<CTransform>(sf::Vector2f((float)iRandomX, (float)iRandomY), sf::Vector2f(fSpeed, fSpeed), 0.0f, fRotationSpeed);

	// Add a input component to the player so that we can use inputs
	entity->cInput = std::make_shared<CInput>();

	// Add a collision component to the player
	entity->cCollision = std::make_shared<CCollision>((float)configuration.getPlayerConfig().getCollisionBoxRadius());

	// Add score component to entity
	entity->cScore = std::make_shared<CScore>();

	return entity;
}


/*
	Method create a enemy entity
	@param window Reference to sf::RenderWindow object
	@param entityManager Reference to entity manager object
	@param configuration Reference to CConfiguration object
	@param std::shared_ptr<CEntity> player Reference to the player object. We use this so that we don't create a enemy where the player is
	@return std::shared_ptr to the enemy entity
*/
std::shared_ptr<CEntity> CEntityCreation::createEnemy(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration, std::shared_ptr<CEntity> player)
{
	auto entity = entityManager.addEntity(ENEMY);

	int iMin = configuration.getEnemyConfig().getMinNumberOfVerticesForShape();
	int iMax = configuration.getEnemyConfig().getMaxNumberOfVerticesForShape();
	int iRandomNumberOfVerticesForShape = m_Helpers.getRandomNumber(iMin, iMax);

	// std::cout << "Vertices. Random number between [" << std::to_string(iMin) << ", " << std::to_string(iMax) << "]: " << iRandomNumberOfVerticesForShape << std::endl;

	// Create a random color
	int iRed = m_Helpers.getRandomNumber(0, 255);
	int iGreen = m_Helpers.getRandomNumber(0, 255);
	int iBlue = m_Helpers.getRandomNumber(0, 255);

	// Create the shape
	//								   CShape(float fRadius, int iPoints, const sf::Color fillColor, const sf::Color outlineColor, float fOutlineThickness)
	entity->cShape = std::make_shared<CShape>((float)configuration.getEnemyConfig().getShapeRadius(),
		iRandomNumberOfVerticesForShape, sf::Color(iRed, iGreen, iBlue),
		configuration.getEnemyConfig().getOutlineColor(), (float)configuration.getEnemyConfig().getOutlineThickness());

	//entity->cShape = std::make_shared<CShape>((float)m_Configuration.getEnemyConfig().getShapeRadius(),
	//	m_Configuration.getEnemyConfig().getMinNumberOfVerticesForShape(), sf::Color(100, 100,100),
	//	m_Configuration.getEnemyConfig().getOutlineColor(), (float)m_Configuration.getEnemyConfig().getOutlineThickness());

	float fRadius = entity->cShape->getShape().getRadius();
	entity->cShape->getShape().setOrigin(fRadius, fRadius);

	// Add a collision component to the entity
	entity->cCollision = std::make_shared<CCollision>((float)configuration.getEnemyConfig().getCollisionBoxRadius());

	float fRotationSpeed = configuration.getEnemyConfig().getRotationSpeed();

	// Create a random speed
	iMin = (int)configuration.getEnemyConfig().getMinSpeed();
	iMax = (int)configuration.getEnemyConfig().getMaxSpeed();
	float fSpeedX = (float)m_Helpers.getRandomNumber(iMin, iMax);
	if (fSpeedX <= 0.0f)
		fSpeedX += 1.0f;

	float fSpeedY = fSpeedX;

	// Now i want to determine if we shall have a positive or negative speed
	int iRandSpeedDirection = m_Helpers.getRandomNumber(1, 10);
	if (iRandSpeedDirection <= 5)
		fSpeedX *= -1.0f;

	iRandSpeedDirection = m_Helpers.getRandomNumber(1, 10);
	if (iRandSpeedDirection <= 5)
		fSpeedY *= -1.0f;

	// std::cout << "Speed. Random i change direction. Random number between [" << std::to_string(iMin) << ", " << std::to_string(iMax) << "]: (" << std::to_string(fSpeedX) << ", " << std::to_string(fSpeedY) << ")" << std::endl;

	// Create enemy in the screen
	sf::Vector2u vecSize = window.getSize();
	int iCollisionBoxRadius3 = configuration.getEnemyConfig().getCollisionBoxRadius() * 3;
	int iRandomX = 0;
	int iRandomY = 0;

	do
	{
		iRandomX = m_Helpers.getRandomNumber(iCollisionBoxRadius3, vecSize.x - iCollisionBoxRadius3);
		iRandomY = m_Helpers.getRandomNumber(iCollisionBoxRadius3, vecSize.y - iCollisionBoxRadius3);

		entity->cShape->getShape().setPosition(sf::Vector2f((float)iRandomX, (float)iRandomY));

		// Check if we have a collision with player. If collision we have to try another position for the enemy
	} while (m_CollisionHelpers.IsCollision(player, entity));


	// Add a transform component to the entity
	//                                     CTransform(const sf::Vector2f& pos, const sf::Vector2f& vel, float fAngle, float fRotationSpeed)
	entity->cTransform = std::make_shared<CTransform>(sf::Vector2f((float)iRandomX, (float)iRandomY), sf::Vector2f(fSpeedX, fSpeedY), 0.0f, -fRotationSpeed);

	int iMinHealth = configuration.getEnemyConfig().getMinHealth();
	int iMaxHealth = configuration.getEnemyConfig().getMaxHealth();
	int iHealth = m_Helpers.getRandomNumber(iMinHealth, iMaxHealth);

	std::cout << "Vertices: " << iRandomNumberOfVerticesForShape << ", Health: " << iHealth << ", Speed (" << std::to_string(fSpeedX) << ", " << std::to_string(fSpeedY) << ")" << std::endl;

	// Add health component to entity
	entity->cHealth = std::make_shared<CHealth>(iHealth);
	return entity;
}


/*
	Method create a small enemy entity
	@param window Reference to sf::RenderWindow object
	@param entityManager Reference to entity manager object
	@param configuration Reference to CConfiguration object
	@param std::shared_ptr<CEntity> entityEnemy Reference to the enemie object where we shall cretae the new small enemies
	@param fShottingAngle Angle direction in radius. Its the direction we will move the new entity
*/
std::shared_ptr<CEntity> CEntityCreation::createSmallEntity(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration, std::shared_ptr<CEntity> entityEnemy, float fShottingAngle)
{
	auto entity = entityManager.addEntity(ENEMY);

	entity->setSmallEntity(true);

	sf::CircleShape& shape = entityEnemy->cShape->getShape();

	float fNewShapeRadius = shape.getRadius() / 2.0f;
	int iNumberOfVerticesForShape = (int)shape.getPointCount();

	// Create the shape
	//								   CShape(float fRadius, int iPoints, const sf::Color fillColor, const sf::Color outlineColor, float fOutlineThickness)
	entity->cShape = std::make_shared<CShape>((float)fNewShapeRadius, iNumberOfVerticesForShape, shape.getFillColor(),
		shape.getOutlineColor(), (float)shape.getOutlineThickness());

	float fRadius = shape.getRadius();
	entity->cShape->getShape().setOrigin(fRadius, fRadius);

	// Add a collision component to the entity
	entity->cCollision = std::make_shared<CCollision>((float)fRadius + 4);

	sf::Vector2f vec(cos(fShottingAngle), sin(fShottingAngle));
	sf::Vector2f vecVelocity = entityEnemy->cTransform->velocity;

	vecVelocity.x = vecVelocity.x * vec.x;
	vecVelocity.y = vecVelocity.y * vec.y;

	// Add a transform component to the entity
	//                                     CTransform(const sf::Vector2f& pos, const sf::Vector2f& vel, float fAngle, float fRotationSpeed)
	entity->cTransform = std::make_shared<CTransform>(entityEnemy->cTransform->position, vecVelocity, 0.0f, entityEnemy->cTransform->rotationSpeed);

	int iHealth = entityEnemy->cHealth->health / 2;

	std::cout << "Vertices: " << iNumberOfVerticesForShape << ", Health: " << iHealth << ", Speed (" << std::to_string(vecVelocity.x) << ", " << std::to_string(vecVelocity.y) << ")" << std::endl;

	// Add health component to entity
	entity->cHealth = std::make_shared<CHealth>(iHealth);
	return entity;
}


/*
	Method create a bullet entity
	@param window Reference to sf::RenderWindow object
	@param entityManager Reference to entity manager object
	@param configuration Reference to CConfiguration object
	@param shootingEntity Reference to object that is shooting the bullet
	@param mousePosition Reference to point where we want the bullet to go
	@return std::shared_ptr to the bullet entity
*/
std::shared_ptr<CEntity> CEntityCreation::createBullet(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration, std::shared_ptr<CEntity>& shootingEntity, const sf::Vector2i& mousePosition)
{
	auto entity = entityManager.addEntity(BULLET);

	// Create the shape
	//								   CShape(float fRadius, int iPoints, const sf::Color fillColor, const sf::Color outlineColor, float fOutlineThickness)
	entity->cShape = std::make_shared<CShape>((float)configuration.getBulletConfig().getShapeRadius(),
		configuration.getBulletConfig().getNumberOfVerticesForShape(), configuration.getBulletConfig().getFillColor(),
		configuration.getBulletConfig().getOutlineColor(), (float)configuration.getBulletConfig().getOutlineThickness());

	// Change origin of shape to middle point
	float fRadius = entity->cShape->getShape().getRadius();
	entity->cShape->getShape().setOrigin(fRadius, fRadius);

	sf::Vector2f vecShootingEntityPosition = shootingEntity->cShape->getShape().getPosition();
	sf::Vector2f vecDist(mousePosition.x - vecShootingEntityPosition.x, mousePosition.y - vecShootingEntityPosition.y);
	float fLength = sqrtf((vecDist.x * vecDist.x) + (vecDist.y * vecDist.y));

	// Normalize vector
	sf::Vector2f vecDistNorm(vecDist.x / fLength, vecDist.y / fLength);

	// Calculate velocity for this bullet
	float fSpeed = configuration.getBulletConfig().getSpeed();
	sf::Vector2f velocity(vecDistNorm.x * fSpeed, vecDistNorm.y * fSpeed);

	// Calculate position for start point for the bullet
	float fshootingEntityRadius = shootingEntity->cShape->getShape().getRadius();

	float fshootingEntityRadiusX = fshootingEntityRadius / 2.0f;
	float fshootingEntityRadiusY = fshootingEntityRadiusX;

	if (vecShootingEntityPosition.x > mousePosition.x)
		fshootingEntityRadiusX *= -1;

	if (vecShootingEntityPosition.y > mousePosition.y)
		fshootingEntityRadiusY *= -1;

	sf::Vector2f vecBulletStartPosition(vecShootingEntityPosition.x + fshootingEntityRadiusX, vecShootingEntityPosition.y + fshootingEntityRadiusY);

	float fRotationSpeed = 0.0f;

	// Add a transform component to the bullet
	//                                     CTransform(const sf::Vector2f& pos, const sf::Vector2f& vel, float fAngle, float fRotationSpeed)
	entity->cTransform = std::make_shared<CTransform>(vecBulletStartPosition, velocity, 0.0f, fRotationSpeed);

	// This bullet has a lifetime. We create it here
	entity->cLifespan = std::make_shared<CLifespan>(configuration.getBulletConfig().getLifespan());

	// Add a collision component to bullet
	entity->cCollision = std::make_shared<CCollision>((float)configuration.getBulletConfig().getCollisionBoxRadius());

	// Add a damage component to the bullet
	entity->cDamage = std::make_shared<CDamage>(configuration.getBulletConfig().getDamage());

	return entity;
}


/*
	Method create a bullet entity. For this bullet we use the angle in the CSpecialWeapon for the direction we shall shot the bullet
	@param window Reference to sf::RenderWindow object
	@param entityManager Reference to entity manager object
	@param configuration Reference to CConfiguration object
	@param shootingEntity Reference to object that is shooting the bullet
	@return std::shared_ptr to the bullet entity
*/
std::shared_ptr<CEntity> CEntityCreation::createSpecialWeaponsBullet(sf::RenderWindow& window, CEntityManager& entityManager, CConfiguration& configuration, std::shared_ptr<CEntity>& shootingEntity)
{
	auto entity = entityManager.addEntity(BULLET);

	// Create the shape
	//								   CShape(float fRadius, int iPoints, const sf::Color fillColor, const sf::Color outlineColor, float fOutlineThickness)
	entity->cShape = std::make_shared<CShape>((float)configuration.getBulletConfig().getShapeRadius(),
		configuration.getBulletConfig().getNumberOfVerticesForShape(), configuration.getBulletConfig().getFillColor(),
		configuration.getBulletConfig().getOutlineColor(), (float)configuration.getBulletConfig().getOutlineThickness());

	// Change origin of shape to middle point
	float fRadius = entity->cShape->getShape().getRadius();
	entity->cShape->getShape().setOrigin(fRadius, fRadius);

	sf::Vector2f vecShootingEntityPosition = shootingEntity->cShape->getShape().getPosition();

	float fCurrentAngle = shootingEntity->cSpecialWeapon->currentAngle;

	//std::cout << "Current Angle: " << fCurrentAngle * (180/M_PI) << std::endl;

	sf::Vector2f vec(cos(fCurrentAngle), sin(fCurrentAngle));

	// Calculate velocity for this bullet
	float fSpeed = configuration.getBulletConfig().getSpeed();
	sf::Vector2f velocity(vec.x * fSpeed, vec.y * fSpeed);

	// Calculate position for start point for the bullet
	float fshootingEntityRadius = shootingEntity->cShape->getShape().getRadius();

	float fshootingEntityRadiusX = fshootingEntityRadius / 2.0f;
	float fshootingEntityRadiusY = fshootingEntityRadiusX;

	//if (vecShootingEntityPosition.x > mousePosition.x)
	//	fshootingEntityRadiusX *= -1;

	//if (vecShootingEntityPosition.y > mousePosition.y)
	//	fshootingEntityRadiusY *= -1;

	sf::Vector2f vecBulletStartPosition(vecShootingEntityPosition.x + fshootingEntityRadiusX, vecShootingEntityPosition.y + fshootingEntityRadiusY);

	float fRotationSpeed = 0.0f;

	// Add a transform component to the bullet
	//                                     CTransform(const sf::Vector2f& pos, const sf::Vector2f& vel, float fAngle, float fRotationSpeed)
	entity->cTransform = std::make_shared<CTransform>(vecBulletStartPosition, velocity, 0.0f, fRotationSpeed);

	// This bullet has a lifetime. We create it here
	entity->cLifespan = std::make_shared<CLifespan>(configuration.getBulletConfig().getLifespan());

	// Add a collision component to bullet
	entity->cCollision = std::make_shared<CCollision>((float)configuration.getBulletConfig().getCollisionBoxRadius());

	// Add a damage component to the bullet
	entity->cDamage = std::make_shared<CDamage>(configuration.getBulletConfig().getDamage());

	return entity;
}
