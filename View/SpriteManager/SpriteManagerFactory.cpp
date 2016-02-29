///////////////////////////////////////////////////////////
//  SpriteManagerFactory.cpp
//  Implementation of the Class SpriteManagerFactory
//  Created on:      28-Mar-2008 18:39:11
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <exception>

#include "SpriteManagerFactory.h"


SpriteManagerFactory::SpriteManagerFactory() {
	throw std::exception("cannot be instantiated");
}


/**
 * Uses RTTI to determine what sprite manager to create for a world object.
 */
WorldSpriteManager* SpriteManagerFactory::create(const WorldObject* wo) {

	if (const Asteroid * asteroid = dynamic_cast<const Asteroid *>(wo)) {
		return create(asteroid);
	} else if (const FuelItem * item = dynamic_cast<const FuelItem*>(wo)) {
		return create(item);
	} else if (const LaserProjectile * laser = dynamic_cast<const LaserProjectile*>(wo)) {
		return create(laser);
	} else if (const MissileItem * item = dynamic_cast<const MissileItem*>(wo)) {
		return create(item);
	} else if (const MissileProjectile * missile = dynamic_cast<const MissileProjectile*>(wo)) {
		return create(missile);
	} else if (const Planet * planet = dynamic_cast<const Planet*>(wo)) {
		return create(planet);
	} else if (const Ship * ship = dynamic_cast<const Ship *>(wo)) {
		return create(ship);
	} else if (const SpawnPoint * sp = dynamic_cast<const SpawnPoint*>(wo)) {
		return create(sp);
	} else {
		throw std::exception("unsupported world object");
	}
}


/**
 * Creates a sprite manager for a ship.
 */
ShipSpriteManager* SpriteManagerFactory::create(const Ship* ship) {
	return new ShipSpriteManager(ship);
}


/**
 * Creates a sprite manager for an asteroid.
 */
AsteroidSpriteManager* SpriteManagerFactory::create(const Asteroid* asteroid) {
	return new AsteroidSpriteManager(asteroid);
}


/**
 * Creates a sprite manager for a missile projectile.
 */
MissileSpriteManager* SpriteManagerFactory::create(const MissileProjectile* missile) {
	return new MissileSpriteManager(missile);
}


/**
 * Creates a sprite manager for a laser projectile.
 */
LaserSpriteManager* SpriteManagerFactory::create(const LaserProjectile* laser) {
	return new LaserSpriteManager(laser);
}


/**
 * Creates a sprite manager for a spawn point.
 */
SpawnPointSpriteManager* SpriteManagerFactory::create(const SpawnPoint* spawnPoint) {
	return new SpawnPointSpriteManager(spawnPoint);
}


/**
 * Creates a sprite manager for a planet.
 */
PlanetSpriteManager* SpriteManagerFactory::create(const Planet* planet) {
	return new PlanetSpriteManager(planet);
}


/**
 * Creates a sprite manager for a fuel item.
 */
FuelItemSpriteManager* SpriteManagerFactory::create(const FuelItem* item) {
	return new FuelItemSpriteManager(item);
}


/**
 * Creates a sprite manager for a missile item.
 */
MissileItemSpriteManager* SpriteManagerFactory::create(const MissileItem* item) {
	return new MissileItemSpriteManager(item);
}


/**
 * Creates a sprite manager for a menu button.
 */
MenuButtonSpriteManager* SpriteManagerFactory::create(const MenuButton* menuButton) {
	return new MenuButtonSpriteManager(menuButton->getName());
}