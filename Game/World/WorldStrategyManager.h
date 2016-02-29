///////////////////////////////////////////////////////////
//  WorldStrategyManager.h
//  Implementation of the Class WorldStrategyManager
//  Created on:      29-Mar-2008 13:45:45
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_9562F775_A9A7_4c89_8A04_D7C27DC1A3B4__INCLUDED_)
#define EA_9562F775_A9A7_4c89_8A04_D7C27DC1A3B4__INCLUDED_

#include <vector>

#include "WorldStrategy.h"

class World;

/**
 * Responsible for managing and applying a world's strategies.
 */
class WorldStrategyManager
{

public:
	
	/**
	 * Constructs a new world strategy manager.
	 */
	WorldStrategyManager();

	virtual ~WorldStrategyManager();
	WorldStrategyManager(const WorldStrategyManager& sm);

	/**
	 * Adds a world strategy to apply on the world on each tick. Must be called before
	 * initialization.
	 * 
	 * @param strategy
	 */
	void addStrategy(const WorldStrategy& strategy);

	void applyStrategies(World& world);

	/**
	 * Initializes the world strategy manager. Requires a world boundary strategy to
	 * be present.
	 */
	void init();

private:

	typedef std::vector<WorldStrategy*> strategies_t;

	/**
	 * Different strategies to be applied on the world on each call to tick().
	 */
	strategies_t m_strategies;

};
#endif // !defined(EA_9562F775_A9A7_4c89_8A04_D7C27DC1A3B4__INCLUDED_)
