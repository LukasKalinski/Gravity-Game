///////////////////////////////////////////////////////////
//  Vector2d.h
//  Implementation of the Class Vector2d
//  Created on:      28-mar-2008 10:35:43
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_3348F9DD_E8B0_48a6_97DD_75113B52E93C__INCLUDED_)
#define EA_3348F9DD_E8B0_48a6_97DD_75113B52E93C__INCLUDED_

#include "Coord2d.h"

/**
 * Defines a vector in 2D space by combining a coordinate and a length.
 */
class Vector2d : public Coord2d
{

public:

	Vector2d();
	Vector2d(float length, float angle);
	Vector2d(const Coord2d& c);
	virtual ~Vector2d();

	float getAngle() const;
	float getLength() const;

	/**
	 * Returns the scalar product of two vectors.
	 */
	float scalar(const Vector2d& v) const;

	///**
	// * Project this vector on vector v returning the pair
	// * where first contains the composant projected on v (is parallel to v) and
	// * second is the composant projected on v's normal vector.
	// */
	//std::pair<Vector2d, Vector2d> project(const Vector2d& v) const;

	/**
	 * Multiply magnitude by factor and return the resulting vector.
	 */
	Vector2d operator*(float factor) const;

	/**
	 * Divides the vector's coordinate by a scalar and returns
	 * the resulting one.
	 */
	Vector2d operator/(float scalar) const;

	/**
	 * Add two vectors and return the resulting one.
	 */
	Vector2d operator+(const Vector2d& v) const;

	/**
	 * Returns the difference of the two coordinates' x and y values in a new coordinate.
	 * 
	 * @param coord
	 */
	Vector2d operator-(const Vector2d& coord) const;

	Vector2d operator-() const;

private:

	/**
	 * The angle of the vector.
	 */
	float m_angle;

	/**
	 * The magnitude/length of the vector.
	 */
	float m_length;

	/**
	 * Defines the vector's from a length and an angle.
	 */
	void define(float length, float angle);

	/**
	 * Defines the vector's from a coordinate.
	 */
	void define(const Coord2d& c);

};
#endif // !defined(EA_3348F9DD_E8B0_48a6_97DD_75113B52E93C__INCLUDED_)
