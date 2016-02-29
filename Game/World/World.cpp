///////////////////////////////////////////////////////////
//  World.cpp
//  Implementation of the Class World
//  Created on:      28-mar-2008 10:35:58
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "World.h"


/**
 * Constructs an uninitialized world instance, specifying the
 * world's dimensions.
 * 
 * @param upperLeft
 * @param lowerRight
 */
World::World(const Coord2d& upperLeft, const Coord2d& lowerRight):
m_initialized(false),
m_time(0),
m_eventManager(0),
m_upperLeft(upperLeft),
m_lowerRight(lowerRight)
{
}


World::~World() {
}


World::World(const World& world):
m_initialized(false),
m_time(world.m_time),
m_strategyManager(world.m_strategyManager),
m_worldObjectsManager(world.m_worldObjectsManager),
m_eventManager(world.m_eventManager),
m_upperLeft(world.m_upperLeft),
m_lowerRight(world.m_lowerRight)
{
	if (world.m_initialized) {
		throw std::exception("World::Copy Constructor: cannot \
							 copy initialized world");
	}	
}


/**
 * Initiates the world, requiring a event manager to be present.
 */
void World::init() {

	if (m_eventManager == 0) {
		throw std::exception("World::init(): event manager must be set \
							 before initialization");
	}

	m_worldObjectsManager.setEventManager(m_eventManager);
	m_worldObjectsManager.init();
	m_initialized = true;
}


/**
 * Tells whether the world is initialized or not.
 */
bool World::isInitialized() const {
	return m_initialized;
}


/**
 * Returns the world's current time, i.e., amount of received ticks.
 */
unsigned int World::getTime() const {
	return m_time;
}


/**
 * Calls tick() on the world objects manager and applies available strategies on
 * self. 
 */
void World::tick() {

	if (!m_initialized) {
		throw std::exception("World::tick(): world not initialized");
	}

	// Tick all world objects:
	m_worldObjectsManager.tick();

	// Apply world strategies on the world:
	m_strategyManager.applyStrategies(*this);

	++m_time;
}


/**
 * Returns the strategy manager used by the world.
 */
WorldStrategyManager& World::getStrategyManager() {
	return m_strategyManager;
}


/**
 * Returns the world objects  manager used by the world.
 */
WorldObjectsManager& World::getWorldObjectsManager() {
	return m_worldObjectsManager;
}

const WorldObjectsManager& World::getWorldObjectsManager() const {
	return m_worldObjectsManager;
}


/**
 * Returns the game event manager used by the world. Throws exception
 * if the world is not initialized.
 */
GameEventManager& World::getEventManager() {

	if (!m_initialized) {
		throw std::exception("World::getEventManager(): world not\
							 initialized");
	}

	return *m_eventManager;
}


/**
 * Sets the game event manager to use.
 * 
 * @param eventManager
 */
void World::setEventManager(GameEventManager* eventManager) {

	if (eventManager == 0) {
		throw std::exception("World::setEventManager(): event manager \
							 must not be 0");
	}

	m_eventManager = eventManager;
}


/**
 * Returns the world's upper left corner coordinate.
 */
const Coord2d& World::getUpperLeft() const {
	return m_upperLeft;
}


/**
 * Returns the world's lower right corner coordinate.
 */
const Coord2d& World::getLowerRight() const {
	return m_lowerRight;
}
