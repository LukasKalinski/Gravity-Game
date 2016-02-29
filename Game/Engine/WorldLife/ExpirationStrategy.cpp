///////////////////////////////////////////////////////////
//  ExpirationStrategy.cpp
//  Implementation of the Class ExpirationStrategy
//  Created on:      28-mar-2008 10:26:00
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ExpirationStrategy.h"
#include "GameEventManager.h"
#include "World.h"


/**
 * Constructs an expiration strategy with the specified event manager to register
 * itself in (and when destroyed, unregister itself from).
 * 
 * @param eventManager
 */
ExpirationStrategy::ExpirationStrategy(GameEventManager* eventManager):
m_eventManager(eventManager),
m_fuelItemExpire(100),
m_laserExpire(40),
m_missileExpire(0),
m_missileItemExpire(100)
{

	if (!m_eventManager) {
		throw std::exception("ExpirationStrategy.cpp: event manager was 0");
	}

	m_eventManager->registerWorldObjectInsertListener(this);
	m_eventManager->registerWorldObjectRemoveListener(this);
}


ExpirationStrategy::~ExpirationStrategy() {

	// Unregister expiration strategy from event listening:
	if (m_eventManager) {
		m_eventManager->unregisterWorldObjectInsertListener(this);
		m_eventManager->unregisterWorldObjectRemoveListener(this);
	}
}


ExpirationStrategy::ExpirationStrategy(const ExpirationStrategy& strategy):
m_eventManager(strategy.m_eventManager),
m_fuelItemExpire(strategy.m_fuelItemExpire),
m_laserExpire(strategy.m_laserExpire),
m_missileExpire(strategy.m_missileExpire),
m_missileItemExpire(strategy.m_missileItemExpire)
{
	// FIXME: handle m_monitoredWorldObjects ? or just skip?
	if (m_eventManager) {
		m_eventManager->registerWorldObjectInsertListener(this);
		m_eventManager->registerWorldObjectRemoveListener(this);
	}
}


/**
 * Applies a world strategy on a world instance.
 */
void ExpirationStrategy::applyWorldStrategy(World& world) {

	monitored_objects_t::iterator wo_it = m_monitoredWorldObjects.begin();
	for ( ; wo_it != m_monitoredWorldObjects.end(); ++wo_it) {

		// Reduce expiration countdown:
		wo_it->second = wo_it->second - 1;

		// Queue removal of world objects that are
		// considered being expired:
		if (wo_it->second == 0) {
			world.getWorldObjectsManager().queueRemoval(wo_it->first);
		}

		// FIXME: either rely on the world remove events to tell us
		//        about the object being removed, and remove it from
		//        our list then, or do it here in a queue or something.
	}
}


/**
 * Notifies the expiration strategy about an occuring world removal event.
 */
void ExpirationStrategy::notifyEvent(const WorldObjectRemoveEvent& ev) {

	// Remove possible internal pointers to the object that
	// is being removed from the world:
	monitored_objects_t::iterator wo_it =
		m_monitoredWorldObjects.find(const_cast<WorldObject*>(ev.getRemoved()));
	if (wo_it != m_monitoredWorldObjects.end()) {
		m_monitoredWorldObjects.erase(wo_it);
	}
}


/**
 * Notifies the expiration strategy about an occuring world insertion event. If
 * the object is to expire, its expiration countdown will start here.
 * 
 * @param ev
 */
void ExpirationStrategy::notifyEvent(WorldObjectInsertEvent& ev) {

	// Save pointer to the inserted world object in order to monitor
	// its life time:
	initExpirationCountdown(ev.getInserted());
}


/**
 * Sets the number of ticks to receive before a fuel item is removed from the
 * world. Setting ticks to 0 means that it will last until removed in a natural
 * way.
 */
void ExpirationStrategy::setFuelItemExpiration(unsigned int ticks) {
	m_fuelItemExpire = ticks;
}


/**
 * Sets the number of ticks to receive before a laser is removed from the world.
 * Setting ticks to 0 means that it will last until removed in a natural way.
 */
void ExpirationStrategy::setLaserExpiration(unsigned int ticks) {
	m_laserExpire = ticks;
}


/**
 * Sets the number of ticks to receive before a missile is removed from the world.
 * Setting ticks to 0 means that it will last until removed in a natural way.
 */
void ExpirationStrategy::setMissileExpiration(unsigned int ticks) {
	m_missileExpire = ticks;
}


/**
 * Sets the number of ticks to receive before a missile item is removed from the
 * world. Setting ticks to 0 means that it will last until removed in a natural
 * way.
 */
void ExpirationStrategy::setMissileItemExpiration(unsigned int ticks) {
	m_missileItemExpire = ticks;
}


/**
 * Routes to leaf types.
 * 
 * @param wo
 */
void ExpirationStrategy::initExpirationCountdown(WorldObject* wo) {
	if (MissileProjectile * missile = dynamic_cast<MissileProjectile*>(wo)) {
		initExpirationCountdown(missile);
	}
	if (LaserProjectile * laser = dynamic_cast<LaserProjectile*>(wo)) {
		initExpirationCountdown(laser);
	}
}


/**
 * Initiates expiration countdown for a laser projectile.
 * 
 * @param laser
 */
void ExpirationStrategy::initExpirationCountdown(LaserProjectile* laser) {
	m_monitoredWorldObjects[laser] = m_laserExpire;
}


/**
 * Initiates expiration countdown for a missile  projectile.
 * 
 * @param missile
 */
void ExpirationStrategy::initExpirationCountdown(MissileProjectile* missile) {
	m_monitoredWorldObjects[missile] = m_missileExpire;
}


/**
 * Initiates expiration countdown for a fuel item.
 * 
 * @param item
 */
void ExpirationStrategy::initExpirationCountdown(FuelItem* item) {
	m_monitoredWorldObjects[item] = m_fuelItemExpire;
}


/**
 * Initiates expiration countdown for a missile item.
 * 
 * @param item
 */
void ExpirationStrategy::initExpirationCountdown(MissileItem* item) {
	m_monitoredWorldObjects[item] = m_missileItemExpire;
}


/**
 * Clones the expiration strategy, returning the clone.
 */
ExpirationStrategy* ExpirationStrategy::clone() const {
	return new ExpirationStrategy(*this);
}