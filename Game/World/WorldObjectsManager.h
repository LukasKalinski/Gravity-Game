///////////////////////////////////////////////////////////
//  WorldObjectsManager.h
//  Implementation of the Class WorldObjectsManager
//  Created on:      31-Mar-2008 00:29:20
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_71ED845F_8616_46a5_9510_B5804DC19359__INCLUDED_)
#define EA_71ED845F_8616_46a5_9510_B5804DC19359__INCLUDED_

#include <queue>
#include <set>
#include <exception>

#include "CollisionHelper.h"
#include "MovableObject.h"
#include "SpawnPoint.h"
#include "WorldObject.h"
#include "Tickable.h"
#include "GameEventManager.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Item.h"

/**
 * Responsible for managing insertion, retrieval and removal of world objects.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 22-Apr-2008 22:12:26
 */
class WorldObjectsManager :
	public CollisionHelper,
	public ProjectileLauncher,
	public Tickable
{

public:

	typedef std::set<WorldObject*> world_objects_t;
	typedef std::set<MovableObject*> movable_objects_t;
	typedef std::set<SpawnPoint*> spawn_points_t;

	/**
	 * Constructs a world objects manager.
	 */
	WorldObjectsManager();
	virtual ~WorldObjectsManager();
	WorldObjectsManager(const WorldObjectsManager& woManager);

	/**
	 * Initiates the world objects manager. Requires event manager to be present.
	 */
	void init();

	/**
	 * Sets the event manager to use when cascading occuring events.
	 * 
	 * @param eventManager
	 */
	void setEventManager(GameEventManager* eventManager);

	/**
	 * Returns an iterator of the world objects vector.
	 */
	world_objects_t& getWorldObjects();
	const world_objects_t& getWorldObjects() const;

	/**
	 * Returns a vector of movable objects residing in the world.
	 */
	movable_objects_t& getMovableObjects();
	const movable_objects_t& getMovableObjects() const;

	/**
	 * Returns a vector of spawn points residing in the world.
	 */
	spawn_points_t& getSpawnPoints();
	const spawn_points_t& getSpawnPoints() const;

	/**
	 * Notifies the object about that the time is being incremented with one time unit.
	 */
	virtual void tick();

	/**
	 * Queues an insert of a ship into the world, waiting for an available spawn point.
	 * Returns a pointer to the ship, expecting the receiver/holder (if any) to listen
	 * for RemovalOrderEvents, to avoid keeping invalid pointers.
	 * 
	 * @param ship
	 */
	Ship* queueInsert(const Ship& ship);

	/**
	 * Queues an insert of an item into the world, waiting for an available spawn
	 * point.
	 * 
	 * @param item
	 */
	void queueInsert(const Item& item);

	/**
	 * Queues an insert of an asteroid into the world, waiting for an available spawn
	 * point.
	 * 
	 * @param asteroid
	 */
	void queueInsert(const Asteroid& asteroid);

	/**
	 * Inserts a world object into the world, specifying the position that it should
	 * initially appear at. Returns a pointer to the inserted world object.
	 * 
	 * @param wo
	 * @param position
	 */
	WorldObject* insert(const WorldObject& wo, const Vector2d& position);

	/**
	 * Inserts a static world object into the world, specifying the position that it
	 * should initially appear at. Returns a pointer to the inserted static object.
	 * 
	 * @param wo
	 * @param position
	 */
	StaticObject* insert(const StaticObject& wo, const Vector2d& position);

	/**
	 * Inserts a movable world object into the world, specifying the position that it
	 * should initially appear at. Returns a pointer to the inserted movable object.
	 * 
	 * @param wo
	 * @param position
	 */
	MovableObject* insert(const MovableObject& wo, const Vector2d& position);

	/**
	 * Inserts a spawn point object into the world, specifying the position that it
	 * should appear at. Returns a pointer to the inserted spawn point.
	 * 
	 * @param wo
	 * @param position
	 */
	SpawnPoint* insert(const SpawnPoint& wo, const Vector2d& position);

	/**
	 * Queues removal of a world object, deferring the actual removal to the final
	 * step of the currently ran tick().
	 * 
	 * @param wo
	 */
	void queueRemoval(WorldObject* wo);

	/**
	 * Queues a projectile for insertion.
	 * 
	 * @param firingShip
	 * @param projectile
	 */
	virtual void launch(const Ship* firingShip, const Projectile& projectile);

	/**
	 * Gathers all world objects that the supplied world object collides with, and
	 * inserts them into the supplied container.
	 * 
	 * @param wo
	 * @param obstacles
	 */
	void probeCollisions(const WorldObject* wo, std::vector<WorldObject*>& obstacles);

private:

	typedef std::queue<Asteroid*>	asteroid_queue_t;
	typedef std::queue<Item*>		item_queue_t;
	typedef std::queue<Ship*>		ship_queue_t;
	typedef std::set<WorldObject*>	remove_queue_t;

	/**
	 * Tells whether the world objects manager has been initialized or not.
	 */
	bool m_initialized;

	/**
	 * The objects currently present in the world.
	 */
	world_objects_t m_worldObjects;

	/**
	 * Shortcut list to all movable objects in the world.
	 */
	movable_objects_t m_movableObjects;

	/**
	 * Shortcut list to all spawn points in the world.
	 */
	spawn_points_t m_spawnPoints;

	/**
	 * Queue of world objects to remove at the end of tick(). Using
	 * set to avoid having the same world object queued more than once.
	 */
	remove_queue_t m_removeQueue;

	/**
	 * Ships that are queued for insertion on a free spawn point. Once inserted, the
	 * responsibility for the ship pointer goes to m_worldObjects.
	 */
	ship_queue_t m_queuedShips;

	/**
	 * Items that are queued for insertion on a free spawn point. Once inserted, the
	 * responsibility for the item pointer goes to m_worldObjects.
	 */
	item_queue_t m_queuedItems;

	/**
	 * Asteroids that are queued for insertion on a free spawn point. Once inserted,
	 * the responsibility for the asteroid pointer goes to m_worldObjects.
	 */
	asteroid_queue_t m_queuedAsteroids;

	/**
	 * The game event manager to cascade occuring events to.
	 */
	GameEventManager *m_eventManager;

	/**
	 * Performs the queued insertions, if any.
	 */
	void performQueuedInsertions();

	/**
	 * Performs the queued removals, if any. Sends out events about the removal
	 * before it is realized.
	 */
	void performQueuedRemovals();

	/**
	 * Removes a world object from the world.
	 * 
	 * @param wo
	 */
	void remove(WorldObject& wo);

	/**
	 * Removes the spawn point object from the world, together with its shortcut in
	 * the m_spawnPoints vector.
	 * 
	 * @param wo
	 */
	void remove(SpawnPoint& wo);

	/**
	 * Removes the movable object from the world, together with its shortcut in the
	 * m_movableObjects vector.
	 * 
	 * @param wo
	 */
	void remove(MovableObject& wo);

	/**
	 * Searches for free spawn points and, if found, inserts as many of the the queued
	 * ship(s) as there are available spawn points. Each ship will have its event
	 * manager (the same as the world uses) set just before being inserted.
	 */
	void tryInsertShips();

	/**
	 * Searches for free spawn points and, if found, inserts as many of the the queued
	 * item(s) as there are available spawn points.
	 */
	void tryInsertItems();

	/**
	 * Searches for free spawn points and, if found, inserts as many of the the queued
	 * asteroid(s) as there are available spawn points.
	 */
	void tryInsertAsteroids();

	/**
	 * Inserts a movable world object (by pointer) into the world, specifying the
	 * position that it should initially appear at.
	 * 
	 * @param mwo
	 * @param position
	 */
	void insert(MovableObject* mwo, const Vector2d& position);

	/**
	 * Tells whether the two provided objects collide or not.
	 * 
	 * @param wo1
	 * @param wo2
	 */
	bool collides(const WorldObject& wo1, const WorldObject& wo2) const;

};
#endif // !defined(EA_71ED845F_8616_46a5_9510_B5804DC19359__INCLUDED_)
