///////////////////////////////////////////////////////////
//  MovableObject.cpp
//  Implementation of the Class MovableObject
//  Created on:      28-mar-2008 10:30:47
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "MovableObject.h"


/**
 * Constructs a movable object.
 * 
 * @param mass
 * @param shape
 */
MovableObject::MovableObject(float mass, const Shape& shape):
WorldObject(mass, shape),
m_movement(0.0f, 0) {
}


MovableObject::~MovableObject() {

}


MovableObject::MovableObject(const MovableObject& mo):
WorldObject(mo), m_movement(mo.m_movement) {
}


/**
 * Returns the movement vector of the movable object. The magnitude represents the
 * speed and the angle represents the direction of movement.
 */
const Vector2d& MovableObject::getMovement() const {
	return m_movement;
}


/**
 * Changes the movement of the movable world object. A change here may result in a
 * change in the object's orientation, depending on the object type.
 */
void MovableObject::setMovement(const Vector2d& movement) {
	m_movement = movement;
}


/**
 * Updates the position of the movable object.
 */
void MovableObject::tick() {

}
