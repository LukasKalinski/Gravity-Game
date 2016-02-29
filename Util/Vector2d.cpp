///////////////////////////////////////////////////////////
//  Vector2d.cpp
//  Implementation of the Class Vector2d
//  Created on:      28-mar-2008 10:35:47
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "Vector2d.h"

#include <math.h>
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif


/**
 * Constructs a vector of length 0, angle 0, and x and y 0.
 */
Vector2d::Vector2d()
{
	define(0, 0);
}


/**
 * Constructs a 2D vector of a certain length and a certain angle.
 */
Vector2d::Vector2d(float length, float angle)
{
	define(length, angle);
}


Vector2d::~Vector2d() {
}


Vector2d::Vector2d(const Coord2d& c)
{
	define(c);
}


/**
 * Defines the vector from a length and an angle.
 */
void Vector2d::define(float length, float angle) {
	m_length = length;
	m_angle = angle;
	m_x = cos(angle) * length;
	m_y = sin(angle) * length;
}


/**
 * Defines the vector from a coordinate.
 */
void Vector2d::define(const Coord2d& c) {
	m_length = sqrt(c.getX()*c.getX() + c.getY()*c.getY());
	m_angle = atan2(c.getY(), c.getX());
	m_x = c.getX();
	m_y = c.getY();
}


/**
 * Returns the angle of the vector.
 */
float Vector2d::getAngle() const {
	return m_angle;
}


/**
 * Returns the length of the vector.
 */
float Vector2d::getLength() const {
	return m_length;
}


/**
 * Returns the scalar product of two vectors.
 */
float Vector2d::scalar(const Vector2d& v) const {
	return m_x * v.m_x + m_y * v.m_y;
}


///**
// * Project this vector on vector v returning the pair
// * where first contains the composant projected on v (is parallel to v) and
// * second is the composant projected on v's normal vector.
// */
//std::pair<Vector2d, Vector2d> Vector2d::project(const Vector2d& v) const {
//
//	Vector2d projected(m_length * cos(m_angle), v.m_angle);
//
//	Vector2d vpar, vnorm;	// Parallel to v and 90 degrees to v.
//	Vector2d ev;			// Like v but length of 1.
//	
//	ev = v / v.getLength();
//	vpar = ev * (this->scalar(ev));
//	vnorm = v - vpar;
//
//	return std::make_pair<Vector2d, Vector2d> (vpar, vnorm); 
//}


/**
 * Divide length by a scalar.
 */
Vector2d Vector2d::operator/(float scalar) const {
	return Vector2d(m_length / scalar, m_angle);
}


/**
 * Multiply length by a factor.
 */
Vector2d Vector2d::operator*(float factor) const {
	return Vector2d(m_length * factor, m_angle);
}


/**
 * Add two vectors and return the resulting one.
 */
Vector2d Vector2d::operator+(const Vector2d& v) const {
	return Vector2d(Coord2d(m_x + v.m_x, m_y + v.m_y));
}


/**
 * Returns the difference of the two coordinates' x and y values in a new coordinate.
 * 
 * @param v
 */
Vector2d Vector2d::operator-(const Vector2d& v) const {
	return Vector2d(Coord2d(m_x - v.m_x, m_y - v.m_y));
}


/**
 * Returns the vector inverted.
 */
Vector2d Vector2d::operator -() const {
	float angle = m_angle + static_cast<float>(M_PI);
	return Vector2d(m_length, angle);
}