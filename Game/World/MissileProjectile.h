///////////////////////////////////////////////////////////
//  MissileProjectile.h
//  Implementation of the Class MissileProjectile
//  Created on:      28-mar-2008 10:30:29
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_04486AC9_C54E_46c2_8681_8E5A9E412F0C__INCLUDED_)
#define EA_04486AC9_C54E_46c2_8681_8E5A9E412F0C__INCLUDED_

#include "DestroyableObject.h"
#include "Projectile.h"

/**
 * Representation of a gravity-affectable missile projectile.
 */
class MissileProjectile : public DestroyableObject, public Projectile
{

public:

	/**
	 * Constructs a missile projectile, providing the movement of the source from
	 * which the projectile originates.
	 * 
	 * @param sourceMovement
	 */
	MissileProjectile(const Vector2d& sourceMovement, float sourceAngle);
	virtual ~MissileProjectile();
	MissileProjectile(const MissileProjectile& projectile);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual MissileProjectile* clone() const;

	virtual unsigned int getMaxDamageStrength();
	virtual void tick();

private:
	/**
	 * Initial strength of a missile.
	 */
	static const float INIT_STRENGTH;

	/**
	 * The movement speed (i.e., the magnitude of the movement vector) at which the
	 * missile is set off, relative to the firing source.
	 */
	static const float SET_OFF_SPEED;

};
#endif // !defined(EA_04486AC9_C54E_46c2_8681_8E5A9E412F0C__INCLUDED_)
