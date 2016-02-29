///////////////////////////////////////////////////////////
//  WorldObject.cpp
//  Implementation of the Class WorldObject
//  Created on:      28-mar-2008 10:36:23
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <exception>

#include "WorldObject.h"


/**
 * Constructs a world object, specifying its shape.
 */
WorldObject::WorldObject(float mass, const Shape& shape):
m_collisionHelper(0),
m_mass(mass),
m_shape(shape.clone()),
m_position(Vector2d(0.0f, 0.0f)),
m_initialized(false)
{
}


WorldObject::~WorldObject() {
	delete m_shape;
}


WorldObject::WorldObject(const WorldObject& wo):
m_mass(wo.m_mass),
m_shape(wo.m_shape->clone()),
m_position(wo.m_position),
m_initialized(wo.m_initialized),
m_collisionHelper(wo.m_collisionHelper)
{
}


/**
 * Initializes the world object, making it aware that it now is present in a world
 * environment.
 */
void WorldObject::init() {

	if (m_initialized) {
		throw std::exception("WorldObject::init(): already initialized");
	}

	if (!m_collisionHelper) {
		throw std::exception("WorldObject::init(): collision helper \
							 not present");
	}

	m_initialized = true;
}


/**
 * Returns the mass of the world object.
 */
float WorldObject::getMass() const {
	return m_mass;
}


/**
 * Returns the position of the object in the world, according to the object's
 * centre.
 */
const Vector2d& WorldObject::getPosition() const {
	return m_position;
}


/**
 * Returns the shape of the object, i.e., a representation of its spacial form and
 * size, for example a circular shape with a radius.
 */
const Shape& WorldObject::getShape() const {
	return *m_shape;
}


/**
 * Set the position of the object in the world, according to the object's centre.
 */
void WorldObject::setPosition(const Vector2d& pos) {
	m_position = pos;
}


/**
 * Notifies the object about that the time is being incremented with one time unit.
 */
void WorldObject::tick() {
	// do nothing by default
}


/**
 * Tells whether the world object is initialized or not, i.e., whether it is
 * placed in a world (=has a valid position).
 */
bool WorldObject::isInitialized() const {
	return m_initialized;
}


/**
 * Handles collision with a generic world object.
 * 
 * @param with
 */
void WorldObject::handleCollision(WorldObject* with){
}


/**
 * Sets the collision helper that the world object should use in order to detect
 * collisions.
 * 
 * @param ch
 */
void WorldObject::setCollisionHelper(CollisionHelper* ch) {
	m_collisionHelper = ch;
}
