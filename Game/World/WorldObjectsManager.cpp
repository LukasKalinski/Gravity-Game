///////////////////////////////////////////////////////////
//  WorldObjectsManager.cpp
//  Implementation of the Class WorldObjectsManager
//  Created on:      31-Mar-2008 00:29:21
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "WorldObjectsManager.h"
#include "GameEventManager.h"


/**
 * Constructs a world objects manager.
 */
WorldObjectsManager::WorldObjectsManager():
m_initialized(false),
m_eventManager(0)
{
}


WorldObjectsManager::~WorldObjectsManager() {
	
	m_movableObjects.clear();
	m_spawnPoints.clear();

	// Delete world objects:
	world_objects_t::iterator wo_it = m_worldObjects.begin();
	for ( ; wo_it != m_worldObjects.end(); ++wo_it) {
		
		// Send remove event before deleting the world object,
		// if an event manager is present (so that any potential
		// holders of the pointer get rid of it):
		if (m_eventManager) {
			m_eventManager->sendWorldObjectRemoveEvent(*wo_it);
		}

		delete *wo_it;
		*wo_it = 0;
	}
	m_worldObjects.clear();

	// Delete asteroids from insertion queue:
	while (!m_queuedAsteroids.empty()) {
		Asteroid * a = m_queuedAsteroids.front();
		
		// Make potential pointer holders aware of the removal:
		m_eventManager->sendWorldObjectRemoveEvent(a);

		m_queuedAsteroids.pop();
		delete a;
	}

	// Delete items from insertion queue:
	while (!m_queuedItems.empty()) {
		Item * i = m_queuedItems.front();
		
		// Make potential pointer holders aware of the removal:
		m_eventManager->sendWorldObjectRemoveEvent(i);

		m_queuedItems.pop();
		delete i;
	}

	// Delete ships from insertion queue:
	while (!m_queuedShips.empty()) {
		Ship * s = m_queuedShips.front();
		
		// Make potential pointer holders aware of the removal:
		m_eventManager->sendWorldObjectRemoveEvent(s);

		m_queuedShips.pop();
		delete s;
	}

	// No longer needed, and we don't own it:
	m_eventManager = 0;
}


WorldObjectsManager::WorldObjectsManager(const WorldObjectsManager& manager):
m_initialized(false),
m_eventManager(0)
{

	// Disallow copying of an initialized world objects manager:
	if (manager.m_initialized) {
		throw std::exception("WorldObjectsManager::Copy Constructor: \
							 copying initialized world objects manager \
							 not allowed");
	}

	// Copy world objects:
	world_objects_t::const_iterator wo_it = manager.m_worldObjects.begin();
	for ( ; wo_it != manager.m_worldObjects.end(); ++wo_it) {

		WorldObject * wo = (*wo_it)->clone();

		wo->setCollisionHelper(this);
		m_worldObjects.insert(wo);

		// If world object is a movable object, then add a movable object reference
		// to the newly created object:
		if (MovableObject * mwo =
			dynamic_cast<MovableObject *>(wo)) {
			m_movableObjects.insert(mwo);

		// If world object is a spawn point, then add a spawn point reference to the
		// newly created object:
		} else if (SpawnPoint * sp =
			dynamic_cast<SpawnPoint *>(wo)) {
			m_spawnPoints.insert(sp);
		}
	}

	// # Don't copy remove or insert queues, as these can only
	// # be accessed when a world objects manager is initialized.
}


/**
 * Initiates the world objects manager. Requires event manager to be present.
 */
void WorldObjectsManager::init() {
	
	if (m_initialized) {
		throw std::exception("WorldObjectsManager::init(): \
							 already initialized");
	}

	// Make sure we have an event manager:
	if (m_eventManager == 0) {
		throw std::exception("WorldObjectsManager::init(): event manager \
							 must be set before initialization");
	}

	m_initialized = true;
}


/**
 * Sets the event manager to use when cascading occuring events.
 * 
 * @param eventManager
 */
void WorldObjectsManager::setEventManager(GameEventManager* eventManager){
	
	if (eventManager == 0) {
		throw std::exception("WorldObjectsManager::setEventManager(): \
							 event manager must not be 0");
	}

	m_eventManager = eventManager;
}


/**
 * Returns an iterator of the world objects vector.
 */
WorldObjectsManager::world_objects_t& WorldObjectsManager::getWorldObjects() {
	return m_worldObjects;
}

const WorldObjectsManager::world_objects_t& WorldObjectsManager::getWorldObjects() const {
	return m_worldObjects;
}


/**
 * Returns a vector of movable objects residing in the world.
 */
WorldObjectsManager::movable_objects_t& WorldObjectsManager::getMovableObjects() {
	return m_movableObjects;
}

const WorldObjectsManager::movable_objects_t& WorldObjectsManager::getMovableObjects() const {
	return m_movableObjects;
}


/**
 * Returns a vector of spawn points residing in the world.
 */
WorldObjectsManager::spawn_points_t& WorldObjectsManager::getSpawnPoints() {
	return m_spawnPoints;
}

const WorldObjectsManager::spawn_points_t& WorldObjectsManager::getSpawnPoints() const {
	return m_spawnPoints;
}


/**
 * Ticks world objects and performs insertions and/or removals if any are queued.
 */
void WorldObjectsManager::tick() {

	if (!m_initialized) {
		throw std::exception("WorldObjectsManager::tick(): \
							 world objects manager not initialized");
	}

	performQueuedRemovals();
	performQueuedInsertions();

	// Tick world objects:
	for (world_objects_t::iterator it = m_worldObjects.begin();
		it != m_worldObjects.end();
		++it) {
		(*it)->tick();
	}
}


/**
 * Queues an insert of a ship into the world, waiting for an available spawn point.
 * Returns a pointer to the ship, expecting the receiver/holder (if any) to listen
 * for RemovalOrderEvents, to avoid keeping invalid pointers.
 * 
 * @param ship
 */
Ship* WorldObjectsManager::queueInsert(const Ship& ship) {

	if (!m_initialized) {
		throw std::exception("WorldObjectsManager::queueInsert(): must \
							 be initialized before queuing insertions");
	}

	Ship* queuedShip = ship.clone();
	m_queuedShips.push(queuedShip);
	return queuedShip;
}


/**
 * Queues an insert of an item into the world, waiting for an available spawn
 * point.
 * 
 * @param item
 */
void WorldObjectsManager::queueInsert(const Item& item) {
	
	if (!m_initialized) {
		throw std::exception("WorldObjectsManager::queueInsert(): must \
							 be initialized before queuing insertions");
	}

	m_queuedItems.push(item.clone());
}


/**
 * Queues an insert of an asteroid into the world, waiting for an available spawn
 * point.
 * 
 * @param asteroid
 */
void WorldObjectsManager::queueInsert(const Asteroid& asteroid) {

	if (!m_initialized) {
		throw std::exception("WorldObjectsManager::queueInsert(): must \
							 be initialized before queuing insertions");
	}

	m_queuedAsteroids.push(asteroid.clone());
}


/**
 * Performs the queued insertions, if any.
 */
void WorldObjectsManager::performQueuedInsertions() {

	// Order defines insertion prioritization:
	tryInsertShips();
	tryInsertItems();
	tryInsertAsteroids();
}


/**
 * Inserts a world object into the world, specifying the position that it should
 * initially appear at. Returns a pointer to the inserted world object.
 * 
 * @param wo
 * @param position
 */
WorldObject* WorldObjectsManager::insert(const WorldObject& wo, const Vector2d& position) {
	
	if (const MovableObject * mwo = dynamic_cast<const MovableObject*>(&wo)) {
		return insert(*mwo, position);
	} else if (const StaticObject * swo = dynamic_cast<const StaticObject*>(&wo)) {

		if (const SpawnPoint * sp = dynamic_cast<const SpawnPoint*>(swo)) {
			return insert(*sp, position);
		} else {
			return insert(*swo, position);
		}
	} else {
		throw std::exception("WorldObjectsManager::insert(): \
							 unknown world object");
	}
}


/**
 * Inserts a static world object into the world, specifying the position that it
 * should initially appear at. Returns a pointer to the inserted static object.
 * 
 * @param wo
 * @param position
 */
StaticObject* WorldObjectsManager::insert(const StaticObject& so, const Vector2d& position) {
	
	StaticObject* soi = so.clone();
	soi->setPosition(position);
	soi->setCollisionHelper(this);
	soi->init();

	m_worldObjects.insert(soi);

	// Notify insertion listeners about the insertion,
	// if we have an event manager set:
	if (m_eventManager) {
		m_eventManager->sendWorldObjectInsertEvent(soi);
	}

	return soi;
}


/**
 * Inserts a movable world object into the world, specifying the position that it
 * should initially appear at. Returns a pointer to the inserted movable object.
 * 
 * @param wo
 * @param position
 */
MovableObject* WorldObjectsManager::insert(const MovableObject& mwo,
										   const Vector2d& position) {

	if (!m_initialized) {
		throw std::exception("WorldObjectsManager::insert(): insertion of \
							 movable objects not allowed before initialization");
	}

	MovableObject * insertedMwo = mwo.clone();
	insert(insertedMwo, position);
	return insertedMwo;
}


/**
 * Inserts a movable world object (by pointer) into the world, specifying the
 * position that it should initially appear at.
 * 
 * @param mwo
 * @param position
 */
void WorldObjectsManager::insert(MovableObject* mwo, const Vector2d& position){

	// Set the object's position in the world:
	mwo->setPosition(position);
	mwo->setCollisionHelper(this);
	mwo->init();

	// Insert world objects into relevant sets:
	m_worldObjects.insert(mwo);
	m_movableObjects.insert(mwo);

	// Notify insertion listeners about the insertion,
	// if we have an event manager set:
	if (m_eventManager) {
		m_eventManager->sendWorldObjectInsertEvent(mwo);
	}
}


/**
 * Inserts a spawn point object into the world, specifying the position that it
 * should appear at. Returns a pointer to the inserted spawn point.
 * 
 * @param wo
 * @param position
 */
SpawnPoint* WorldObjectsManager::insert(const SpawnPoint& wo, const Vector2d& position) {

	SpawnPoint* sp = wo.clone();
	sp->setPosition(position);
	sp->setCollisionHelper(this);
	sp->init();

	// Insert spawn point into corresponding sets:
	m_worldObjects.insert(sp);
	m_spawnPoints.insert(sp);

	// Notify insertion listeners about the insertion,
	// if we have an event manager set:
	if (m_eventManager) {
		m_eventManager->sendWorldObjectInsertEvent(sp);
	}

	return sp;
}


/**
 * Queues removal of a world object, deferring the actual removal to the final
 * step of the currently ran tick().
 * 
 * @param wo
 */
void WorldObjectsManager::queueRemoval(WorldObject* wo) {

	if (!m_initialized) {
		throw std::exception("WorldObjectsManager::queueRemoval(): must \
							 be initialized before queuing removals");
	}

	m_removeQueue.insert(wo);
}


/**
 * Performs the queued removals, if any. Sends out events about the removal
 * before it is realized.
 */
void WorldObjectsManager::performQueuedRemovals() {

	remove_queue_t::iterator target_it = m_removeQueue.begin();
	for ( ; target_it != m_removeQueue.end(); ++target_it) {
		
		WorldObject* wo = *target_it;

		// Send event about the upcoming removal:
		m_eventManager->sendWorldObjectRemoveEvent(wo);

		if (MovableObject* mov = dynamic_cast<MovableObject*> (wo)) {
			remove(*mov);
		} else if (SpawnPoint* mov = dynamic_cast<SpawnPoint*> (wo)) {
			remove(*mov);
		} else {
			remove(*wo);
		}
	}
	m_removeQueue.clear();
}


/**
 * Removes a world object from the world.
 * 
 * @param wo
 */
void WorldObjectsManager::remove(WorldObject& wo) {
	std::set<WorldObject*>::iterator woit = m_worldObjects.find(&wo);
	if (woit != m_worldObjects.end()) {
		delete *woit;
		m_worldObjects.erase(woit);
	}
}


/**
 * Removes the spawn point object from the world, together with its shortcut in
 * the m_spawnPoints vector.
 * 
 * @param wo
 */
void WorldObjectsManager::remove(SpawnPoint& wo) {

	std::set<WorldObject*>::iterator woit =  m_worldObjects.find(&wo);
	std::set<SpawnPoint*>::iterator spit = m_spawnPoints.find(&wo);
	if (woit != m_worldObjects.end()) {
		delete *woit;
		m_worldObjects.erase(woit);
	}

	// Remove pointer from m_spawnPoints:
	if (spit != m_spawnPoints.end()) {
		m_spawnPoints.erase(spit);
	}
}


/**
 * Removes the movable object from the world, together with its shortcut in the
 * m_movableObjects vector.
 * 
 * @param wo
 */
void WorldObjectsManager::remove(MovableObject& wo) {

	//Removes pointer from m_worldObjects.
	std::set<WorldObject*>::iterator woit =  m_worldObjects.find(&wo);
	std::set<MovableObject*>::iterator moit = m_movableObjects.find(&wo);

	if (woit != m_worldObjects.end()) {
		delete *woit;
		m_worldObjects.erase(woit);
	}

	// Remove pointer from m_movableObjects:
	if (moit != m_movableObjects.end()) {
		m_movableObjects.erase(moit);
	}

}


/**
 * Searches for free spawn points and, if found, inserts as many of the the queued
 * ship(s) as there are available spawn points. Each ship will have its event
 * manager (the same as the world uses) set just before being inserted.
 */
void WorldObjectsManager::tryInsertShips() {

	while (!m_queuedShips.empty()) {
		bool changed = false;
		for (spawn_points_t::iterator it = m_spawnPoints.begin();
			it != m_spawnPoints.end(); ++it) {
			if ((*it)->isFree()) {
				changed = true;
				if (m_queuedShips.empty())
					break;

				Ship *ship = m_queuedShips.front();
				m_queuedShips.pop();

				// Enable ship to fire missiles:
				ship->setProjectileLauncher(this);

				// It is important that we do _not_ insert another copy
				// of the ship here, but the original pointer, as it is
				// (or may be) monitored by external observers:
				insert(ship, (*it)->getPosition());
				(*it)->toggleAvailability(false);
			}
		}
		if(!changed)
			return;
	}
}


/**
 * Searches for free spawn points and, if found, inserts as many of the the queued
 * item(s) as there are available spawn points.
 */
void WorldObjectsManager::tryInsertItems() {

	while(!m_queuedItems.empty()) {
		for(spawn_points_t::iterator it = m_spawnPoints.begin();
			it != m_spawnPoints.end(); ++it) {
			if((*it)->isFree()) {
				Item *item = m_queuedItems.front();
				m_queuedItems.pop();
				insert(*item, (*it)->getPosition());
			}
		}
	}
}


/**
 * Searches for free spawn points and, if found, inserts as many of the the queued
 * asteroid(s) as there are available spawn points.
 */
void WorldObjectsManager::tryInsertAsteroids() {

	for(spawn_points_t::iterator it = m_spawnPoints.begin();
		it != m_spawnPoints.end(); ++it) {

		if (!m_queuedAsteroids.empty() && (*it)->isFree()) {
			Asteroid *asteroid = m_queuedAsteroids.front();
			m_queuedAsteroids.pop();
			insert(*asteroid, (*it)->getPosition());
			(*it)->toggleAvailability(false);
		}
	}

}


/**
 * Queues a projectile for insertion.
 * 
 * @param firingShip
 * @param projectile
 */
void WorldObjectsManager::launch(const Ship* firingShip, const Projectile& projectile) {

	float shipAngle = firingShip->getShape().getOrientation();
	float shipRadius = firingShip->getShape().getRadius();
	float missileRadius = projectile.getShape().getRadius();

	// Ge fan i konstanten
	Vector2d positionOffset(shipRadius + missileRadius + 10, shipAngle);

	Vector2d newPos = firingShip->getPosition() + positionOffset;

	Projectile * p = dynamic_cast<Projectile*>(insert(projectile, newPos));
	m_eventManager->sendProjectileFireEvent(firingShip, p);
}


/**
 * Tells whether the two provided objects collide or not.
 * 
 * @param wo1
 * @param wo2
 */
bool WorldObjectsManager::collides(const WorldObject& wo1, const WorldObject& wo2) const {
	return (wo1.getPosition() - wo2.getPosition()).getLength() < 
		wo1.getShape().getRadius() + wo2.getShape().getRadius();
}


/**
 * Gathers all world objects that the supplied world object collides with, and
 * inserts them into the supplied container.
 * 
 * @param wo
 * @param obstacles
 */
void WorldObjectsManager::probeCollisions(const WorldObject* wo, std::vector<WorldObject*>& obstacles) {

	world_objects_t::iterator wo_it = getWorldObjects().begin();
	for ( ; wo_it != getWorldObjects().end(); ++wo_it) {
		if (*wo_it != wo && collides(*wo, **wo_it)) {
			obstacles.push_back(*wo_it);
		}
	}
}