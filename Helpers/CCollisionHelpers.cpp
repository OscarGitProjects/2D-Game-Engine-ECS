#include "CCollisionHelpers.h"

/*
	Method detect collision between entity and the windows borders
	@param Reference to the sf::RenderWindow object
	@param Reference to the entity
	@return CDirection class with the Direction which border we collided with
*/
CDirection CCollisionHelpers::IsCollision(const sf::RenderWindow& window, const std::shared_ptr<CEntity> entity) const
{
	CDirection direction;

	sf::Vector2u vecWindowSize = window.getSize();
	sf::Vector2f vecEntityPosition = entity->cShape->getShape().getPosition();
	float fEntityCollisionRadius = entity->cCollision->radius + entity->cShape->getShape().getOutlineThickness();

	if (vecEntityPosition.x - fEntityCollisionRadius <= 0)
	{// Check the left side of the window
		direction.HorizontalDirection = LEFT;
		//std::cout << "Entity(" << std::to_string(entity->getId()) << ") collided with window left" << std::endl;
	}
	else if (vecEntityPosition.x + fEntityCollisionRadius >= vecWindowSize.x)
	{// Check the right side of the window
		direction.HorizontalDirection = RIGHT;
		//std::cout << "Entity(" << std::to_string(entity->getId()) << ") collided with window right" << std::endl;
	}

	if (vecEntityPosition.y - fEntityCollisionRadius <= 35)
	{// Check the top of the window
		direction.VerticalDirection = UP;
		//std::cout << "Entity(" << std::to_string(entity->getId()) << ") collided with window top" << std::endl;
	}
	else if (vecEntityPosition.y + fEntityCollisionRadius >= vecWindowSize.y)
	{// Check the bottom of the window
		direction.VerticalDirection = DOWN;
		//std::cout << "Entity(" << std::to_string(entity->getId()) << ") collided with window down" << std::endl;
	}

	return direction;
}


/*
	Method detect collision between two entities
	@param std::shared_ptr to entity
	@param std::shared_ptr to entity
	@return true if entities is colliding. Otherwise returns false
*/
bool CCollisionHelpers::IsCollision(const std::shared_ptr<CEntity> entity1, const std::shared_ptr<CEntity> entity2) const
{
	if (entity1 != nullptr && entity2 != nullptr)
	{
		sf::Vector2f vecEntity1Position = entity1->cShape->getShape().getPosition();
		sf::Vector2f vecEntity2Position = entity2->cShape->getShape().getPosition();

		float fDistX = vecEntity1Position.x - vecEntity2Position.x;
		float fDistY = vecEntity1Position.y - vecEntity2Position.y;
		float fTotRadius = entity1->cCollision->radius + entity2->cCollision->radius + entity1->cShape->getShape().getOutlineThickness() + entity2->cShape->getShape().getOutlineThickness();

		if (((fDistX * fDistX) + (fDistY * fDistY)) < (fTotRadius * fTotRadius))
		{
			//std::cout << "Collision between Entity(" << std::to_string(entity1->getId()) << ") and Entity(" << std::to_string(entity2->getId()) << ")" << std::endl;
			return true;
		}
	}

	return false;
}
