///////////////////////////////////////////////////////////
//  Player.h
//  Implementation of the Class Player
//  Created on:      28-mar-2008 10:31:44
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_30A4ABC4_6729_4d34_ABFC_26CAC3C5F490__INCLUDED_)
#define EA_30A4ABC4_6729_4d34_ABFC_26CAC3C5F490__INCLUDED_

#include <set>

#include "GameEventManager.h"
#include "World.h"
#include "Ship.h"
#include "Tickable.h"

/**
 * Responsible for maintaining generic statistics about a player's activity in the
 * game world, as well as for managing the player's ships.
 */
class Player :
	public Tickable,
	public WorldObjectDestructionListener,
	public ProjectileFireListener,
	public WorldObjectRemoveListener
{

public:

	Player(const std::string& name, const Ship& shipTemplate);
	virtual ~Player();
	Player(const Player& player);


	/**
	 * Returns the player's current ship. If there are no ships left then a zero-
	 * pointer is returned.
	 */
	Ship* getCurrentShip();
	const Ship* getCurrentShip() const;

	unsigned int getDestroyedAsteroidsCount() const;
	unsigned int getDestroyedShipsCount() const;
	unsigned int getLives() const;
	const std::string& getName() const;

	virtual void tick();

	/**
	 * Initializes the player, making it register itself in the required-to-be-present
	 * event manager. World must also be present when this function is called, as the
	 * player instance will insert a ship into it here.
	 */
	void init();

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
	virtual void notifyEvent(const WorldObjectDestructionEvent& ev);

	/**
	 * Notifies about a projectile being fired in the world.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(const ProjectileFireEvent& ev);

	/**
	 * Checks whether the removal order is about one of this players saved projectiles
	 * or the player's ship, and removes the related pointer if that's the case.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(const WorldObjectRemoveEvent& ev);

	/**
	 * Sets the event manager that is used in the current game state.
	 * 
	 * @param eventManager
	 */
	void setEventManager(GameEventManager* eventManager);

	/**
	 * Sets the world into which the player will insert his ships.
	 * 
	 * @param world
	 */
	void setWorld(World* world);

private:

	typedef std::set<const Projectile*> projectiles_t;

	/**
	 * Ticks to wait before trying to respawn a ship.
	 */
	static const unsigned int RESPAWN_DELAY = 35;

	/**
	 * Ticks left before the player's ship respawns.
	 */
	unsigned int m_respawnCountdown;

	/**
	 * The event manager used in the current game state. Must be set before
	 * initialization.
	 *
	 * Available after initialization.
	 */
	GameEventManager *m_eventManager;

	/**
	 * Number of destroyed asteroids.
	 */
	unsigned int m_destroyedAsteroids;

	/**
	 * Number of killed ships.
	 */
	unsigned int m_killedShips;

	/**
	 * The name of the player.
	 */
	std::string m_name;

	/**
	 * Number of ships left to use.
	 */
	unsigned short m_shipsLeft;

	/**
	 * The ship template to create new ships from.
	 */
	Ship m_shipTemplate;

	/**
	 * The ship that the player is currently in control of.
	 *
	 * Available after initialization.
	 */
	Ship *m_currentShip;

	/**
	 * The world to insert ships into.
	 *
	 * Available after initialization.
	 */
	World *m_world;

	/**
	 * The projectiles that this player has fired from one or
	 * more of his ships and that still exist in the world.
	 *
	 * Available after initialization.
	 */
	projectiles_t m_firedProjectiles;

	/**
	 * Tells whether the player is initialized or not.
	 */
	bool m_initialized;

	bool tryRespawnShip();

	/**
	 * Catches all irrelevant destruction events.
	 * 
	 * @param wo1
	 * @param wo2
	 */
	void handleDestructionEvent(const WorldObject& wo1, const WorldObject& wo2);

	/**
	 * Handles the following cases:
	 * 
	 * 1. The player's ship is destroyed by a projectile, in which case we try to
	 * insert a new ship into the world (if there are ships left).
	 * 2. One of the player's fired projectiles hits a ship, in which case the
	 * player's stats will be updated.
	 * 
	 * @param destroyedShip
	 * @param hittingProjectile
	 */
	void handleDestructionEvent(Ship& destroyedShip, const Projectile& hittingProjectile);

	/**
	 * Handles the case of a ship being destroyed by any world object (excluding
	 * projectiles; see corresponding overload). Tries to respawn the ship in the
	 * world if there are any ships left.
	 * 
	 * @param destroyedShip
	 * @param causeObject
	 */
	void handleDestructionEvent(Ship& destroyedShip, const WorldObject& causeObject);

	/**
	 * Handles the case of this player's ship destroying a world object that is not a
	 * ship. Updates player statistics.
	 * 
	 * @param wo
	 */
	void handleDestructionEvent(const WorldObject* wo);

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
	void handleShipDestructionEvent(Ship* destroyedShip, const Projectile* hittingProjectile);

	/**
	 * Handles the case of a ship being destroyed by any world object (excluding
	 * projectiles; see corresponding overload). Tries to respawn the ship in the
	 * world if there are any ships left.
	 * 
	 * @param destroyedShip
	 * @param causeObject
	 */
	void handleShipDestructionEvent(Ship* destroyedShip, const WorldObject* causeObject);

};
#endif // !defined(EA_30A4ABC4_6729_4d34_ABFC_26CAC3C5F490__INCLUDED_)
