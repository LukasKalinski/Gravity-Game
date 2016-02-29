///////////////////////////////////////////////////////////
//  Coord2d.h
//  Implementation of the Class Coord2d
//  Created on:      28-mar-2008 10:25:03
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_A40B1DA3_7019_4d6a_8BF2_B1729040B419__INCLUDED_)
#define EA_A40B1DA3_7019_4d6a_8BF2_B1729040B419__INCLUDED_

#include <utility>


/**
 * Represents a coordinate in the absolute 2D-space.
 */
class Coord2d
{

public:

	/**
	 * Constructs a (0,0) coordinate.
	 */
	Coord2d();
	Coord2d(float x, float y);
	virtual ~Coord2d();

	float getX() const;
	float getY() const;

	/**
	 * Returns the sum of the two coordinates' x and y values in a new coordinate.
	 * 
	 * @param coord
	 */
	Coord2d operator+(const Coord2d& coord) const;

	/**
	 * Returns the difference of the two coordinates' x and y values in a new coordinate.
	 * 
	 * @param coord
	 */
	Coord2d operator-(const Coord2d& coord) const;

	/**
	 * Divide by scalar.
	 */
	Coord2d operator/(float scalar) const;
	
	/**
	 * Multiply vector by scalar.
	 */
	Coord2d operator*(const float& scalar) const;

	Coord2d operator-() const;
	Coord2d operator+(float scalar) const;

protected:

	/**
	 * The x coordinate.
	 */
	float m_x;

	/**
	 * The y coordinate.
	 */
	float m_y;

};
#endif // !defined(EA_A40B1DA3_7019_4d6a_8BF2_B1729040B419__INCLUDED_)
