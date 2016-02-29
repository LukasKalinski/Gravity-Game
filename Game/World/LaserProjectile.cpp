///////////////////////////////////////////////////////////
//  LaserProjectile.cpp
//  Implementation of the Class LaserProjectile
//  Created on:      28-mar-2008 10:28:59
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "LaserProjectile.h"


LaserProjectile::LaserProjectile(const Vector2d& sourceMovement):
Projectile(CircularShape(7.0f), 0.0f){
	printf("LaserProjectile::LaserProjectile\n");
}


/**
 * Constructs a laser projectile, deriving the movement direction from the
 * supplied source movement.
 * 
 * @param sourceMovement
 */
LaserProjectile::LaserProjectile(const Vector2d& sourceMovement, float sourceAngle):
Projectile(CircularShape(7.0f), 0.0f){

	// Missile movement is set relative to the speed and direction of the ship:
	Vector2d firingDirection(SET_OFF_SPEED, sourceAngle);
	m_movement = firingDirection + sourceMovement;
	m_shape->setOrientation(sourceAngle);

}


LaserProjectile::~LaserProjectile() {

}


LaserProjectile::LaserProjectile(const LaserProjectile& projectile):
Projectile(projectile){
}


/**
 * Clones the world object, returning a pointer to the clone.
 */
LaserProjectile* LaserProjectile::clone() const {
	return new LaserProjectile(*this);
}

void LaserProjectile::tick() {

	//Updates the position and maintains
	//orientation so that it follows the
	//missile's movement.

	m_position = m_position + m_movement;

	// Check if we're colliding and handle the collision if that's the case:
	std::vector<WorldObject*> obstacles;
	m_collisionHelper->probeCollisions(this, obstacles);
	if (obstacles.size() > 0) {
		std::vector<WorldObject*>::iterator obstacle_it = obstacles.begin();
		for ( ; obstacle_it != obstacles.end(); ++obstacle_it) {
			float intersectionDistance = m_shape->getRadius() +
				(*obstacle_it)->getShape().getRadius();
			
		}
	}
}

/**
 * Returns the maximal damage strength of the laser.
 */
unsigned int LaserProjectile::getMaxDamageStrength() {

	return 0;
}

/**
 * Initial strength of a missile.
 */
const float LaserProjectile::INIT_STRENGTH = 0.5f;


/**
 * The movement speed (i.e., the magnitude of the movement vector) at which the
 * missile is set off, relative to the firing source.
 */
const float LaserProjectile::SET_OFF_SPEED = 20.0f;