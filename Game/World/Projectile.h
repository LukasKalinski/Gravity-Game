///////////////////////////////////////////////////////////
//  Projectile.h
//  Implementation of the Class Projectile
//  Created on:      28-mar-2008 10:32:24
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_A3292D64_A66C_4bc1_B3D7_FC2BE54B4B3B__INCLUDED_)
#define EA_A3292D64_A66C_4bc1_B3D7_FC2BE54B4B3B__INCLUDED_

#include "MovableObject.h"
#include "CircularShape.h"

/**
 * Contains common behavior and properties of weapon projectiles fired by a ship.
 */
class Projectile : public MovableObject
{

public:

	/**
	 * Constructs a projectile, specifying its shape.
	 */
	Projectile(const Shape& shape);

	/**
	 * Constructs a projectile, specifying its shape and mass.
	 */
	Projectile(const Shape& shape, float mass);

	virtual ~Projectile();
	Projectile(const Projectile& projectile);

	/**
	 * Clones the projectile, returning a pointer to the clone.
	 */
	virtual Projectile* clone() const = 0;

	/**
	 * Returns the maximal damage strength of the projectile.
	 */
	virtual unsigned int getMaxDamageStrength() = 0;

};
#endif // !defined(EA_A3292D64_A66C_4bc1_B3D7_FC2BE54B4B3B__INCLUDED_)
