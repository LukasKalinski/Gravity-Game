///////////////////////////////////////////////////////////
//  Player.cpp
//  Implementation of the Class Player
//  Created on:      28-mar-2008 10:31:52
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "Player.h"
#include "Game.h"

/**
 * Constructs a player, specifying his name and the ship template to use when
 * inserting new ships into the world.
 */
Player::Player(const std::string& name, const Ship& shipTemplate):
m_currentShip(0),
m_destroyedAsteroids(0),
m_eventManager(0),
m_initialized(false),
m_killedShips(0),
m_name(name),
m_respawnCountdown(0),
m_shipsLeft(10),
m_shipTemplate(shipTemplate),
m_world(0)
{
}


Player::~Player() {

	// Unregister player from event listening
	// (if event manager present _and_ init() was run):
	if (m_eventManager && m_initialized) {
		m_eventManager->unregisterProjectileFireListener(this);
		m_eventManager->unregisterWorldObjectDestructionListener(this);
		m_eventManager->unregisterWorldObjectRemoveListener(this);
	}

	// Unregister ourselves from receiving ticks:
	if (m_initialized) {
		Game::instance()->unregisterStateTickable(this);
	}
}


Player::Player(const Player& player):
m_currentShip(0),
m_destroyedAsteroids(0),
m_eventManager(player.m_eventManager),
m_initialized(false),
m_killedShips(0),
m_name(player.m_name),
m_respawnCountdown(player.m_respawnCountdown),
m_shipsLeft(player.m_shipsLeft),
m_shipTemplate(player.m_shipTemplate),
m_world(0)
{
	// Don't allow copying initialized players:
	if (player.m_initialized) {
		throw std::exception("Player::Copy Constructor: cannot copy initialized player");
	}
}


/**
 * Initializes the player, making it register itself in the required-to-be-present
 * event manager. World must also be present when this function is called, as the
 * player instance will insert a ship into it here.
 */
void Player::init() {

	// Assure that we have an event manager present:
	if (m_eventManager == 0) {
		throw std::exception("Player::init(): event manager must \
							 be set before initialization");
	}

	// Assure that we have a world to insert ships into present:
	if (m_world == 0) {
		throw std::exception("Player::init(): world must be set \
							 before initialization");
	}

	// Assure that the world is initialized:
	if (!m_world->isInitialized()) {
		throw std::exception("Player::init(): world supplied \
							 to player must be initialized");
	}

	// Register player for event listening:
	m_eventManager->registerProjectileFireListener(this);
	m_eventManager->registerWorldObjectDestructionListener(this);
	m_eventManager->registerWorldObjectRemoveListener(this);

	// Try to insert the player's first ship into the world:
	if (!tryRespawnShip()) {
		throw std::exception("Player::init(): ship insertion failed");
	}

	// Start receiving ticks:
	Game::instance()->registerStateTickable(this);

	m_initialized = true;
}


/**
 * Respawns player's ship when respawn countdown is finished and
 * player's ship is destroyed.
 */
void Player::tick() {
	
	if (!m_currentShip && m_shipsLeft > 0) {
		
		// Try to respawn the ship if countdown reached 0:
		if (m_respawnCountdown == 0) {
			tryRespawnShip();
		} else {
			--m_respawnCountdown;
		}
	}
}

/**
 * Returns the player's current ship. If there are no ships left
 * then a zero-pointer is returned.
 */
Ship* Player::getCurrentShip() {
	return m_currentShip;
}

/**
 * Returns the player's current ship. If there are no ships left then a zero-
 * pointer is returned.
 */
const Ship* Player::getCurrentShip() const  {
	return m_currentShip;
}


/**
 * Returns the total number of asteroids destroyed by this player.
 */
unsigned int Player::getDestroyedAsteroidsCount() const  {
	return m_destroyedAsteroids;
}


/**
 * Returns the total number of ships destroyed by this player.
 */
unsigned int Player::getDestroyedShipsCount() const  {
	return m_killedShips;
}


/**
 * Gets the number of lives/ships left.
 */
unsigned int Player::getLives() const  {
	return m_shipsLeft;
}


/**
 * Returns the name of the player.
 */
const std::string& Player::getName() const  {
	return m_name;
}


/**
 * Tries to respawn a new ship for the player. Returns true if respawn succeeds (i.
 * e., the player have lives left) or false otherwise.
 */
bool Player::tryRespawnShip() {
	
	if (m_shipsLeft > 0) {

		// Queue an insertion of a new ship for this player into the world
		// and keep a pointer to it (which we're not responsible for!):
		m_currentShip = dynamic_cast<Ship*>(
			m_world->getWorldObjectsManager().queueInsert(m_shipTemplate));

		if (!m_currentShip) { 
			throw std::exception("Player::tryRespawnShip(): \
								 this exception should not be thrown!");
		}

		--m_shipsLeft;

		return true;
	} else {
		return false;
	}
}


/**
 * Checks if either:
 * <ul>
 * 	<li>the destroyed object was a ship and if it was this player's ship, if yes,
 * then, if there are ships left, a new ship will be inserted into the world.
 * </li>
 * 	<li>the cause of the destruction was one of this player's projectiles, and
 * updates the stats if that's the case.</li>
 * </ul>
 * 
 * @param ev
 */
void Player::notifyEvent(const WorldObjectDestructionEvent& ev) {

	// Check whether the destroyed world object is this player's ship:
	if (m_currentShip == ev.getDestroyed()) {

		// Set current ship pointer to 0:
		m_currentShip = 0;

		// Set respawn countdown:
		m_respawnCountdown = RESPAWN_DELAY;

		// # Note that tick() will handle respawning.

	// Check whether the cause of the destruction was one of this player's
	// projectiles, and update the stats if that's the case:
	} else if (const Projectile * projectile = dynamic_cast<const Projectile*>(ev.getCause())) {
		if (m_firedProjectiles.find(projectile) != m_firedProjectiles.end()) {

			// # Note that projectile pointer removal will be handled
			// # in removal event handler.

			const DestroyableObject * destroyed = ev.getDestroyed();

			// Check what was destroyed and update stats according to that:
			if (dynamic_cast<const Asteroid*>(destroyed)) {
				++m_destroyedAsteroids;
			} else if (dynamic_cast<const Ship*>(destroyed)) {
				++m_killedShips;
			}
		}
	}
}


/**
 * Notifies about a projectile being fired in the world.
 * 
 * @param ev
 */
void Player::notifyEvent(const ProjectileFireEvent& ev) {

	// Check whether it was this player's ship that fired the
	// projectile, and if yes, then insert it into our list
	// of fired proejctiles:
	if (m_currentShip == ev.getShip()) {
		m_firedProjectiles.insert(ev.getProjectile());
	}
}


/**
 * Checks whether the removal order is about one of this players saved projectiles
 * or the player's ship, and removes the related pointer if that's the case.
 * 
 * @param ev
 */
void Player::notifyEvent(const WorldObjectRemoveEvent& ev) {
	
	// Check if the removed world object is a projectile:
	if (const Projectile * removedProjectile =

		dynamic_cast<const Projectile*>(ev.getRemoved())) {

		// Check whether the removed projectile is one of this player's
		// fired projectiles:
		projectiles_t::iterator projectileToRemove =
			m_firedProjectiles.find(removedProjectile);

		// ...and remove it from the set if that's the case:
		if (projectileToRemove != m_firedProjectiles.end()) {
			m_firedProjectiles.erase(projectileToRemove);
		}
	} else if (m_currentShip == ev.getRemoved()) {
		throw std::exception("Player::notifyEvent(): should this happen \
							 or should it have been catched by the \
							 destruction event handler?");
	}
}


/**
 * Sets the event manager that is used in the current game state.
 * 
 * @param eventManager
 */
void Player::setEventManager(GameEventManager* eventManager) {
	
	if (m_initialized) {
		throw std::exception("Player::setEventManager(): cannot set \
							 event manager after initialization");
	}

	m_eventManager = eventManager;
}


/**
 * Sets the world into which the player will insert his ships.
 * 
 * @param world
 */
void Player::setWorld(World* world){
	m_world = world;
}


/**
 * Handles the case of this player's ship destroying a world object that is not a
 * ship. Updates player statistics.
 * 
 * @param wo
 */
void Player::handleDestructionEvent(const WorldObject* wo){

}


/**
 * Handles the following cases:
 * 
 * <ol>
 * 	<li>The player's ship is destroyed by a projectile, in which case we try to
 * insert a new ship into the world (if there are ships left).</li>
 * 	<li>One of the player's fired projectiles hits another player's ship, in which
 * case the hitting player's stats will be updated.</li>
 * </ol>
 * 
 * @param destroyedShip
 * @param hittingProjectile
 */
void Player::handleShipDestructionEvent(Ship* destroyedShip,
										const Projectile* hittingProjectile) {
	// necessary or fixed above?
}


/**
 * Handles the case of a ship being destroyed by any world object (excluding
 * projectiles; see corresponding overload). Tries to respawn the ship in the
 * world if there are any ships left.
 * 
 * @param destroyedShip
 * @param causeObject
 */
void Player::handleShipDestructionEvent(Ship* destroyedShip,
										const WorldObject* causeObject){
	// necessary or fixed above?
}
