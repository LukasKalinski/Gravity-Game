///////////////////////////////////////////////////////////
//  CircularShape.cpp
//  Implementation of the Class CircularShape
//  Created on:      28-mar-2008 10:24:07
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "CircularShape.h"


/**
 * Constructs a circular shape, defining its radius and
 * setting its orientation to 0.
 */
CircularShape::CircularShape(float radius):
Shape(0),
m_radius(radius)
{
}


/**
 * Constructs a circular shape, defining its orientation and radius.
 */
CircularShape::CircularShape(float orientation, float radius):
Shape(orientation),
m_radius(radius)
{
}


CircularShape::~CircularShape() {
}


CircularShape::CircularShape(const CircularShape& shape):
Shape(shape),
m_radius(shape.m_radius)
{
}


/**
 * Clones the circular shape, returning a pointer to the created clone.
 */
CircularShape* CircularShape::clone() const {
	return new CircularShape(*this);
}


/**
 * Returns the radius of the circular shape.
 */
float CircularShape::getRadius() const {
	return m_radius;
}
