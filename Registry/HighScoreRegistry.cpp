///////////////////////////////////////////////////////////
//  HighScoreRegistry.cpp
//  Implementation of the Class HighScoreRegistry
//  Created on:      28-mar-2008 10:27:56
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "HighScoreRegistry.h"

HighScoreRegistry* HighScoreRegistry::m_singleton = 0;

HighScoreRegistry::~HighScoreRegistry() {

}



HighScoreRegistry::HighScoreRegistry(const HighScoreRegistry& theHighScoreRegistry) {

}





/**
 * Constructs a high score registry.
 */
HighScoreRegistry::HighScoreRegistry() {

	//Loads data from high score file.
	
	m_highScores.insert(std::make_pair("Player 1", 1234));
}


/**
 * Returns a multimap iterator containing the top ten high scores and the players that
 * achieved them.
 */
std::multimap<std::string, unsigned int>::const_iterator HighScoreRegistry::getHighScores() const {
	return m_highScores.begin();
}


/**
 * Returns the singleton instance of the high score registry.
 */
HighScoreRegistry* HighScoreRegistry::instance() {
	if (!m_singleton) {
	  m_singleton = new HighScoreRegistry();
	}
	return m_singleton;
}


/**
 * Tries to set the specified score as a high score and will do so if the score is
 * high enough (top 10), returning true. If the high score is not high enough,
 * false will be returned.
 */
bool HighScoreRegistry::trySetHighScore(const std::string& playerName, unsigned int score) {

	return false;
}