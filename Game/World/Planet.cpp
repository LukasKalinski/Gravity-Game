///////////////////////////////////////////////////////////
//  Planet.cpp
//  Implementation of the Class Planet
//  Created on:      28-mar-2008 10:31:33
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "Planet.h"


/**
 * Constructs a new planet specifying its mass and radius.
 * 
 * @param mass
 * @param radius
 * @param type    See planet_t enum.
 */
Planet::Planet(float mass, float radius, planet_t type):
StaticObject(mass, CircularShape(radius)),
m_type(type) {
}


Planet::~Planet() {
}


/**
 * Clones the world object, returning a pointer to the clone.
 */
Planet* Planet::clone() const {
	return new Planet(*this);
}


Planet::Planet(const Planet& planet):
StaticObject(planet),
m_type(planet.m_type)
{
}


/**
 * Returns the planet's type, which will be one of the public TYPE_* constants.
 */
Planet::planet_t Planet::getType() const {
	return m_type;
}
