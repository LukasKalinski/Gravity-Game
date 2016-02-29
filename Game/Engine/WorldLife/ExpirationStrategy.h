///////////////////////////////////////////////////////////
//  ExpirationStrategy.h
//  Implementation of the Class ExpirationStrategy
//  Created on:      28-mar-2008 10:25:52
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_B5F9AA74_505E_46ef_BED3_64A62C98FFCB__INCLUDED_)
#define EA_B5F9AA74_505E_46ef_BED3_64A62C98FFCB__INCLUDED_

#include <map>

#include "WorldStrategy.h"
#include "GameEventManager.h"
#include "WorldObject.h"
#include "FuelItem.h"
#include "MissileItem.h"
#include "MissileProjectile.h"
#include "LaserProjectile.h"


/**
 * Responsible for deciding what world objects should expire and when they should
 * do so, resulting in being removed from the world. Examples are: projectiles,
 * which shouldn't be in the world too long.
 */
class ExpirationStrategy :
	public WorldStrategy,
	public WorldObjectInsertListener,
	public WorldObjectRemoveListener
{

public:

	/**
	 * Constructs an expiration strategy with the specified event manager to register
	 * itself in (and when destroyed, unregister itself from).
	 * 
	 * @param eventManager
	 */
	ExpirationStrategy(GameEventManager* eventManager);
	
	virtual ~ExpirationStrategy();
	ExpirationStrategy(const ExpirationStrategy& strategy);

	virtual void applyWorldStrategy(World& world);
	void setFuelItemExpiration(unsigned int ticks);
	void setLaserExpiration(unsigned int ticks);
	void setMissileExpiration(unsigned int ticks);
	void setMissileItemExpiration(unsigned int ticks);

	virtual void notifyEvent(const WorldObjectRemoveEvent& ev);

	/**
	 * Notifies the expiration strategy about an occuring world insertion event. If
	 * the object is to expire, its expiration countdown will start here.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(WorldObjectInsertEvent& ev);

	/**
	 * Clones the expiration strategy, returning the clone.
	 */
	virtual ExpirationStrategy* clone() const;

private:

	typedef std::map<WorldObject*, unsigned int> monitored_objects_t;

	/**
	 * The number of ticks from a fuel item's detection to its expiration.
	 */
	unsigned int m_fuelItemExpire;

	/**
	 * The number of ticks from a laser's detection to its expiration.
	 */
	unsigned int m_laserExpire;

	/**
	 * The number of ticks from a missile's detection to its expiration.
	 */
	unsigned int m_missileExpire;

	/**
	 * The number of ticks from a missile item's detection to its expiration.
	 */
	unsigned int m_missileItemExpire;

	/**
	 * The event manager where the expiration strategy registers itself as well as
	 * unregisters itself when being destroyed.
	 */
	GameEventManager *m_eventManager;

	/**
	 * Contains all monitored world objects together with the time they have left
	 * before being expired.
	 */
	monitored_objects_t m_monitoredWorldObjects;

	/**
	 * Catches world objects that should not be expired.
	 * 
	 * @param wo
	 */
	void initExpirationCountdown(WorldObject* wo);

	/**
	 * Initiates expiration countdown for a laser projectile.
	 * 
	 * @param laser
	 */
	void initExpirationCountdown(LaserProjectile* laser);

	/**
	 * Initiates expiration countdown for a missile  projectile.
	 * 
	 * @param missile
	 */
	void initExpirationCountdown(MissileProjectile* missile);

	/**
	 * Initiates expiration countdown for a fuel item.
	 * 
	 * @param item
	 */
	void initExpirationCountdown(FuelItem* item);

	/**
	 * Initiates expiration countdown for a missile item.
	 * 
	 * @param item
	 */
	void initExpirationCountdown(MissileItem* item);

};
#endif // !defined(EA_B5F9AA74_505E_46ef_BED3_64A62C98FFCB__INCLUDED_)
