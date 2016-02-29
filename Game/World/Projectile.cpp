///////////////////////////////////////////////////////////
//  Projectile.cpp
//  Implementation of the Class Projectile
//  Created on:      28-mar-2008 10:32:28
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "Projectile.h"


/**
 * Constructs a projectile.
 */
Projectile::Projectile(const Shape& shape):
MovableObject(0.0, shape)
{
}


/**
 * Constructs a projectile, specifying its mass.
 */
Projectile::Projectile(const Shape& shape, float mass):
MovableObject(mass, shape)
{
}

Projectile::~Projectile() {
}


Projectile::Projectile(const Projectile& projectile):
MovableObject(projectile) {
}
