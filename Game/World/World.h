///////////////////////////////////////////////////////////
//  World.h
//  Implementation of the Class World
//  Created on:      28-mar-2008 10:35:51
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_B4695CF2_FB9B_4795_9B04_8E98BAEA2F15__INCLUDED_)
#define EA_B4695CF2_FB9B_4795_9B04_8E98BAEA2F15__INCLUDED_

#include <queue>
#include <exception>

#include "WorldObject.h"
#include "Tickable.h"
#include "SpawnPoint.h"
#include "MovableObject.h"
#include "GameEventManager.h"
#include "WorldStrategyManager.h"
#include "WorldObjectsManager.h"


/**
 * Representation of the whole game world, containing all world objects that are
 * supposed to exist at a certain moment during a game session.
 */
class World : public Tickable
{

public:

	/**
	 * Constructs an uninitialized world instance, specifying the
	 * world's dimensions.
	 * 
	 * @param upperLeft
	 * @param lowerRight
	 */
	World(const Coord2d& upperLeft, const Coord2d& lowerRight);

	virtual ~World();
	World(const World& world);

	unsigned int getTime() const;

	/**
	 * Initiates the world, requiring an event manager to be present.
	 */
	void init();

	/**
	 * Calls tick() on the world objects manager and applies available strategies on
	 * self. 
	 */
	virtual void tick();

	/**
	 * Returns the strategy manager used by the world.
	 */
	WorldStrategyManager& getStrategyManager();

	/**
	 * Returns the world objects  manager used by the world.
	 */
	WorldObjectsManager& getWorldObjectsManager();
	const WorldObjectsManager& getWorldObjectsManager() const;

	/**
	 * Returns the game event manager used by the world.
	 */
	GameEventManager& getEventManager();
	
	/**
	 * Sets the game event manager to use.
	 * 
	 * @param eventManager
	 */
	void setEventManager(GameEventManager* eventManager);

	/**
	 * Returns the world's upper left corner coordinate.
	 */
	const Coord2d& getUpperLeft() const;

	/**
	 * Returns the world's lower right corner coordinate.
	 */
	const Coord2d& getLowerRight() const;

	/**
	 * Tells whether the world is initialized or not.
	 */
	bool isInitialized() const;

private:

	/**
	 * Tells whether the world has been initialized or not.
	 */
	bool m_initialized;

	/**
	 * The number of ticks received by the world - the world's time.
	 */
	unsigned int m_time;

	/**
	 * Manager of the world's strategies.
	 */
	WorldStrategyManager m_strategyManager;

	/**
	 * Manages the world's objects (ships, asteroids, etc).
	 */
	WorldObjectsManager m_worldObjectsManager;

	/**
	 * The game event manager used by the world to cascade occuring events in.
	 */
	GameEventManager *m_eventManager;

	/**
	 * The upper left corner coordinate of the world.
	 */
	Coord2d m_upperLeft;

	/**
	 * The lower right corner coordinate of the world.
	 */
	Coord2d m_lowerRight;

};
#endif // !defined(EA_B4695CF2_FB9B_4795_9B04_8E98BAEA2F15__INCLUDED_)
