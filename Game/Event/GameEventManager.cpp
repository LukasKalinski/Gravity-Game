///////////////////////////////////////////////////////////
//  GameEventManager.cpp
//  Implementation of the Class GameEventManager
//  Created on:      28-mar-2008 10:27:01
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "GameEventManager.h"
#include "BoingListener.h"


GameEventManager::GameEventManager() {
}


GameEventManager::~GameEventManager() {

	if (!m_boingListeners.empty()) {
		throw std::exception("GameEventManager::Destructor: \
							 there are registered boing \
							 listeners left");
	}

	if (!m_projectileFireListeners.empty()) {
		throw std::exception("GameEventManager::Destructor: \
							 there are registered projectile fire \
							 listeners left");
	}

	if (!m_woDestructListeners.empty()) {
		throw std::exception("GameEventManager::Destructor: \
							 there are registered world object \
							 destruction listeners left");
	}

	if (!m_woRemoveListeners.empty()) {
		throw std::exception("GameEventManager::Destructor: \
							 there are registered world object \
							 remove listeners left");
	}

	if (!m_woInsertListeners.empty()) {
		throw std::exception("GameEventManager::Destructor: \
							 there are registered world object \
							 insert listeners left");
	}
}

/**
 * Notifies all registered projectile fire event listeners about the event,
 * specifying the ship that fired the projectile as well as the projectile itself.
 * 
 * @param ship
 * @param projectile
 */
void GameEventManager::sendBoingEvent()
{

	// Create the event instance and sends it to all registered listeners:
	boing_listeners_t::iterator listener_it = m_boingListeners.begin();
	for ( ; listener_it != m_boingListeners.end(); ++listener_it) {
		(*listener_it)->notifyEvent(BoingEvent());
	}
}


/**
 * Notifies all registered projectile fire event listeners about the event,
 * specifying the ship that fired the projectile as well as the projectile itself.
 * 
 * @param ship
 * @param projectile
 */
void GameEventManager::sendProjectileFireEvent(
	const Ship* ship, const Projectile* projectile) {

	// Create the event instance and sends it to all registered listeners:
	projectile_fire_listeners_t::iterator listener_it = m_projectileFireListeners.begin();
	for ( ; listener_it != m_projectileFireListeners.end(); ++listener_it) {
		(*listener_it)->notifyEvent(ProjectileFireEvent(ship, projectile));
	}
}


/**
 * Notifies all registered world object destruction event listeners about an
 * occuring destruction, specifying the destroyed world object as well as the
 * world object that caused its destruction.
 * 
 * @param wo
 * @param cause
 */
void GameEventManager::sendWorldObjectDestructionEvent(
	const DestroyableObject* wo, const WorldObject* cause) {

	// Create the event instance and sends it to all registered listeners:
	wo_destruct_listeners_t::iterator listener_it = m_woDestructListeners.begin();
	for ( ; listener_it != m_woDestructListeners.end(); ++listener_it) {
		(*listener_it)->notifyEvent(WorldObjectDestructionEvent(wo, cause));
	}
}


/**
 * Notifies all registered world object insert event listeners about a world
 * object being inserted into the world (i.e., not queued for insertion, but
 * actually inserted!).
 * 
 * @param wo
 */
void GameEventManager::sendWorldObjectInsertEvent(WorldObject* wo) {

	// Create the event instance and sends it to all registered listeners:
	wo_insert_listeners_t::iterator listener_it = m_woInsertListeners.begin();
	for ( ; listener_it != m_woInsertListeners.end(); ++listener_it) {
		(*listener_it)->notifyEvent(WorldObjectInsertEvent(wo));
	}
}


/**
 * Notifies all registered world object remove event listeners about a world
 * object soon being removed (probably directly after the event is sent out).
 * 
 * @param wo
 */
void GameEventManager::sendWorldObjectRemoveEvent(const WorldObject* wo) {

	// Create the event instance and sends it to all registered listeners:
	wo_remove_listeners_t::iterator listener_it = m_woRemoveListeners.begin();
	for ( ; listener_it != m_woRemoveListeners.end(); ++listener_it) {
		(*listener_it)->notifyEvent(WorldObjectRemoveEvent(wo));
	}
}

//

/**
 * Registers a boing event listener.
 * 
 * @param listener
 */
void GameEventManager::registerBoingListener(
	BoingListener* listener) {
	m_boingListeners.insert(listener);
}


/**
 * Unregisters a boing event listener.
 * 
 * @param listener
 */
void GameEventManager::unregisterBoingListener(
	BoingListener* listener) {

	boing_listeners_t::const_iterator listener_it;
	listener_it = m_boingListeners.find(listener);
	if (listener_it != m_boingListeners.end()) {
		m_boingListeners.erase(listener_it);
	} else {
		throw std::exception("GameEventManager::\
							 unregisterBoingListener(): \
							 listener not found");
	}
}

//

/**
 * Registers a projectile fire event listener.
 * 
 * @param listener
 */
void GameEventManager::registerProjectileFireListener(
	ProjectileFireListener* listener) {
	m_projectileFireListeners.insert(listener);
}


/**
 * Unregisters a projectile fire event listener.
 * 
 * @param listener
 */
void GameEventManager::unregisterProjectileFireListener(
	ProjectileFireListener* listener) {

	projectile_fire_listeners_t::const_iterator listener_it;
	listener_it = m_projectileFireListeners.find(listener);
	if (listener_it != m_projectileFireListeners.end()) {
		m_projectileFireListeners.erase(listener_it);
	} else {
		throw std::exception("GameEventManager::\
							 unregisterProjectileFireListener(): \
							 listener not found");
	}
}


/**
 * Registers a world object destruction event listener.
 * 
 * @param listener
 */
void GameEventManager::registerWorldObjectDestructionListener(
	WorldObjectDestructionListener* listener) {
	m_woDestructListeners.insert(listener);
}


/**
 * Unregisters a world object destruction event listener.
 * 
 * @param listener
 */
void GameEventManager::unregisterWorldObjectDestructionListener(
	WorldObjectDestructionListener* listener) {

	wo_destruct_listeners_t::const_iterator listener_it;
	listener_it = m_woDestructListeners.find(listener);
	if (listener_it != m_woDestructListeners.end()) {
		m_woDestructListeners.erase(listener_it);
	} else {
		throw std::exception("GameEventManager::\
							 unregisterWorldObjectDestructionListener(): \
							 listener not found");
	}
}


/**
 * Registers a world object insert event listener.
 * 
 * @param listener
 */
void GameEventManager::registerWorldObjectInsertListener(
	WorldObjectInsertListener* listener) {
	m_woInsertListeners.insert(listener);
}


/**
 * Unregisters a world object insert event listener.
 * 
 * @param listener
 */
void GameEventManager::unregisterWorldObjectInsertListener(
	WorldObjectInsertListener* listener) {

	wo_insert_listeners_t::const_iterator listener_it;
	listener_it = m_woInsertListeners.find(listener);
	if (listener_it != m_woInsertListeners.end()) {
		m_woInsertListeners.erase(listener_it);
	} else {
		throw std::exception("GameEventManager::\
							 unregisterWorldObjectInsertListener(): \
							 listener not found");
	}
}


/**
 * Registers a world object remove event listener.
 * 
 * @param listener
 */
void GameEventManager::registerWorldObjectRemoveListener(
	WorldObjectRemoveListener* listener) {
	m_woRemoveListeners.insert(listener);
}


/**
 * Unregisters a world object remove event listener.
 * 
 * @param listener
 */
void GameEventManager::unregisterWorldObjectRemoveListener(
	WorldObjectRemoveListener* listener) {

	wo_remove_listeners_t::const_iterator listener_it;
	listener_it = m_woRemoveListeners.find(listener);
	if (listener_it != m_woRemoveListeners.end()) {
		m_woRemoveListeners.erase(listener_it);
	} else {
		throw std::exception("GameEventManager::\
							 unregisterWorldObjectRemoveListener(): \
							 listener not found");
	}
}