///////////////////////////////////////////////////////////
//  GravityStrategy.cpp
//  Implementation of the Class GravityStrategy
//  Created on:      28-mar-2008 10:27:34
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <iostream>

#include "GravityStrategy.h"


GravityStrategy::GravityStrategy() {

}


GravityStrategy::~GravityStrategy() {

}

//
//GravityStrategy::GravityStrategy(const GravityStrategy& strategy) {
//	throw std::exception("GravityStrategy.cpp: Copy constructor called.");
//}


/**
 * Does no affection. This function only exists to catch all cases which the other
 * affect function(s) can't handle.
 */
void GravityStrategy::affect(const WorldObject& wo1, const WorldObject& wo2) {
	throw std::exception("GravityStrategy::affect() Catch all function called.");
}


/**
 * Affects a movable object with a planet's gravity, in proportion to the object's
 * mass.
 */
void GravityStrategy::affect(MovableObject& mwo, const Planet& swo) {

	// Vector from planet to object.
	Vector2d mwo_to_swo = swo.getPosition() - mwo.getPosition();

	// Distance between centers of object and planet.
	float distance = mwo_to_swo.getLength();

	// Unit vector pointing at planet from MovableObject.
	Vector2d planet_to_obj = mwo_to_swo/distance;

	// Note to Jesper: Should it be this way?
	// The gravity strategy seems to mess up when mass is 0...
	if (mwo.getMass() == 0) {
		return;
	}

	if(distance < 15.0)
		return;

	// std::cout << "Planet to obj: " << planet_to_obj.getX() << " " << planet_to_obj.getY() << std::endl;

	float G = 10.0f;

	// Value of force.
	float force = (G * mwo.getMass() * swo.getMass()) / (distance*distance);

	// Complete force with direction.
	Vector2d forcedir = planet_to_obj * force;

	// Amount of acceleration.
	Vector2d acc = forcedir / mwo.getMass();

	// Accelerate movableobject.
	Vector2d mov(mwo.getMovement());
	mov = mov + acc;
	mwo.setMovement(mov);
}


/**
 * Affects all movable world objects found in the world according to their gravity
 * fields.
 */
void GravityStrategy::applyWorldStrategy(World& world) {
	// Movable objects
	typedef WorldObjectsManager::movable_objects_t movable_objects_t;
	movable_objects_t mov_objects =
		world.getWorldObjectsManager().getMovableObjects();
	// All objects.
	typedef WorldObjectsManager::world_objects_t world_objects_t;
	world_objects_t wobjects =
		world.getWorldObjectsManager().getWorldObjects();

	// Build a temporary array with pointers to all planets.
	std::vector<Planet*> planets;
	for(world_objects_t::iterator it = wobjects.begin();
		it != wobjects.end();
		++it)
	{
		if(Planet* planet = dynamic_cast<Planet*> (*it)) {
			planets.push_back(planet);
		}
	}

	// Go through all movable objects and affect them by gravity.
	for(std::vector<Planet*>::iterator it = planets.begin();
		it!=planets.end();
		++it) {
			for(movable_objects_t::iterator mov_it = mov_objects.begin();
				mov_it!=mov_objects.end();
				++mov_it) {
					affect(**mov_it, **it);
			}
	}
}


/**
 * Clones the gravity strategy, returning the clone.
 */
GravityStrategy* GravityStrategy::clone() const {
	return new GravityStrategy(*this);
}