///////////////////////////////////////////////////////////
//  MissileItemSpriteManager.cpp
//  Implementation of the Class MissileItemSpriteManager
//  Created on:      28-Mar-2008 17:38:26
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "MissileItemSpriteManager.h"


MissileItemSpriteManager::MissileItemSpriteManager(const MissileItem* missileItem):
WorldSpriteManager(missileItem)
{
}


MissileItemSpriteManager::~MissileItemSpriteManager() {
}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
MissileItemSpriteManager* MissileItemSpriteManager::clone() const {
	return new MissileItemSpriteManager(*this);
}


void MissileItemSpriteManager::init() {
	WorldSpriteManager::init();
	addSprite(Sprite(Sprite::MISSILE_ITEM, m_worldObject->getShape()));
}