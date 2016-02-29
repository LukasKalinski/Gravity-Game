///////////////////////////////////////////////////////////
//  MissileProjectile.cpp
//  Implementation of the Class MissileProjectile
//  Created on:      28-mar-2008 10:30:33
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "MissileProjectile.h"


/**
 * Constructs a missile projectile, providing the movement of the source from
 * which the projectile originates.
 * 
 * @param sourceMovement
 */
MissileProjectile::MissileProjectile(const Vector2d& sourceMovement, float sourceAngle):
Projectile(CircularShape(10.0f), 30.0f),
DestroyableObject(INIT_STRENGTH)
{
	// Missile movement is set relative to the speed and direction of the ship:
	Vector2d firingDirection(SET_OFF_SPEED, sourceAngle);
	m_movement = firingDirection + sourceMovement;
	m_shape->setOrientation(sourceAngle);
}


MissileProjectile::~MissileProjectile() {

}

MissileProjectile::MissileProjectile(const MissileProjectile& projectile):
Projectile(projectile), DestroyableObject(projectile) {
}

/**
 * Clones the world object, returning a pointer to the clone.
 */
MissileProjectile* MissileProjectile::clone() const {
	return new MissileProjectile(*this);
}

/**
 * Returns the maximal damage strength of the projectile.
 */
unsigned int MissileProjectile::getMaxDamageStrength() {

	return 0;
}


/**
 * Updates the position and maintains orientation so that it follows the missile's
 * movement.
 */
void MissileProjectile::tick() {

	//Updates the position and maintains
	//orientation so that it follows the
	//missile's movement.

	m_position = m_position + m_movement;
}


/**
 * Initial strength of a missile.
 */
const float MissileProjectile::INIT_STRENGTH = 0.5f;


/**
 * The movement speed (i.e., the magnitude of the movement vector) at which the
 * missile is set off, relative to the firing source.
 */
const float MissileProjectile::SET_OFF_SPEED = 12.0f;