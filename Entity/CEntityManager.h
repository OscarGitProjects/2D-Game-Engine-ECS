#pragma once
#include <vector>
#include <memory>
#include <iostream>

#include "CEntity.h"
#include "../Helpers/CHelpers.h"


/*
	CEntityManager.h
	CEntityManager class that handles the entities in the game
	@author Oscar Andersson
	@date 2022-11-14
	@version 1.0
*/
class CEntityManager
{
private: 
	/* Class with method that convert enum Type_of_Entity to a std::string */
	CHelpers m_Helpers;

	/* std::vector with all entities */
	std::vector<std::shared_ptr<CEntity>> m_Entities;		

	/* std::map with pointers to std::vector with entities.The key is the type of entity */
	std::map<std::string, std::vector<std::shared_ptr<CEntity>>> m_EntitiesMap;		

	/* std::vector with pointers to entities we shall add */
	std::vector<std::shared_ptr<CEntity>> m_EntitiesToAdd;

public:
	/* Number of entities that shall be removed. I use this to know if we shall remove entities from m_Entities and m_EntitiesMap */
	int m_NumberOfEntitiesToBeRemoved = 0;

	/* I use this as a unik id for every new entity that is created */
	int m_NumberOfEntitiesCreated = 0;


	/***** Methods *****/


	/* Method add new entities and remove entities that shall be destroyd */
	void update();


	/*
		Method add a new entity of a type
		@param typeOfEntity enum with the type of entity
		@return Pointer to the new entity
	*/
	std::shared_ptr<CEntity> addEntity(Type_of_Entity typeOfEntity);


	/* 
		Method return std::vector with the entities 
		@return std::vector The entities 
	*/
	std::vector<std::shared_ptr<CEntity>> getEntities() { return m_Entities; }


	/*	
		Method return std::vector of entities of a type 
		@param strTypeOfEntity Type of entity as a string 
		@return std::vector The entities of a specific type 
	*/
	std::vector<std::shared_ptr<CEntity>> getEntities(std::string strTypeOfEntity);


	/*	
		Method return std::vector of entities of a type 
		@param typeOfEntity Type of entity as a enum
		@return std::vector The entities of a specific type 
	*/
	std::vector<std::shared_ptr<CEntity>> getEntities(Type_of_Entity typeOfEntity);

	
	/* 
		Method remove destroyed entities from std::vector 
		@param strKey The key from the std::map
		@param vect std::vector with entities where we shall remove entities that are marked as destroyed 
	*/
	void removeDestroyedEntities(std::string strKey, std::vector<std::shared_ptr<CEntity>>& vec);
};