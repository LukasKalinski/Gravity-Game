///////////////////////////////////////////////////////////
//  Engine.cpp
//  Implementation of the Class Engine
//  Created on:      28-mar-2008 10:25:39
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////


#include "Engine.h"
#include "GravityStrategy.h"
#include "CollisionStrategy.h"
#include "WrapBoundaryStrategy.h"
#include "ExpirationStrategy.h"
#include "AsteroidStrategy.h"

/**
 * Constructs a game engine.
 */
Engine::Engine():
m_world(0),
m_eventManager(0),
m_initialized(false)
{
}


Engine::~Engine() {
	if (m_world) {
		delete m_world;
	}

	players_t::iterator player_it = m_players.begin();
	for ( ; player_it != m_players.end(); ++player_it) {
		delete *player_it;
		*player_it = 0;
	}
	m_players.clear();
}


Engine::Engine(const Engine& engine) {
	throw std::exception("Engine: copy constructor called");
}


/**
 * Initializes the world and the added players, meaning that both the world and
 * all players must be present.
 */
void Engine::init() {

	if (m_initialized) {
		throw std::exception("Engine::init(): cannot initialize more \
							 than once");
	}

	// Make sure that an event manager is present:
	if (m_eventManager == 0) {
		throw std::exception("Engine::init(): event manager must be present \
							 before initialization");
	}

	// Make sure that a world is present:
	if (m_world == 0) {
		throw std::exception("Engine::init(): world must be present \
							 before initialization");
	}

	// Make sure that we have at least one player:
	if (m_players.size() == 0) {
		throw std::exception("Engine::init(): at least one player \
							 must be present before initialization");
	}

	m_world->setEventManager(m_eventManager);
	m_world->init();

	// Initialize players:
	players_t::iterator players_it = m_players.begin();
	for ( ; players_it != m_players.end(); ++players_it) {
		(*players_it)->setWorld(m_world);
		(*players_it)->init();
	}

	m_world->getStrategyManager().addStrategy(GravityStrategy());
	m_world->getStrategyManager().addStrategy(CollisionStrategy());
	m_world->getStrategyManager().addStrategy(WrapBoundaryStrategy());
	m_world->getStrategyManager().addStrategy(ExpirationStrategy(m_eventManager));
	m_world->getStrategyManager().addStrategy(AsteroidStrategy(200));

	m_initialized = true;
}


/**
 * Sets the event manager that is used in the current game state.
 * 
 * @param eventManager
 */
void Engine::setEventManager(GameEventManager* eventManager){
	
	if (m_initialized) {
		throw std::exception("Engine::setEventManager(): cannot set event \
							 manager after initialization");
	}

	if (eventManager == 0) {
		throw std::exception("Engine::setEventManager(): event manager \
							 must not be 0");
	}

	m_eventManager = eventManager;
}


/**
 * Sets the world that the engine should manage, and in which the game will be
 * played. This function also validates that the world is in a consistent state.
 * 
 * @param world
 */
void Engine::loadWorld(const World& world) {

	if (m_initialized) {
		throw std::exception("Engine::loadWorld(): cannot load world \
							 after initialization");
	}

	// Validate world _before_ deleting old world:
	validateWorld(world);

	// Delete old world if any:
	if (m_world) {
		delete m_world;
	}

	m_world = new World(world);
}


/**
 * Adds a player to the engine and returns the pointer to the player
 * instance stored by engine.
 */
Player * Engine::addPlayer(const Player& player) {

	if (m_initialized) {
		throw std::exception("Engine::addPlayer(): cannot add players \
							 after initialization");
	}

	Player * addedPlayer = new Player(player);

	m_players.push_back(addedPlayer);

	return addedPlayer;
}


/**
 * Returns the player that is associated with the specified number (first=0,
 * second=1, ...).
 */
Player& Engine::getPlayer(Engine::player_num_t playerNum) {

	if (!m_initialized) {
		throw std::exception("Engine::getPlayer(): cannot access \
							 players before initialization");
	}

	if (static_cast<size_t>(playerNum) >= m_players.size()) {
		throw std::exception("Engine::getPlayer(): player not found");
	}

	return *m_players[playerNum];
}


/**
 * Returns an iterator of all contained players. May be called by the game state
 * to check if a player has lost or not, for example.
 */
Engine::players_t& Engine::getPlayers() {

	if (!m_initialized) {
		throw std::exception("Engine::getPlayers(): cannot access \
							 players before initialization");
	}

	return m_players;
}

const Engine::players_t& Engine::getPlayers() const {
	
	if (!m_initialized) {
		throw std::exception("Engine::getPlayers(): cannot access \
							 players before initialization");
	}

	return m_players;
}


/**
 * Returns the game world instance.
 */
World& Engine::getWorld() {

	if (!m_initialized) {
		throw std::exception("Engine::getWorld(): engine not initialized");
	}

	return *m_world;
}

const World& Engine::getWorld() const {

	if (!m_initialized) {
		throw std::exception("Engine::getWorld(): engine not initialized");
	}

	return *m_world;
}


/**
 * Ticks the world instance.
 */
void Engine::tick() {

	if (!m_initialized) {
		throw std::exception("Engine::tick(): engine not initialized");
	}

	m_world->tick();
}


/**
 * Makes sure that no static objects are intersecting and that no movable objects
 * are present.
 */
void Engine::validateWorld(const World& world) const {
	// FIXME
}