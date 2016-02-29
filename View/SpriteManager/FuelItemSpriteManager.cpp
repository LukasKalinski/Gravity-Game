///////////////////////////////////////////////////////////
//  FuelItemSpriteManager.cpp
//  Implementation of the Class FuelItemSpriteManager
//  Created on:      28-mar-2008 10:26:22
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "FuelItemSpriteManager.h"


FuelItemSpriteManager::FuelItemSpriteManager(const FuelItem* fuelItem):
WorldSpriteManager(fuelItem)
{
}


FuelItemSpriteManager::~FuelItemSpriteManager() {
}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
FuelItemSpriteManager* FuelItemSpriteManager::clone() const {
	return new FuelItemSpriteManager(*this);
}

void FuelItemSpriteManager::init() {
	WorldSpriteManager::init();
	addSprite(Sprite(Sprite::FUEL_ITEM, m_worldObject->getShape()));
}