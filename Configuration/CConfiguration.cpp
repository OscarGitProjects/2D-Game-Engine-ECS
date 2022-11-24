#include "CConfiguration.h"


/*
	Constructor
	@param strConfigFileName Name of the configuration file
*/
CConfiguration::CConfiguration(std::string strConfigFileName)
	:m_strConfigFileName(strConfigFileName)
{}


/*
	Constructor
	@param strConfigFileName Name of the configuration file
	@param strFontFileName Name and path of the fonts file
*/
CConfiguration::CConfiguration(std::string strConfigFileName, std::string strFontFileName)
	:m_strConfigFileName(strConfigFileName), m_strFontFileName(strFontFileName)
{}


/*
	Method load configurations from the config file
	@param strConfigFileName Name of the configuration file
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadConfigurations(std::string strConfigFileName)
{
	m_strConfigFileName = strConfigFileName;
	return LoadConfigurations();
}


/*
	Method load configurations from the config file
	@param strConfigFileName Name of the configuration file
	@param strFontFileName Name and path of the fonts file
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadConfigurations(std::string strConfigFileName, std::string strFontFileName)
{
	m_strConfigFileName = strConfigFileName;
	m_strFontFileName = strFontFileName;
	return LoadConfigurations();
}


/*
	Method load configurations from the config file. The configuration files name has to be set in this class
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadConfigurations()
{
	// TODO Implement LoadConfigurations()

	bool bWindowConfigLoaded = LoadWindowConfigurations();
	bool bFontConfigLoaded = LoadFontConfigurations();
	bool bPlayerConfigLoaded = LoadPlayerConfigurations();
	bool bBulletConfigLoaded = LoadBulletConfigurations();
	bool bEnemyConfigLoaded = LoadEnemyConfigurations();

	return false;
}


/*
	Method load configurations about the window from config file
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadWindowConfigurations()
{
	// TODO Load Window config from config file

	m_WindowConfig.setProgramName("Geometry Wars");
	m_WindowConfig.setWindowHeight(768);
	m_WindowConfig.setWindowWidth(1024);
	m_WindowConfig.setFramerateLimit(30);
	m_WindowConfig.setWindowMode(0);

	return true;
}


/*
	Method load configurations about the font from config file
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadFontConfigurations()
{
	// TODO Load Font config from config file

	m_FontConfig.setFontFileName(this->m_strFontFileName);
	m_FontConfig.setFontSize(18);
	m_FontConfig.setFontColor(sf::Color(250, 250, 250));

	return true;
}


/* 
	Method load configurations about the player from config file
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadPlayerConfigurations()
{
	// TODO Load Player config from config file

	m_PlayerConfig.setShapeRadius(32);
	m_PlayerConfig.setCollisionBoxRadius(36);
	m_PlayerConfig.setSpeed(10.0f);
	m_PlayerConfig.setFillColor(sf::Color(0,0,255));
	m_PlayerConfig.setOutlineColor(sf::Color(255,0,0));
	m_PlayerConfig.setOutlineThickness(2);
	m_PlayerConfig.setNumberOfVerticesForShape(8);
	m_PlayerConfig.setRotationSpeed(2.0f);
	m_PlayerConfig.setRespawnInterval(100);

	return true;
}


/*
	Method load configurations about the bullets player from config file
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadBulletConfigurations()
{
	// TODO Load bullet config from config file

	m_BulletConfig.setShapeRadius(5);
	m_BulletConfig.setCollisionBoxRadius(9);
	m_BulletConfig.setSpeed(10.0f);
	m_BulletConfig.setFillColor(sf::Color(255, 255, 255));
	m_BulletConfig.setOutlineColor(sf::Color(255, 255, 255));
	m_BulletConfig.setOutlineThickness(2);
	m_BulletConfig.setNumberOfVerticesForShape(20);
	m_BulletConfig.setLifespan(60);
	m_BulletConfig.setDamage(50);

	return true;
}


/*
	Method load configurations about the enemy from config file
	@return true if the loading was ok. Otherwise we return false
*/
bool CConfiguration::LoadEnemyConfigurations()
{
	// TODO Load enemy config from config file
	m_EnemyConfig.setShapeRadius(20);
	m_EnemyConfig.setCollisionBoxRadius(24);
	m_EnemyConfig.setMinSpeed(1.0f);
	m_EnemyConfig.setMaxSpeed(10.0f);
	m_EnemyConfig.setOutlineColor(sf::Color(255, 255, 255));
	m_EnemyConfig.setOutlineThickness(2);
	m_EnemyConfig.setMinNumberOfVerticesForShape(3);
	m_EnemyConfig.setMaxNumberOfVerticesForShape(8);
	m_EnemyConfig.setSmallEnemyShapeLifeSpan(90);
	m_EnemyConfig.setSpawnInterval(60);
	m_EnemyConfig.setRotationSpeed(2.0f);
	m_EnemyConfig.setMinHealth(100);
	m_EnemyConfig.setMaxHealth(255);

	return true;
}
