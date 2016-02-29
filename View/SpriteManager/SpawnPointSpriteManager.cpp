///////////////////////////////////////////////////////////
//  SpawnPointSpriteManager.cpp
//  Implementation of the Class SpawnPointSpriteManager
//  Created on:      28-mar-2008 10:34:40
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "SpawnPointSpriteManager.h"



SpawnPointSpriteManager::SpawnPointSpriteManager(const SpawnPoint* spawnPoint):
WorldSpriteManager(spawnPoint),
m_spawnPoint(spawnPoint),
m_currentSprite(Sprite(Sprite::SPAWN_POINT_FREE, spawnPoint->getShape()))
{
}


SpawnPointSpriteManager::~SpawnPointSpriteManager() {

}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
SpawnPointSpriteManager* SpawnPointSpriteManager::clone() const {
	return new SpawnPointSpriteManager(*this);
}


/**
 * Initializes the sprite manager.
 */
void SpawnPointSpriteManager::init() {
	WorldSpriteManager::init();
	addSprite(m_currentSprite);
}


void SpawnPointSpriteManager::update() {

	if (m_spawnPoint->isFree() && m_currentSprite.getImage() == Sprite::SPAWN_POINT_OCCUPIED) {
		m_currentSprite = Sprite(Sprite::SPAWN_POINT_FREE, m_spawnPoint->getShape());
		clearSprites();
		addSprite(m_currentSprite);
	} else if (!m_spawnPoint->isFree() && m_currentSprite.getImage() == Sprite::SPAWN_POINT_FREE) {
		clearSprites();
		m_currentSprite = Sprite(Sprite::SPAWN_POINT_OCCUPIED, m_spawnPoint->getShape());
		addSprite(m_currentSprite);
	}

	WorldSpriteManager::update();
}