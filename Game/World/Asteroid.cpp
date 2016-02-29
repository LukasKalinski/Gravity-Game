///////////////////////////////////////////////////////////
//  Asteroid.cpp
//  Implementation of the Class Asteroid
//  Created on:      28-mar-2008 10:23:35
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "Asteroid.h"
#include "CircularShape.h"


/**
 * Constructs an asteroid, specifying the rotation direction, its speed and the
 * asteroid's mass.
 */
Asteroid::Asteroid(float rotationSpeed, float mass):
MovableObject(mass, CircularShape(20.0f)),
m_rotationSpeed(rotationSpeed),
DestroyableObject(INIT_STRENGTH) {
}


/**
 * Constructs an asteroid, specifying the rotation direction and its speed, the
 * asteroid's mass and its shape.
 */
Asteroid::Asteroid(float rotationSpeed, float mass, const Shape& shape):
MovableObject(mass, shape),
m_rotationSpeed(rotationSpeed),
DestroyableObject(INIT_STRENGTH) {
}


/**
 * Clones the world object, returning a pointer to the clone.
 */
Asteroid* Asteroid::clone() const {
	return new Asteroid(*this);
}


Asteroid::~Asteroid() {

}


Asteroid::Asteroid(const Asteroid& asteroid):
MovableObject(asteroid), DestroyableObject(asteroid),
m_rotationSpeed(asteroid.m_rotationSpeed) {
}


/**
 * Updates position and orientation (i.e., rotation).
 */
void Asteroid::tick() {

	//Updates position and orientation (i.e.,
	//rotation).
	m_position = m_position + m_movement;
	m_shape->setOrientation(m_shape->getOrientation() + m_rotationSpeed);

}


/**
 * Initial strength of an asteroid.
 */
const float Asteroid::INIT_STRENGTH = 3.0f;