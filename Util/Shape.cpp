///////////////////////////////////////////////////////////
//  Shape.cpp
//  Implementation of the Class Shape
//  Created on:      28-mar-2008 10:33:06
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "Shape.h"


/**
 * Constructs a shape.
 * 
 * @param orientation
 */
Shape::Shape(float orientation):
m_orientation(orientation)
{
}


Shape::~Shape() {
}


Shape::Shape(const Shape& shape):
m_orientation(shape.m_orientation)
{
}


/**
 * Sets the shape's orientation according to the unit circle.
 * 
 * @param orientation
 */
void Shape::setOrientation(float orientation) {
	m_orientation = orientation;
}


/**
 * Returns the angle of orientation, according to the unit circle.
 */
float Shape::getOrientation() const {
	return m_orientation;
}