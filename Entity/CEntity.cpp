#include "CEntity.h"


/* 
	Constructor 
	@param iId Id for the entity 
	@param typeOfEntity Type of entity 
*/
CEntity::CEntity(const int iId, const Type_of_Entity& typeOfEntity)
	: m_iId(iId), m_Type_Of_Entity(typeOfEntity)
{

}