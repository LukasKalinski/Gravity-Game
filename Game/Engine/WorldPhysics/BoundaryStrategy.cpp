///////////////////////////////////////////////////////////
//  BoundaryStrategy.cpp
//  Implementation of the Class BoundaryStrategy
//  Created on:      28-mar-2008 10:24:00
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "BoundaryStrategy.h"
#include "World.h"


/**
 * Constructs a world boundary strategy.
 */
BoundaryStrategy::BoundaryStrategy() {
}


BoundaryStrategy::~BoundaryStrategy() {
}


BoundaryStrategy::BoundaryStrategy(const BoundaryStrategy& strategy) {
}


/**
 * Loops throuh all world objects and takes care of those that are found
 * outside the boundaries defined in world.
 */
void BoundaryStrategy::applyWorldStrategy(World& world) {

	WorldObjectsManager::world_objects_t worldObjects;
	WorldObjectsManager::world_objects_t::iterator worldObject_it;

	worldObjects = world.getWorldObjectsManager().getWorldObjects();
	worldObject_it = worldObjects.begin();

	for ( ; worldObject_it != worldObjects.end(); ++worldObject_it) {
		manage(**worldObject_it, world);
	}
}