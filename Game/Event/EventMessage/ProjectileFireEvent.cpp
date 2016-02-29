///////////////////////////////////////////////////////////
//  ProjectileFireEvent.cpp
//  Implementation of the Class ProjectileFireEvent
//  Created on:      16-Apr-2008 23:56:59
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ProjectileFireEvent.h"


/**
 * Constructs a projectile fire event, specifying the projectile as well as the
 * ship that fired it.
 * 
 * @param ship
 * @param projectile
 */
ProjectileFireEvent::ProjectileFireEvent(
	const Ship* ship, const Projectile* projectile):
m_ship(ship),
m_projectile(projectile)
{
}


ProjectileFireEvent::~ProjectileFireEvent() {
}


/**
 * Returns a pointer to the projectile that was fired.
 */
const Projectile* ProjectileFireEvent::getProjectile() const {
	return m_projectile;
}


/**
 * Returns a pointer to the ship that fired the projectile.
 */
const Ship* ProjectileFireEvent::getShip() const {
	return m_ship;
}