///////////////////////////////////////////////////////////
//  LaserSpriteManager.cpp
//  Implementation of the Class LaserSpriteManager
//  Created on:      28-mar-2008 10:29:06
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "LaserSpriteManager.h"


LaserSpriteManager::LaserSpriteManager(const LaserProjectile* laser):
WorldSpriteManager(laser),
m_laser(laser)
{
}


LaserSpriteManager::~LaserSpriteManager() {
}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
LaserSpriteManager* LaserSpriteManager::clone() const {
	return new LaserSpriteManager(*this);
}


void LaserSpriteManager::init() {
	WorldSpriteManager::init();
	addSprite(Sprite(Sprite::LASER, m_worldObject->getShape()));
}