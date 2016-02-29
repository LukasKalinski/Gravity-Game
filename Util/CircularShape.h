///////////////////////////////////////////////////////////
//  CircularShape.h
//  Implementation of the Class CircularShape
//  Created on:      28-mar-2008 10:24:04
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_865B2C4E_197E_4b3d_BAE9_B84747CF49B7__INCLUDED_)
#define EA_865B2C4E_197E_4b3d_BAE9_B84747CF49B7__INCLUDED_

#include "Shape.h"

/**
 * A circular shape.
 */
class CircularShape : public Shape
{

public:

	CircularShape(float radius);
	CircularShape(float orientation, float radius);
	virtual ~CircularShape();
	CircularShape(const CircularShape& shape);

	/**
	 * Clones the circular shape, returning a pointer to the created clone.
	 */
	virtual CircularShape* clone() const;

	float getRadius() const;

private:
	/**
	 * The radius of the circular shape.
	 */
	float m_radius;

};
#endif // !defined(EA_865B2C4E_197E_4b3d_BAE9_B84747CF49B7__INCLUDED_)
