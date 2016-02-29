///////////////////////////////////////////////////////////
//  LaserProjectile.h
//  Implementation of the Class LaserProjectile
//  Created on:      28-mar-2008 10:28:55
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_DAF8707F_A529_4c25_9A9B_F80777127DB8__INCLUDED_)
#define EA_DAF8707F_A529_4c25_9A9B_F80777127DB8__INCLUDED_

#include "Projectile.h"

/**
 * Representation of a laser projectile, which is not affected by gravities.
 */
class LaserProjectile : public Projectile
{

public:
	/**
	 * Constructs a laser projectile, deriving the movement direction from the
	 * supplied source movement.
	 * 
	 * @param sourceMovement
	 */
	LaserProjectile(const Vector2d& sourceMovement);
	virtual ~LaserProjectile();
	LaserProjectile(const LaserProjectile& projectile);

	LaserProjectile(const Vector2d&, float);
	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual LaserProjectile* clone() const;

	virtual unsigned int getMaxDamageStrength();

	virtual void tick();

private:
	/**
	 * Initial strength of a Lazer.
	 */
	static const float INIT_STRENGTH;

	/**
	 * The movement speed (i.e., the magnitude of the movement vector) at which the
	 * Lazer is set off, relative to the firing source.
	 */
	static const float SET_OFF_SPEED;

};
#endif // !defined(EA_DAF8707F_A529_4c25_9A9B_F80777127DB8__INCLUDED_)
