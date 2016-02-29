///////////////////////////////////////////////////////////
//  MissileSpriteManager.cpp
//  Implementation of the Class MissileSpriteManager
//  Created on:      28-mar-2008 10:30:40
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "MissileSpriteManager.h"


MissileSpriteManager::MissileSpriteManager(const MissileProjectile* missile):
WorldSpriteManager(missile) {
}


MissileSpriteManager::~MissileSpriteManager() {

}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
MissileSpriteManager* MissileSpriteManager::clone() const {
	return new MissileSpriteManager(*this);
}


void MissileSpriteManager::init() {
	WorldSpriteManager::init();
	addSprite(Sprite(Sprite::MISSILE, m_worldObject->getShape()));
}