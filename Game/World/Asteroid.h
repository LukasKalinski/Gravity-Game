///////////////////////////////////////////////////////////
//  Asteroid.h
//  Implementation of the Class Asteroid
//  Created on:      28-mar-2008 10:23:31
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_87239E29_1812_4857_8959_B00078FE1946__INCLUDED_)
#define EA_87239E29_1812_4857_8959_B00078FE1946__INCLUDED_

#include "MovableObject.h"
#include "DestroyableObject.h"

/**
 * Representation of an asteroid flying around randomly in the game world.
 */
class Asteroid : public MovableObject, public DestroyableObject
{

public:
	Asteroid(float rotationSpeed, float mass);
	Asteroid(float rotationSpeed, float mass, const Shape& shape);
	virtual ~Asteroid();
	Asteroid(const Asteroid& asteroid);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual Asteroid* clone() const;

	virtual void tick();

private:
	/**
	 * Initial strength of an asteroid.
	 */
	static const float INIT_STRENGTH;

	/**
	 * The speed at which the asteroid rotates. If positive, it rotates clockwise, if
	 * negative, it rotates counter-clockwise.
	 */
	float m_rotationSpeed;

};
#endif // !defined(EA_87239E29_1812_4857_8959_B00078FE1946__INCLUDED_)
