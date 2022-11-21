#include "CEntityManager.h"


/* Method add new entities and remove entities that shall be destroyd */
void CEntityManager::update()
{
	// If we shall add entities we do it here
	for (auto& entity : m_EntitiesToAdd)
	{
		m_Entities.push_back(entity);
		m_EntitiesMap[m_Helpers.Type_of_Entity_ToString(entity->getTypeOfEntity())].push_back(entity);

		//std::cout << "m_EntitiesToAdd update: " << std::to_string(m_Entities.size()) << ", m_EntitiesMap: " << m_EntitiesMap[m_Helpers.Type_of_Entity_ToString(entity->getTypeOfEntity())].size() << std::endl;
	}

	m_EntitiesToAdd.clear();


	// Check if we shall remove entities
	if (this->m_NumberOfEntitiesToBeRemoved > 0)
	{// We shall remove entities that is marked as destroyed
		removeDestroyedEntities("NOPE", m_Entities);

		for (auto& [key, vec] : m_EntitiesMap)
			removeDestroyedEntities(key, vec);
	}

	this->m_NumberOfEntitiesToBeRemoved = 0;
}


/* 
	Method add a new entity of a type 
	@param typeOfEntity enum with the type of entity 
	@return Pointer to the new entity
*/
std::shared_ptr<CEntity> CEntityManager::addEntity(Type_of_Entity typeOfEntity)
{
	auto entity = std::shared_ptr<CEntity>(new CEntity(++this->m_NumberOfEntitiesCreated, typeOfEntity));
	
	m_EntitiesToAdd.push_back(entity);
		
	//std::cout << "addEntity m_EntitiesToAdd: " << std::to_string(m_EntitiesToAdd.size()) << ", m_EntitiesMap: " << m_EntitiesMap[m_Helpers.Type_of_Entity_ToString(typeOfEntity)].size() << std::endl;

	return entity;
}


/*
	Method return std::vector of entities of a type
	@param strTypeOfEntity Type of entity as a string
	@return std::vector The entities of a specific type
*/
std::vector<std::shared_ptr<CEntity>> CEntityManager::getEntities(std::string strTypeOfEntity)
{	
	return m_EntitiesMap[strTypeOfEntity];
}


/*
	Method return std::vector of entities of a type
	@param typeOfEntity Type of entity as a enum
	@return std::vector The entities of a specific type
*/
std::vector<std::shared_ptr<CEntity>> CEntityManager::getEntities(Type_of_Entity typeOfEntity)
{
	return getEntities(m_Helpers.Type_of_Entity_ToString(typeOfEntity));
}


/*
	Method remove destroyed entities from std::vector
	@param strKey The key from the std::map. I only used this for output to the console
	@param vect std::vector with entities where we shall remove entities that are marked as destroyed
*/
void CEntityManager::removeDestroyedEntities(std::string strKey, std::vector<std::shared_ptr<CEntity>>& vec)
{	
	vec.erase(
		std::remove_if(vec.begin(), vec.end(), [](std::shared_ptr<CEntity> entity) { return entity->getDestroy(); }),
		vec.end()
	);

	//std::cout << "removeDestroyedEntities: " << std::to_string(vec.size()) << ", m_EntitiesMap: " << m_EntitiesMap[strKey].size() << ", strKey: " << strKey << std::endl;
}

