///////////////////////////////////////////////////////////
//  WorldBackgroundSpriteManager.cpp
//  Implementation of the Class WorldBackgroundSpriteManager
//  Created on:      30-Apr-2008 17:20:04
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <math.h>

#include "WorldBackgroundSpriteManager.h"
#include "World.h"


/**
 * Constructs a sprite manager for the world background, having the world
 * specified.
 * 
 * @param world
 */
WorldBackgroundSpriteManager::WorldBackgroundSpriteManager(const World* world):
SpriteManager(Coord2d(0,0)),
m_world(world)
{
	// FIXME: take world ref instead, and fetch relevant data from it here
	//        (so we don't keep any pointers...)

	if (!world) {
		throw std::exception("WorldBackgroundSpriteManager::Constructor: \
							 world pointer must not be 0");
	}
}


WorldBackgroundSpriteManager::~WorldBackgroundSpriteManager() {
}


/**
 * Clones the world background sprite manager, returning a pointer to the clone.
 */
WorldBackgroundSpriteManager * WorldBackgroundSpriteManager::clone() const {
	return new WorldBackgroundSpriteManager(*this);
}


/**
 * Initializes the sprite manager.
 */
void WorldBackgroundSpriteManager::init() {

	const Coord2d & worldUpperLeft	= m_world->getUpperLeft();
	const Coord2d & worldLowerRight = m_world->getLowerRight();

	float worldWidth  = worldLowerRight.getX() - worldUpperLeft.getX();
	float worldHeight = worldLowerRight.getY() - worldUpperLeft.getY();

	// Set desirable tile dimensions:
	float tileWidth = 400.0;
	float tileHeight = 400.0;

	// # Adjust tile dimensions to world size.

	// Calc tile width:
	float wNumOfTiles = floor(worldWidth / tileWidth);
	float wGap = worldWidth - wNumOfTiles * tileWidth;
	tileWidth = tileWidth + (wGap / wNumOfTiles);

	// Calc tile height:
	float hNumOfTiles = floor(worldHeight / tileHeight);
	float hGap = worldHeight - hNumOfTiles * tileHeight;
	tileHeight = tileHeight + (hGap / hNumOfTiles);


	// # Create and add tile sprites.
	
	Coord2d pos = worldUpperLeft + Coord2d((tileWidth / 2), (tileHeight / 2));

	// Horizontal "painting":
	for ( ; pos.getX() < worldLowerRight.getX(); pos = pos + Coord2d(tileWidth, 0)) {
		
		// Vertical "painting":
		for ( ; pos.getY() < worldLowerRight.getY();
			pos = pos + Coord2d(0, tileHeight)) {
			Sprite tmpSprite = Sprite(Sprite::BACKGROUND_1, tileWidth, tileHeight);
			tmpSprite.setPosition(pos);
			addSprite(tmpSprite);
		}

		// Reset y axis pos:
		pos = Coord2d(pos.getX(), worldUpperLeft.getY() + (tileHeight / 2));
	}
}