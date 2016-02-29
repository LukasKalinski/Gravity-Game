///////////////////////////////////////////////////////////
//  SpriteManager.cpp
//  Implementation of the Class SpriteManager
//  Created on:      28-Mar-2008 18:36:14
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "SpriteManager.h"


/**
 * Constructs a sprite manager, specifying the reference point coordinate to use.
 * 
 * @param refPoint
 */
SpriteManager::SpriteManager(const Vector2d& refPoint):
m_refPoint(refPoint),
m_eventManager(0),
m_valid(true),
m_initialized(false)
{
}


SpriteManager::~SpriteManager() {
	clearSprites();
}


SpriteManager::SpriteManager(const SpriteManager& sm):
m_refPoint(sm.m_refPoint),
m_eventManager(sm.m_eventManager),
m_valid(sm.m_valid),
m_initialized(sm.m_initialized),
m_sprites(sm.m_sprites)
{
}


/**
 * Does common initialization checks (should be called by children!).
 */
void SpriteManager::init() {
	
	if (m_initialized) {
		throw std::exception("WorldSpriteManager::init(): \
							 already initialized");
	}

	if (m_eventManager == 0) {
		throw std::exception("SpriteManager::init(): \
							 event manager must be present");
	}

	m_initialized = true;
}


/**
 * Tells whether the sprite manager is valid or not (i.e., whether it should be
 * used or removed).
 */
bool SpriteManager::isValid() const  {
	return m_valid;
}

/**
 * Updates the sprite manager.
 */
void SpriteManager::update() {
	// do nothing currently
}


/**
 * Set the game event manager to use within the sprite manager.
 */
void SpriteManager::setEventManager(GameEventManager* eventManager) {

	if (eventManager == 0) {
		throw std::exception("SpriteManager::setEventManager(): \
							 event manager must not be 0");
	}

	m_eventManager = eventManager;
}


/**
 * Returns the coordinate in relation to which all sprites in the contained sprite
 * contexts are to be drawn. (Hint: move coordinate system to this coordinate
 * before drawing.)
 */
const Vector2d& SpriteManager::getReferencePoint() const {
	return m_refPoint;
}


void SpriteManager::setReferencePoint(const Vector2d& refPoint) {
	m_refPoint = refPoint;
}


/**
 * Adds a sprite, making it available for drawing.
 * 
 * @param sprite
 */
void SpriteManager::addSprite(const Sprite& sprite) {
	m_sprites.push_back(sprite);
}


/**
 * Returns a vector of the sprites that are available for drawing.
 */
const SpriteManager::sprites_t& SpriteManager::getSprites() const {
	return m_sprites;
}


/**
 * Clears sprites that are currently visible.
 */
void SpriteManager::clearSprites() {
	m_sprites.clear();
}