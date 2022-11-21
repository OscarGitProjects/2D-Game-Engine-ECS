#pragma once
#include <string>
#include<memory>
#include "../enums.h"
#include "../Components/CInput.h"
#include "../Components/CShape.h"
#include "../Components/CTransform.h"
#include "../Components/CLifespan.h"
#include "../Components/CCollision.h"
#include "../Components/CHealth.h"
#include "../Components/CScore.h"
#include "../Components/CDamage.h"


/*
	CEntity.h
	CEntity class with varaiables and methods for different entities in the game
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0 
*/
class CEntity
{
private:
	friend class CEntityManager;

	std::string m_strTag = "default";

	bool m_bActive = true;					// true if inactive entity
	bool m_bDead = false;					// Entity is dead. if m_bDestroy is true we remove entity
	int m_iId = 0;							// Id
	Type_of_Entity m_Type_Of_Entity = NA;	// Type of entity. ex. NA, PLAYER, ENEMY or BULLET
	bool m_bDestroy = false;				// true if we shall remove the entity
	bool m_bRespawn = false;				// true when it is time to respawn

	/*
		Private Constructor
		@param iId Id for the entity
		@param typeOfEntity Type of entity
	*/
	CEntity(const int iId, const Type_of_Entity& typeOfEntity);

public:
	bool getRespawn() { return m_bRespawn; }
	void setRespawn(bool bRespawn) { m_bRespawn = bRespawn; }

	// Pointers to Components
	std::shared_ptr<CTransform> cTransform = nullptr;
	std::shared_ptr<CShape> cShape = nullptr;
	std::shared_ptr<CCollision> cCollision = nullptr;
	std::shared_ptr<CInput> cInput = nullptr;
	std::shared_ptr<CScore> cScore = nullptr;
	std::shared_ptr<CHealth> cHealth = nullptr;
	std::shared_ptr<CDamage> cDamage = nullptr;
	std::shared_ptr<CLifespan> cLifespan = nullptr;
	

	// get methods

	/* 
		Method sheck if entity is active or not 
		@return true if entity is active. Otherwise return false 
	*/
	bool isActive() { return m_bActive; }

	/* 
		Method check if entity is dead or not 
		@return true if its dead. Otherwise return false
	*/
	bool isDead() { return m_bDead; }

	/* 
		Method return Id for this entity 
		@return Id 
	*/
	int getId() { return m_iId; }

	/* 
		Method return type of entity 
		@return enum type of entity with information about type 
	*/
	Type_of_Entity getTypeOfEntity() { return m_Type_Of_Entity; }

	/* 
		Method return if entity shall be destroyed or not 
		@return true if entity shall be destroyed. Otherwise false 
	*/
	bool getDestroy() { return m_bDestroy; }


	// set methods


	/* 
		Method set if entity is active or not 
		@param bActive true if entity is active. Otherwise false 
	*/
	void isActive(bool bActive) { m_bActive = bActive; }


	/*
		Method set if entity is dead or not
		@param bDead true if its dead. Otherwise return false
	*/
	void isDead(bool bDead) { m_bDead = bDead; }


	/*
		Method set Id for this entity
		@param Id
	*/
	void setId(int iId) { m_iId = iId; }


	/*
		Method set type of entity
		@set type_Of_Entity enum type of entity with information about type
	*/
	void getTypeOfEntity(Type_of_Entity type_Of_Entity) { m_Type_Of_Entity = type_Of_Entity; }


	/*
		Method set if entity shall be destroyed or not
		@param bDestroy true if entity shall be destroyed. Otherwise false
	*/
	void setDestroy(bool bDestroy) { m_bDestroy = bDestroy; }


	/***** Methods *****/


	/* Method set the destroy flag for this entity */
	void destroy() { m_bDestroy = true; }
};