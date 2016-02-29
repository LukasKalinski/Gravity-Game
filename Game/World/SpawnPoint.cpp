///////////////////////////////////////////////////////////
//  SpawnPoint.cpp
//  Implementation of the Class SpawnPoint
//  Created on:      28-mar-2008 10:34:33
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <math.h>
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif


#include "SpawnPoint.h"


/**
 * Constructs a spawn point with a circular shape and mass == 0.
 */
SpawnPoint::SpawnPoint():
StaticObject(0.0, CircularShape(32.0f)),
m_isFree(true)
{
}


SpawnPoint::~SpawnPoint() {
}


/**
 * Clones the world object, returning a pointer to the clone.
 */
SpawnPoint* SpawnPoint::clone() const {
	return new SpawnPoint(*this);
}


SpawnPoint::SpawnPoint(const SpawnPoint& sp):
StaticObject(sp),
m_isFree(sp.m_isFree)
{
}


/**
 * Returns true if the spawn point is free to use, i.e., that no other world
 * object spawned in it for a certain amount of time, otherways false is returned.
 */
bool SpawnPoint::isFree() const {
	return m_isFree;
}


/**
 * Toggles the availability of the spawn point by setting free to false or true.
 */
void SpawnPoint::toggleAvailability(bool setFree) {
	m_isFree = setFree;
}


/**
 * Rotates the spawn point.
 */
void SpawnPoint::tick() {

	StaticObject::tick();

	float newOrientation = m_shape->getOrientation();
	newOrientation += 0.03f;
	if (newOrientation >= 2*M_PI) {
		newOrientation = 0;
	}
	m_shape->setOrientation(newOrientation);
}