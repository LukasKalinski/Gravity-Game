///////////////////////////////////////////////////////////
//  CollisionStrategy.h
//  Implementation of the Class CollisionStrategy
//  Created on:      28-mar-2008 10:24:19
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_26E6A8E4_120E_45fe_B2B6_3720A320951E__INCLUDED_)
#define EA_26E6A8E4_120E_45fe_B2B6_3720A320951E__INCLUDED_

#include "WorldStrategy.h"
#include "WorldObject.h"
#include "Item.h"
#include "Ship.h"
#include "SpawnPoint.h"
#include "FuelItem.h"
#include "MissileItem.h"
#include "Projectile.h"
#include "LaserProjectile.h"
#include "DestroyableObject.h"
#include "Planet.h"
#include "Asteroid.h"



/**
 * Responsible for detecting and handling collisions between objects in the game
 * world, provided a game world instance.
 */
class CollisionStrategy : public WorldStrategy
{

public:
	CollisionStrategy();
	virtual ~CollisionStrategy();

	//CollisionStrategy(const CollisionStrategy& strategy);

	virtual void applyWorldStrategy(World& world);

	/**
	 * Clones the collision strategy, returning the clone.
	 */
	virtual CollisionStrategy* clone() const;

private:

	void checkYTest(World* world, WorldObject& wo1, WorldObject& wo2);

	bool collidesWith(const WorldObject& wo1, const WorldObject& wo2);

	/**
	 * Leaves active object unaffected. This function catches all cases where no
	 * collision handling is required.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World& world, WorldObject* active, WorldObject* passive);

	/**
	 * Removes the item as a result of it being picked up by the ship.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(Item* active, const Ship* passive);

	/**
	 * Increases the ship's fuel level.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(Ship* active, const FuelItem* passive);

	/**
	 * Increases the ship's missile count.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(Ship* active, const MissileItem* passive);

	/**
	 * Sets the spawn point to not being free (see SpawnPoint::toggleFree()). Note
	 * that: if an item appears on a spawn point, the spawn point shall still be
	 * considered free.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(SpawnPoint* active, const MovableObject* passive);

	/**
	 * Puts the projectile in the world's remove queue, as it is considered consumed.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World& world, Projectile* active, const DestroyableObject* passive);

	/**
	 * Causes damage on the destroyable object, according to the projectile's "max
	 * damage strength".
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World& world, DestroyableObject* active, const Projectile* passive);

	/**
	 * Destroys the destroyable object.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World& world, DestroyableObject* active, const Planet* passive);

	/**
	 * Causes damage on the active asteroid according to the collision power (i.e.,
	 * the movement towards the other asteroid).
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World& world, Asteroid* active, const Asteroid* passive);

	/**
	 * Causes damage on the active ship according to the collision power (i.e., the
	 * movement towards the other ship).
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World* world, Ship* active, Ship* passive);

	/**
	 * Causes damage to the ship according to the collision power (i.e., the movement
	 * towards the asteroid).
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World &world, Ship* active, const Asteroid* passive);

	/**
	 * Causes damage to the asteroid according to the collision power (i.e., the
	 * movement towards the ship).
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(Asteroid* active, const Ship* passive);

	/**
	 * Bounces the laser projectile on the planet.
	 * 
	 * @param active    The world object that actively participates in the
	 * intersection, i.e., may be affected by it.
	 * @param passive    The world object that passively participates in the
	 * intersection, i.e., will not be affected by it (in this function).
	 */
	virtual void handleCollision(World& world, LaserProjectile* active, const Planet* passive);

};
#endif // !defined(EA_26E6A8E4_120E_45fe_B2B6_3720A320951E__INCLUDED_)
