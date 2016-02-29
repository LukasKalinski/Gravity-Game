///////////////////////////////////////////////////////////
//  AsteroidSpriteManager.cpp
//  Implementation of the Class AsteroidSpriteManager
//  Created on:      28-mar-2008 10:23:42
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "AsteroidSpriteManager.h"


AsteroidSpriteManager::AsteroidSpriteManager(const Asteroid* asteroid):
WorldSpriteManager(asteroid),
m_animationSprite(0)
{
}


AsteroidSpriteManager::~AsteroidSpriteManager() {
	if (m_animationSprite) {
		delete m_animationSprite;
	}

	if (m_initialized) {
		// Stop listening for destructions:
		m_eventManager->unregisterWorldObjectDestructionListener(this);
	}
}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
AsteroidSpriteManager* AsteroidSpriteManager::clone() const {
	return new AsteroidSpriteManager(*this);
}


void AsteroidSpriteManager::init() {
	WorldSpriteManager::init();

	// Start listening for destructions:
	m_eventManager->registerWorldObjectDestructionListener(this);

	m_animationSprite = new AnimationSprite(
		m_worldObject->getShape(),
		AnimationSprite::ASTEROID_INSERT,
		3, 0);
	m_animationSprite->setRotation(m_worldObject->getShape().getOrientation());
	m_animationSprite->play();
	addSprite(*m_animationSprite);
}


/**
 * Updates the sprites of the asteroid sprite manager.
 */
void AsteroidSpriteManager::update() {

	if (m_animationSprite) {
		clearSprites();

		if (m_animationSprite->getAnimation() == AnimationSprite::ASTEROID_INSERT) {
			if (m_animationSprite->isFinished()) {
				addSprite(Sprite(Sprite::ASTEROID, m_worldObject->getShape()));
				delete m_animationSprite;
				m_animationSprite = 0;
			} else {
				addSprite(*m_animationSprite);
			}
		} else if (m_animationSprite->getAnimation() == AnimationSprite::ASTEROID_DESTROY) {
			if (m_animationSprite->isFinished()) {
				delete m_animationSprite;
				m_animationSprite = 0;
				m_valid = false;
			} else {
				addSprite(*m_animationSprite);
			}
		}
	}

	if (m_valid) {
		WorldSpriteManager::update();
	}
}


/**
 * Notifies the asteroid sprite manager about an occuring destruction. 
 * Checks whether the world object being destroyed is the asteroid 
 * monitored by this sprite manager and plays an asteroid destruction
 * animation if that is the case. After the animation is played
 * the sprite manager becomes invalid.
 */
void AsteroidSpriteManager::notifyEvent(const WorldObjectDestructionEvent& ev) {

	if (const WorldObject * destroyed =
		dynamic_cast<const WorldObject *>(ev.getDestroyed())) {

		// Handle asteroid destruction if this sprite manager's
		// asteroid is destroyed:
		if (m_worldObject == destroyed) {

			// Remove animation if any is present:
			if (m_animationSprite) {
				delete m_animationSprite;
				m_animationSprite = 0;
			}

			clearSprites();

			// Start destruction animation:
			m_animationSprite = new AnimationSprite(
				m_worldObject->getShape(),
				AnimationSprite::ASTEROID_DESTROY,
				3, 0);
			m_animationSprite->play();
			
			addSprite(*m_animationSprite);

			// Get rid of pointer to asteroid:
			m_worldObject = 0;
		}
	} else {
		throw std::exception("AsteroidSpriteManager::notifyEvent(destruction): \
							 destroyable object was not a world object");
	}
}