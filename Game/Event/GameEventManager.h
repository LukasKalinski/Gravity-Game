///////////////////////////////////////////////////////////
//  GameEventManager.h
//  Implementation of the Class GameEventManager
//  Created on:      28-mar-2008 10:26:58
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_9EE9242D_7418_498a_939E_1DBEA6F29774__INCLUDED_)
#define EA_9EE9242D_7418_498a_939E_1DBEA6F29774__INCLUDED_

#include <set>

#include "WorldObjectDestructionEvent.h"
#include "WorldObjectInsertEvent.h"
#include "WorldObjectRemoveEvent.h"
#include "ProjectileFireEvent.h"

#include "WorldObjectDestructionListener.h"
#include "WorldObjectInsertListener.h"
#include "WorldObjectRemoveListener.h"
#include "ProjectileFireListener.h"

class Ship;
class Projectile;
class DestroyableObject;
class WorldObject;
class BoingListener;

/**
 * Holds event listeners and sends relevant game events to them when requested to
 * do so.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 16-Apr-2008 23:48:24
 */
class GameEventManager
{

public:

	GameEventManager();
	virtual ~GameEventManager();

	/**
	 * Notifies all registered boing event listeners about the event.
	 * 
	 * @param ship
	 * @param projectile
	 */
	void sendBoingEvent();

	/**
	 * Notifies all registered projectile fire event listeners about the event,
	 * specifying the ship that fired the projectile as well as the projectile itself.
	 * 
	 * @param ship
	 * @param projectile
	 */
	void sendProjectileFireEvent(const Ship* ship, const Projectile* projectile);

	/**
	 * Notifies all registered world object destruction event listeners about an
	 * occuring destruction, specifying the destroyed world object as well as the
	 * world object that caused its destruction.
	 * 
	 * @param wo
	 * @param cause
	 */
	void sendWorldObjectDestructionEvent(const DestroyableObject* wo, const WorldObject* cause);

	/**
	 * Notifies all registered world object insert event listeners about a world
	 * object being inserted into the world (i.e., not queued for insertion, but
	 * actually inserted!).
	 * 
	 * @param wo
	 */
	void sendWorldObjectInsertEvent(WorldObject* wo);

	/**
	 * Notifies all registered world object remove event listeners about a world
	 * object soon being removed (probably directly after the event is sent out).
	 * 
	 * @param wo
	 */
	void sendWorldObjectRemoveEvent(const WorldObject* wo);

	/**
	 * Registers a boing event listener.
	 * 
	 * @param listener
	 */
	void registerBoingListener(BoingListener* listener);
	/**
	 * Unregisters a boing event listener.
	 * 
	 * @param listener
	 */
	void unregisterBoingListener(BoingListener* listener);

	/**
	 * Registers a projectile fire event listener.
	 * 
	 * @param listener
	 */

	void registerProjectileFireListener(ProjectileFireListener* listener);

	/**
	 * Unregisters a projectile fire event listener.
	 * 
	 * @param listener
	 */
	void unregisterProjectileFireListener(ProjectileFireListener* listener);

	/**
	 * Registers a world object destruction event listener.
	 * 
	 * @param listener
	 */
	void registerWorldObjectDestructionListener(WorldObjectDestructionListener* listener);

	/**
	 * Unregisters a world object destruction event listener.
	 * 
	 * @param listener
	 */
	void unregisterWorldObjectDestructionListener(WorldObjectDestructionListener* listener);

	/**
	 * Registers a world object insert event listener.
	 * 
	 * @param listener
	 */
	void registerWorldObjectInsertListener(WorldObjectInsertListener* listener);

	/**
	 * Unregisters a world object insert event listener.
	 * 
	 * @param listener
	 */
	void unregisterWorldObjectInsertListener(WorldObjectInsertListener* listener);

	/**
	 * Registers a world object remove event listener.
	 * 
	 * @param listener
	 */
	void registerWorldObjectRemoveListener(WorldObjectRemoveListener* listener);

	/**
	 * Unregisters a world object remove event listener.
	 * 
	 * @param listener
	 */
	void unregisterWorldObjectRemoveListener(WorldObjectRemoveListener* listener);

private:

	typedef std::set<WorldObjectDestructionListener*>	wo_destruct_listeners_t;
	typedef std::set<WorldObjectInsertListener*>		wo_insert_listeners_t;
	typedef std::set<WorldObjectRemoveListener*>		wo_remove_listeners_t;
	typedef std::set<ProjectileFireListener*>			projectile_fire_listeners_t;
	typedef std::set<BoingListener*>					boing_listeners_t;

	/**
	 * Listeners of world boing events.
	 */

	boing_listeners_t m_boingListeners;

	/**
	 * Listeners of world object destruction events.
	 */
	wo_destruct_listeners_t m_woDestructListeners;

	/**
	 * Listeners of world object insert events.
	 */
	wo_insert_listeners_t m_woInsertListeners;

	/**
	 * Listeners of world object remove events.
	 */
	wo_remove_listeners_t m_woRemoveListeners;

	/**
	 * Listeners of projectile fire events in the world.
	 */
	projectile_fire_listeners_t m_projectileFireListeners;

};
#endif // !defined(EA_9EE9242D_7418_498a_939E_1DBEA6F29774__INCLUDED_)
