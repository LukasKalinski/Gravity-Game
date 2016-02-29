///////////////////////////////////////////////////////////
//  CollisionStrategy.cpp
//  Implementation of the Class CollisionStrategy
//  Created on:      28-mar-2008 10:24:24
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <math.h>
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#include "CollisionStrategy.h"
#include "World.h"

#include <iostream>
#include <algorithm>

CollisionStrategy::CollisionStrategy() {

}


CollisionStrategy::~CollisionStrategy() {

}


//CollisionStrategy::CollisionStrategy(const CollisionStrategy& strategy) {
//	throw std::exception("CollisionStrategy: Copy constructor called.");
//}
namespace {
float getLeft(WorldObject* obj) {
	return obj->getPosition().getX() - obj->getShape().getRadius();
}
float getRight(WorldObject* obj) {
	return obj->getPosition().getX() + obj->getShape().getRadius();
}

struct LeftCmp {

	bool operator()(WorldObject* a, WorldObject* b) {
		return getLeft(a) < getLeft(b);
	}
};

struct RightValueLessThan {
	float x;
	RightValueLessThan(float xx) : x(xx) {}
	// Returns true if a has a right value less than x
	bool operator()(WorldObject* a) {
		return getRight(a) < x;
	}
};
}
void CollisionStrategy::checkYTest(World* world, WorldObject& wo1, WorldObject& wo2) {
	if (collidesWith(wo1, wo2)) {
		handleCollision(*world, &wo2, &wo1);
		if(!(dynamic_cast<Ship*> (&wo1) && dynamic_cast<Ship*> (&wo2)))
			handleCollision(*world, &wo1, &wo2);
	}
}
int collTestCount =0;
/**
 * Searches for and handles collisions in the world.
 */
void CollisionStrategy::applyWorldStrategy(World& world) {
	collTestCount=0;
	WorldObjectsManager::world_objects_t objects = 
		world.getWorldObjectsManager().getWorldObjects();

	WorldObjectsManager::spawn_points_t spawnpoints = 
		world.getWorldObjectsManager().getSpawnPoints();

	for (WorldObjectsManager::spawn_points_t::iterator it = spawnpoints.begin();
		it!=spawnpoints.end(); ++it) {
		(*it)->toggleAvailability(true);
	}

	// sorted according to the left side
	std::vector<WorldObject*> left(objects.begin(), objects.end());
	std::sort(left.begin(), left.end(), LeftCmp());

	std::vector<WorldObject*> workingSet;

	for (unsigned int i=0; i<left.size(); i++) {
		WorldObject* curr = left[i];
		// remove the objects from workingSet that got a right value larger
		// then the left of curr
		workingSet.erase(
			std::remove_if(
				workingSet.begin(),
				workingSet.end(),
				RightValueLessThan(getLeft(curr))),
			workingSet.end());
		// now all objects in workingSet intersects with curr in the x-axis

		// we should check them
		for (std::vector<WorldObject*>::iterator it=workingSet.begin();
			it != workingSet.end(); ++it)
		{
			collTestCount++;
			checkYTest(&world, *curr, **it);
		}

		workingSet.push_back(curr);
	}

	//// Compare each pair of objects to se if they collides.
	//for (WorldObjectsManager::world_objects_t::iterator it = objects.begin();
	//	it!=objects.end(); ++it) {
	//	for (WorldObjectsManager::world_objects_t::iterator it2 = it;
	//		it2!=objects.end(); ++it2) {
	//			collTestCount++;
	//			if (*it!=*it2 && collidesWith(**it2, **it)) {
	//				handleCollision(world, *it2, *it);
	//				if(!(dynamic_cast<Ship*> (*it) && dynamic_cast<Ship*> (*it2)))
	//					handleCollision(world, *it, *it2);
	//			}
	//	}
	//}
	//std::cout << "collTestCount= " << collTestCount << std::endl;
}


/**
 * Tells whether two objects collide or not.
 */
bool CollisionStrategy::collidesWith(const WorldObject& wo1, const WorldObject& wo2) {
	// Checks if the distance between two objects are
	// less than their combined radiuses. If so, it's a collision.
	// Assumes everything is circular in a way.
	return (wo1.getPosition() - wo2.getPosition()).getLength() < 
		wo1.getShape().getRadius() + wo2.getShape().getRadius();
}


/**
 * Leaves active object unaffected. This function catches all cases where no
 * collision handling is required.
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World& world,
										WorldObject* active,
										WorldObject* passive) {
	// throw std::exception("CollisionStrategy::handleCollision() catch all function called!!!!!!1111!!");
	
	if(Item* item = dynamic_cast<Item*>(active) ) {
		//virtual void handleCollision(Item* active, const Ship* passive);
		if(const Ship* ship = dynamic_cast<const Ship*>(passive))
			handleCollision(item, ship);
	}
	if(Ship* ship = dynamic_cast<Ship*>(active) ) {
		//virtual void handleCollision(Ship* active, const FuelItem* passive);
		if(const FuelItem* fuelItem = dynamic_cast<const FuelItem*>(passive))
			handleCollision(ship, fuelItem);
	}
	if(Ship* ship = dynamic_cast<Ship*>(active) ) {
		//virtual void handleCollision(Ship* active, const MissileItem* passive);
		if(const MissileItem* missileItem = dynamic_cast<const MissileItem*>(passive))
			handleCollision(ship, missileItem);
	}
	if(SpawnPoint* spawnPoint = dynamic_cast<SpawnPoint*>(active) ) {
		//virtual void handleCollision(SpawnPoint* active, const MovableObject* passive);
		if(const MovableObject* movableObject = dynamic_cast<const MovableObject*>(passive))
			handleCollision(spawnPoint, movableObject);
	}
	if(Projectile* projectile = dynamic_cast<Projectile*>(active) ) {
		//virtual void handleCollision(Projectile* active, const DestroyableObject* passive);
		if(const DestroyableObject* destroyableObject = dynamic_cast<const DestroyableObject*>(passive))
			handleCollision(world, projectile, destroyableObject);
	}
	if(DestroyableObject* destroyableObject = dynamic_cast<DestroyableObject*>(active) ) {
		//virtual void handleCollision(DestroyableObject* active, const Projectile* passive);
		if(const Projectile* projectile = dynamic_cast<const Projectile*>(passive))
			handleCollision(world, destroyableObject, projectile);
	}
	if(DestroyableObject* destroyableObject = dynamic_cast<DestroyableObject*>(active) ) {
		//virtual void handleCollision(DestroyableObject* active, const Planet* passive);
		if(const Planet* planet = dynamic_cast<const Planet*>(passive))
			handleCollision(world, destroyableObject, planet);
	}
	if(Asteroid* asteroid = dynamic_cast<Asteroid*>(active) ) {
		//virtual void handleCollision(Asteroid* active, const Asteroid* passive);
		if(const Asteroid* asteroid2 = dynamic_cast<const Asteroid*>(passive))
			handleCollision(world, asteroid, asteroid2);
	}
	if(Ship* ship = dynamic_cast<Ship*>(active) ) {
		//virtual void handleCollision(Ship* active, const Ship* passive);
		if(Ship* ship2 = dynamic_cast<Ship*>(passive))
			handleCollision(&world, ship, ship2);
	}
	if(Ship* ship = dynamic_cast<Ship*>(active) ) {
		//virtual void handleCollision(Ship* active, const Asteroid* passive);
		if(const Asteroid* asteroid = dynamic_cast<const Asteroid*>(passive))
			handleCollision(world, ship, asteroid);
	}
	if(Asteroid* asteroid = dynamic_cast<Asteroid*>(active) ) {
		//virtual void handleCollision(Asteroid* active, const Ship* passive);
		if(const Ship* ship = dynamic_cast<const Ship*>(passive))
			handleCollision(asteroid, ship);
	}
	if(LaserProjectile* laserProjectile = dynamic_cast<LaserProjectile*>(active) ) {
		//virtual void handleCollision(LaserProjectile* active, const Planet* passive);
		if(const Planet* planet = dynamic_cast<const Planet*>(passive))
			handleCollision(world, laserProjectile, planet);
	}


}


/**
 * Removes the item as a result of it being picked up by the ship.
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(Item* active, const Ship* passive) {

}


/**
 * Increases the ship's fuel level.
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(Ship* active, const FuelItem* passive) {

}


/**
 * Increases the ship's missile count.
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(Ship* active, const MissileItem* passive) {

}


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
void CollisionStrategy::handleCollision(SpawnPoint* active, const MovableObject* passive) {
	active->toggleAvailability(false);
}


/**
 * Puts the projectile in the world's remove queue, as it is considered consumed.
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World& world,
										Projectile* active,
										const DestroyableObject* passive) {

	world.getEventManager().sendWorldObjectRemoveEvent(active);

	if (WorldObject * wo = dynamic_cast<WorldObject*>(active)) {
		world.getWorldObjectsManager().queueRemoval(wo);
	} else {
		throw std::exception("CollisionStrategy::handleCollision(): \
							 destroyable object was not a world object");
	}
}


/**
 * Causes damage on the destroyable object, according to the projectile's "max
 * damage strength".
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World& world, 
										DestroyableObject* active,
										const Projectile* passive) {
	
	world.getEventManager().sendWorldObjectDestructionEvent(active, passive);

	if (WorldObject * wo = dynamic_cast<WorldObject*>(active)) {
		world.getWorldObjectsManager().queueRemoval(wo);
	} else {
		throw std::exception("CollisionStrategy::handleCollision(): \
							 destroyable object was not a world object");
	}
}


/**
 * Destroys the destroyable object.
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World& world,
										DestroyableObject* active,
										const Planet* passive) {
	//std::cout << "Collision between DestroyableObject and Planet!" << std::endl;

	world.getEventManager().sendWorldObjectDestructionEvent(active, passive);

	if (WorldObject * wo = dynamic_cast<WorldObject*>(active)) {
		world.getWorldObjectsManager().queueRemoval(wo);
	} else {
		throw std::exception("CollisionStrategy::handleCollision(): \
							 destroyable object was not a world object");
	}
}


/**
 * Causes damage on the active asteroid according to the collision power (i.e.,
 * the movement towards the other asteroid).
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World& world, Asteroid* active, const Asteroid* passive) {
	world.getEventManager().sendWorldObjectDestructionEvent(active, passive);

	if (WorldObject * wo = dynamic_cast<WorldObject*>(active)) {
		world.getWorldObjectsManager().queueRemoval(wo);
	} else {
		throw std::exception("CollisionStrategy::handleCollision(): \
							 destroyable object was not a world object");
	}
}


/**
 * Causes damage on the active ship according to the collision power (i.e., the
 * movement towards the other ship).
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World* world, Ship* active, Ship* passive) {
	active->setPosition(active->getPosition()-active->getMovement());
	passive->setPosition(passive->getPosition()-passive->getMovement());

	Vector2d active_movement;
	active_movement = active->getMovement();
	Vector2d half_active_movement;
	half_active_movement = active_movement/2;

	Vector2d passive_movement;
	passive_movement = passive->getMovement();
	Vector2d half_passive_movement;
	half_passive_movement = passive_movement / 2;
	

	active_movement = (-half_active_movement)   + half_passive_movement;
	passive_movement = (-half_passive_movement)  + half_active_movement;

	active->setMovement(active_movement);
	passive->setMovement(passive_movement);

	world->getEventManager().sendBoingEvent();
}


/**
 * Causes damage to the ship according to the collision power (i.e., the movement
 * towards the asteroid).
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World &world, Ship* active, const Asteroid* passive) {

	world.getEventManager().sendWorldObjectDestructionEvent(active, passive);

	if (WorldObject * wo = dynamic_cast<WorldObject*>(active)) {
		world.getWorldObjectsManager().queueRemoval(wo);
	} else {
		throw std::exception("CollisionStrategy::handleCollision(): \
							 destroyable object was not a world object");
	}
}


/**
 * Causes damage to the asteroid according to the collision power (i.e., the
 * movement towards the ship).
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(Asteroid* active, const Ship* passive) {
	active->setMovement(active->getMovement() + passive->getMovement());
}


/**
 * Bounces the laser projectile on the planet.
 * 
 * @param active    The world object that actively participates in the
 * intersection, i.e., may be affected by it.
 * @param passive    The world object that passively participates in the
 * intersection, i.e., will not be affected by it (in this function).
 */
void CollisionStrategy::handleCollision(World& world,
										LaserProjectile* laser,
										const Planet* planet)
{
	laser->setPosition(laser->getPosition() - laser->getMovement());
	world.getWorldObjectsManager().queueRemoval(laser);
	//Vector2d v = laser->getPosition();
	//Vector2d u = planet->getPosition();
	//Vector2d w = u - v;

	//// Movement vector as a unit vector:
	//Vector2d m(1.0f, laser->getMovement().getAngle());

	//float r1 = planet->getShape().getRadius();
	//float r2 = laser->getShape().getRadius();

	//// # Using formula '||v - x*m + u|| == r1 + r2' in order to
	//// # calculate the fallback vector (i.e., the counter-movement
	//// # vector to apply so that the objects' shapes intersect).
	//// # The solution is derived from putting everything on the
	//// # 'x^2 + px + q = 0' form.

	//// Get vector components shortcuts:
	////float v1 = v.getX();
	////float v2 = v.getY();
	////float u1 = u.getX();
	////float u2 = u.getY();
	//float w1 = w.getX();
	//float w2 = w.getY();
	////float m1 = m.getX() * cos(m.getAngle());
	////float m2 = m.getY() * sin(m.getAngle());

	//float p = -2 * (m1 + m2) / (m1*m1 + m2*m2);
	//float q = (w1*w1 + w2*w2 - (r1 + r2)*(r1 + r2)) / (m1*m1 + m2*m2);

	////float p = 2 * (v1*m1 + u1*m1 + v2*m2 + u2*m2) / (m1*m1 + m2*m2);
	////float q = v1*v1 + u1*u1 + v2*v2 + u2*u2 - 2*v1*u1 - 2*v2*u2 - ((r1 + r2)*(r1 + r2));

	//// Calculate the length of the fallback vector:
	//float x = -p/2 + sqrt(((p/2)*(p/2)) - q);

	//laser->setPosition(laser->getPosition() - Vector2d(Coord2d(m.getX()*x, m.getY()*x)));

	//laser->setMovement(Vector2d(0,0));

	//if (laser->getPosition().getX() > 5000) {

	//	std::cout
	//		<< "Laser pos: ("
	//		<< laser->getPosition().getX()
	//		<< ","
	//		<< laser->getPosition().getY()
	//		<< ")"
	//		<< std::endl;
	//	std::cout
	//		<< "Planet pos: ("
	//		<< planet->getPosition().getX()
	//		<< ","
	//		<< planet->getPosition().getY()
	//		<< ")"
	//		<< std::endl;
	//}

	/*Vector2d newMovement(
		laser->getMovement().getLength(),
		laser->getMovement().getAngle() + static_cast<float>(M_PI));*/
	/*Vector2d normal = laser->getPosition() - planet->getPosition();
	Vector2d diff = newMovement - normal;
	if (newMovement.getAngle() > static_cast<float>(M_PI)) {

	}
	newMovement = Vector2d(newMovement.getLength(), newMovement.getAngle() + diff.getAngle()*2);
	*/
	//laser->setMovement(newMovement);
	/*laser->setPosition(laser->getPosition() +
		Vector2d(newMovement.getLength() + (m*x).getLength(), newMovement.getAngle()));*/

	//// Calculate normal to the planet's surface at the point of collision:
	//Vector2d collisionNormal = laser->getPosition() - planet->getPosition();

	//float angleOfArrival = laser->getMovement().getAngle() - collisionNormal.getAngle();

	//Vector2d bounceMovement(laser->getMovement().getLength(), -1 * angleOfArrival);
	//laser->setMovement(bounceMovement);


	//laser->setMovement(Vector2d(0, 0));
	

	//// If the laser is found inside the planet, then move it out
	//// and save the overflow vector length:
	//float intersectionDistance =
	//	active->getShape().getRadius() +
	//	passive->getShape().getRadius();
	//Vector2d diffVector = passive->getPosition() - active->getPosition();
	//float overflow = intersectionDistance - diffVector.getLength();
	//Vector2d fallback(overflow, active->getPosition().getAngle());
	//active->setPosition(active->getPosition() + fallback);

	//// Define the normal to the point on the planet's surface
	//// where the collision occurs:
	//Vector2d normal(active->getPosition() + passive->getPosition());

	//// Calculate difference between the normal's angle and the angle
	//// of arrival:
	//float diffAngle = laser->getMovement().getAngle() - collisionNormal.getAngle();
	//laser->setMovement(
	//	Vector2d(
	//		laser->getMovement().getLength(),
	//		diffAngle*2 + static_cast<float>(M_PI)));
	//active->setPosition(active->getPosition() + active->getMovement());

	//world.getWorldObjectsManager().queueRemoval(active);
}


/**
 * Clones the collision strategy, returning the clone.
 */
CollisionStrategy* CollisionStrategy::clone() const {
	return new CollisionStrategy(*this);
}
