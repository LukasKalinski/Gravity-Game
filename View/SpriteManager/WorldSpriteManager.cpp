///////////////////////////////////////////////////////////
//  WorldSpriteManager.cpp
//  Implementation of the Class WorldSpriteManager
//  Created on:      01-apr-2008 16:02:25
//  Original author: Jesper
///////////////////////////////////////////////////////////

#include "WorldSpriteManager.h"


WorldSpriteManager::WorldSpriteManager(const WorldObject* wo):
SpriteManager(wo->getPosition()),
m_worldObject(wo)
{
}


WorldSpriteManager::~WorldSpriteManager() {

	// Stop sending remove events to the sprite manager:
	if (m_eventManager && m_initialized) {
		m_eventManager->unregisterWorldObjectRemoveListener(this);
	}
}


WorldSpriteManager::WorldSpriteManager(const WorldSpriteManager& sm):
SpriteManager(sm),
m_worldObject(sm.m_worldObject)
{
	if (m_eventManager && m_initialized) {
		m_eventManager->registerWorldObjectRemoveListener(this);
	}
}


/**
 * Initializes the sprite manager.
 */
void WorldSpriteManager::init() {
	SpriteManager::init();
	m_eventManager->registerWorldObjectRemoveListener(this);
}


void WorldSpriteManager::update() {
	
	if (!m_initialized) {
		throw std::exception("WorldSpriteManager::update(): \
							 sprite manager not initialized");
	}

	// Make sure that we are valid:
	if (!m_valid) {
		throw std::exception("WorldSpriteManager::update(): \
							 cannot update invalid sprite manager");
	}

	// If the world object we're representing still exists, update
	// its sprites according to its new position:
	if (m_worldObject) {

		// Set sprite manager's reference point coordinate to the
		// world object's position:
		m_refPoint = m_worldObject->getPosition();

		sprites_t::iterator sprite_it = m_sprites.begin();

		// Update orientation of contained sprite(s):
		for ( ; sprite_it != m_sprites.end(); ++sprite_it) {
			sprite_it->setRotation(m_worldObject->getShape().getOrientation());
		}
	}
}


/**
 * Invalidates the sprite manager if the soon-removed world object is the same
 * that this class is pointing at.
 */
void WorldSpriteManager::notifyEvent(const WorldObjectRemoveEvent& ev) {
	if (m_worldObject == ev.getRemoved()) {
		m_worldObject = 0;
		m_valid = 0;
	}
}