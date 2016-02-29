///////////////////////////////////////////////////////////
//  SpriteManagerFactory.h
//  Implementation of the Class SpriteManagerFactory
//  Created on:      28-Mar-2008 18:39:10
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_A2807933_202D_42d0_B39A_C5BF3887CF5F__INCLUDED_)
#define EA_A2807933_202D_42d0_B39A_C5BF3887CF5F__INCLUDED_

// Include visual elements:
#include "Ship.h"
#include "Asteroid.h"
#include "MissileProjectile.h"
#include "LaserProjectile.h"
#include "SpawnPoint.h"
#include "Planet.h"
#include "FuelItem.h"
#include "MissileItem.h"
#include "MenuButton.h"

// Include sprite managers:
#include "ShipSpriteManager.h"
#include "AsteroidSpriteManager.h"
#include "MissileSpriteManager.h"
#include "LaserSpriteManager.h"
#include "SpawnPointSpriteManager.h"
#include "PlanetSpriteManager.h"
#include "FuelItemSpriteManager.h"
#include "MissileItemSpriteManager.h"
#include "MenuButtonSpriteManager.h"

/**
 * Responsible for creating sprite managers, being provided a valid visual element
 * (ships, menu buttons, planets, etc).
 */
class SpriteManagerFactory
{

public:

	static WorldSpriteManager* create(const WorldObject* wo);

	static ShipSpriteManager* create(const Ship* ship);
	static AsteroidSpriteManager* create(const Asteroid* asteroid);
	static MissileSpriteManager* create(const MissileProjectile* missile);
	static LaserSpriteManager* create(const LaserProjectile* laser);
	static SpawnPointSpriteManager* create(const SpawnPoint* spawnPoint);
	static PlanetSpriteManager* create(const Planet* planet);
	static FuelItemSpriteManager* create(const FuelItem* item);
	static MissileItemSpriteManager* create(const MissileItem* item);
	static MenuButtonSpriteManager* create(const MenuButton* menuButton);

private:

	SpriteManagerFactory();
};
#endif // !defined(EA_A2807933_202D_42d0_B39A_C5BF3887CF5F__INCLUDED_)
