#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

#include "CWindowConfig.h"
#include "CFontConfig.h"
#include "CPlayerConfig.h"
#include "CEnemyConfig.h"
#include "CBulletConfig.h"


/*
	CConfiguration.h
	CConfiguration class for different configurations from a config file
	@author Oscar Andersson
	@date 2022-11-12
	@version 1.0 
*/
class CConfiguration
{
private:
	/* Name of the configuration file */
	std::string m_strConfigFileName = "config.txt";

	/* Name and path to the fonts file */
	std::string m_strFontFileName = "Fonts/sansation.ttf";

	/* Configrurations for the window */
	CWindowConfig m_WindowConfig;

	/* Configurations for the font */
	CFontConfig m_FontConfig;

	/* Configurations for the player */
	CPlayerConfig m_PlayerConfig;

	/* Configurations for the enemies */
	CEnemyConfig m_EnemyConfig;

	/* Configurations for the bullets */
	CBulletConfig m_BulletConfig;

public:
	sf::Font m_Font;

	/* Constructor */
	CConfiguration() {}


	/* 
		Constructor 
		@param strConfigFileName Name of the configuration file 
	*/
	CConfiguration(std::string strConfigFileName);


	/*
		Constructor
		@param strConfigFileName Name of the configuration file
		@param strFontFileName Name and path of the fonts file
	*/
	CConfiguration(std::string strConfigFileName, std::string strFontFileName);


	// get methods

	/* 
		Method get the name of the configuration file 
		@return Name of the configuration file 
	*/
	const std::string& getConfigFileName() const { return m_strConfigFileName; }

	/*
		Method get the name and path for the font file
		@return Name and path to the font file
	*/
	const std::string& getFontFileName() const { return m_strFontFileName; }

	/* 
		Method get the Configurations for the Window 
		@return Reference to the configurations for the window 
	*/
	CWindowConfig& getWindowConfig() { return m_WindowConfig; }

	/* 
		Method get the Configurations for the Font 
		@return Reference to the configurations for the font 
	*/
	CFontConfig& getFontConfig() { return m_FontConfig; }

	/* 
		Method get the Configurations for the Player 
		@return Reference to the configurations for the Player 
	*/
	CPlayerConfig& getPlayerConfig() { return m_PlayerConfig; }

	/* 
		Method get the Configurations for the Enemy 
		@return Reference to the configurations for the Enemy 
	*/
	CEnemyConfig& getEnemyConfig() { return m_EnemyConfig; }

	/* 
		Method get the Configurations for the Bullets 
		@return Reference to the configurations for the Bullets 
	*/
	CBulletConfig& getBulletConfig() { return m_BulletConfig; }


	// set methods

	/*
		Method set the name of the configuration file
		@param strConfigFileName Name of the configuration file
	*/
	void setConfigFileName(const std::string & strConfigFileName) { m_strConfigFileName = strConfigFileName; }

	/*
		Method set the name and path for the font file
		@param strFontFileName Name and path to the font file
	*/
	void setFontFileName(const std::string & strFontFileName) { m_strFontFileName = strFontFileName; }


	/***** Methods *****/

	/*
		Method load configurations from the config file
		@param strConfigFileName Name of the configuration file
		@param strFontFileName Name and path of the fonts file
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadConfigurations(std::string strConfigFileName, std::string strFontFileName);

	/*
		Method load configurations from the config file
		@param strConfigFileName Name of the configuration file
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadConfigurations(std::string strConfigFileName);

	/*
		Method load configurations from the config file. The configuration files name has to be set in this class
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadConfigurations();

	/* 
		Method load configurations about the window from config file 
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadWindowConfigurations();

	/*
		Method load configurations about the font from config file
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadFontConfigurations();

	/*
		Method load configurations about the player from config file
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadPlayerConfigurations();

	/*
		Method load configurations about the bullets player from config file
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadBulletConfigurations();

	/*
		Method load configurations about the enemy from config file
		@return true if the loading was ok. Otherwise we return false
	*/
	bool LoadEnemyConfigurations();

};

 