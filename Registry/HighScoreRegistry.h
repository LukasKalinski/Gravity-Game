///////////////////////////////////////////////////////////
//  HighScoreRegistry.h
//  Implementation of the Class HighScoreRegistry
//  Created on:      28-mar-2008 10:27:52
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_5777B49E_411C_4bad_A002_96389DD9A977__INCLUDED_)
#define EA_5777B49E_411C_4bad_A002_96389DD9A977__INCLUDED_

#include <map>

#include "Registry.h"

/**
 * Responsible for storing high scores in a file, as well as deciding what scores
 * should be considered being high scores.
 */
class HighScoreRegistry : public Registry
{

public:
	virtual ~HighScoreRegistry();
	HighScoreRegistry(const HighScoreRegistry& theHighScoreRegistry);

	std::multimap<std::string, unsigned int>::const_iterator getHighScores() const;
	static HighScoreRegistry* instance();
	bool trySetHighScore(const std::string& playerName, unsigned int score);

private:
	/**
	 * Contains the names of the players achieving a high score together with the high
	 * score they achieved.
	 */
	std::multimap<std::string, unsigned int> m_highScores;

	/**
	 * The singleton instance.
	 */
	static HighScoreRegistry* m_singleton;

	HighScoreRegistry();

};
#endif // !defined(EA_5777B49E_411C_4bad_A002_96389DD9A977__INCLUDED_)
