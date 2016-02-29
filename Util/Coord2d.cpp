///////////////////////////////////////////////////////////
//  Coord2d.cpp
//  Implementation of the Class Coord2d
//  Created on:      28-mar-2008 10:25:06
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "Coord2d.h"
#include <math.h>


/**
 * Constructs a (0,0) coordinate.
 */
Coord2d::Coord2d():
m_x(0.0f),
m_y(0.0f)
{
}


/**
 * Constructs a new coordinate in 2D-space.
 */
Coord2d::Coord2d(float x, float y):
m_x(x),
m_y(y)
{
}


Coord2d::~Coord2d() {
}


/**
 * Returns the X coordinate.
 */
float Coord2d::getX() const {
	return m_x;
}


/**
 * Returns the Y coordinate.
 */
float Coord2d::getY() const {
	return m_y;
}


/**
 * Returns the sum of the two coordinates' x and y values in a new coordinate.
 * 
 * @param coord
 */
Coord2d Coord2d::operator+(const Coord2d& coord) const {
	Coord2d c(m_x + coord.m_x, m_y + coord.m_y);
	return c;
}


/**
 * Returns the difference of the two coordinates' x and y values in a new coordinate.
 * 
 * @param coord
 */
Coord2d Coord2d::operator-(const Coord2d& coord) const {
	return Coord2d(m_x - coord.m_x, m_y - coord.m_y);
}


/**
 * Divide by scalar.
 */
Coord2d Coord2d::operator/(float scalar) const {
	return Coord2d(m_x/scalar, m_y/scalar);
}


/**
 * Multiply vector by scalar.
 */
Coord2d Coord2d::operator*(const float& scalar) const {
	return Coord2d(scalar*m_x, scalar*m_y);
}


Coord2d Coord2d::operator-() const {
	return Coord2d(-(this->m_x), -(this->m_y));
}


Coord2d Coord2d::operator+(float scalar) const {
	return Coord2d(m_x + scalar, m_y + scalar);
}