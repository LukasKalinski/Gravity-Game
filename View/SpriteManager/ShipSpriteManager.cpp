///////////////////////////////////////////////////////////
//  ShipSpriteManager.cpp
//  Implementation of the Class ShipSpriteManager
//  Created on:      28-Mar-2008 17:26:51
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////


#include "ShipSpriteManager.h"


ShipSpriteManager::ship_color_sprites_t ShipSpriteManager::m_shipColorSprites;


ShipSpriteManager::ShipSpriteManager(const Ship* ship):
WorldSpriteManager(ship),
m_animationSprite(0),
m_shipColor(ship->getColor()),
m_isThrottling(false)
{
	if (m_shipColorSprites.empty()) {

		m_shipColorSprites[Ship::BLUE][SHIP] = Sprite::SHIP_BLUE;
		m_shipColorSprites[Ship::BLUE][SHIP_THROTTLE_F1] = Sprite::SHIP_BLUE_THROTTLE_F1;
		m_shipColorSprites[Ship::BLUE][SHIP_THROTTLE_F2] = Sprite::SHIP_BLUE_THROTTLE_F2;
		m_shipColorSprites[Ship::BLUE][SHIP_THROTTLE_F3] = Sprite::SHIP_BLUE_THROTTLE_F3;

		m_shipColorSprites[Ship::RED][SHIP] = Sprite::SHIP_RED;
		m_shipColorSprites[Ship::RED][SHIP_THROTTLE_F1] = Sprite::SHIP_RED_THROTTLE_F1;
		m_shipColorSprites[Ship::RED][SHIP_THROTTLE_F2] = Sprite::SHIP_RED_THROTTLE_F2;
		m_shipColorSprites[Ship::RED][SHIP_THROTTLE_F3] = Sprite::SHIP_RED_THROTTLE_F3;
	}
}


ShipSpriteManager::~ShipSpriteManager() {

	// Stop sending destruction events to the sprite manager:
	if (m_initialized) {
		m_eventManager->unregisterWorldObjectDestructionListener(this);
	}

	if (m_animationSprite) {
		delete m_animationSprite;
	}
}


ShipSpriteManager::ShipSpriteManager(const ShipSpriteManager& sm):
WorldSpriteManager(sm),
m_animationSprite(sm.m_animationSprite->clone()),
m_isThrottling(sm.m_isThrottling)
{
	if (m_eventManager && m_initialized) {
		m_eventManager->registerWorldObjectDestructionListener(this);
	}
}


/**
 * Initializes the sprite manager.
 */
void ShipSpriteManager::init() {
	WorldSpriteManager::init();
	m_eventManager->registerWorldObjectDestructionListener(this);

	addSprite(Sprite(getSpriteImage(SHIP), m_worldObject->getShape()));
}


/**
 * Notifies the ship sprite manager about an occuring destruction. 
 * Checks whether the world object being destroyed is the ship 
 * monitored by this sprite manager and plays a ship destruction
 * animation if that is the case. After the animation is played
 * the sprite manager becomes invalid.
 */
void ShipSpriteManager::notifyEvent(const WorldObjectDestructionEvent& ev) {

	if (const WorldObject * destroyed =
		dynamic_cast<const WorldObject *>(ev.getDestroyed())) {

		// Handle ship destruction if this sprite manager's ship is destroyed:
		if (m_worldObject == destroyed) {

			startShipDestructionAnim();
		
			// Get rid of pointer to ship:
			m_worldObject = 0;
		}
	} else {
		throw std::exception("ShipSpriteManager::notifyEvent(destruction): \
							 destroyable object was not a world object");
	}
}


/**
 * Overrides and therefore neutralizes default behavior of this function,
 * as defined by WorldSpriteManager.
 */
void ShipSpriteManager::notifyEvent(const WorldObjectRemoveEvent& ev) {
	// ignore removal as we've catched the destruction event.
	// this function 
}


/**
 * Checks animation sprite (if any) and falls back to a non-animation
 * sprite if the animation is finished or should not longer be played.
 * If the animation is a destruction animation, then when it is finished,
 * the ship sprite manager becomes invalid.
 */
void ShipSpriteManager::update() {

	if (m_worldObject) {
		if (const Ship * ship = dynamic_cast<const Ship*>(m_worldObject)) {

			// If the ship started throttling, change sprite:
			if (ship->isThrottling() && !m_isThrottling) {
				clearSprites();
				addSprite(Sprite(getSpriteImage(SHIP_THROTTLE_F1), ship->getShape()));
				m_isThrottling = true;
			// If the ship stopped throttling, change sprite:
			} else if (!ship->isThrottling() && m_isThrottling) {
				clearSprites();
				addSprite(Sprite(getSpriteImage(SHIP), ship->getShape()));
				m_isThrottling = false;
			}
		} else {
			throw std::exception("ShipSpriteManager::update(): \
								 world object was not a ship");
		}
	}

	if (m_animationSprite && m_animationSprite->isFinished()) {

		// If we've finished playing a ship destruction animation, then
		// get rid of the animation sprite pointer, clear all sprites and
		// invalidate this sprite manager:
		if (m_animationSprite->getAnimation() == AnimationSprite::SHIP_DESTROY) {
			delete m_animationSprite;
			m_animationSprite = 0;
			clearSprites();
			m_valid = false;
		}
	} else {
		
		if (m_animationSprite) {
			clearSprites();
			addSprite(*m_animationSprite);
		}

		// Do common world object update:
		WorldSpriteManager::update();
	}
}


/**
 * Plays a ship destruction animation and 
 */
void ShipSpriteManager::startShipThrottleAnim() {
	// next version
}


/**
 * Plays a ship destruction animation and 
 */
void ShipSpriteManager::startShipDamageAnim() {
	// next version
}


/**
 * Plays a ship destruction animation and finishes the sprite manager.
 */
void ShipSpriteManager::startShipDestructionAnim() {
	
	// Get rid of previous ship sprite(s):
	clearSprites();

	// Create and setup a ship destruction animation sprite:
	m_animationSprite = new AnimationSprite(
		m_worldObject->getShape(),
		AnimationSprite::SHIP_DESTROY, 3, 0);
	m_animationSprite->setRotation(m_worldObject->getShape().getOrientation());
	m_animationSprite->play();

	// Make that animation sprite available for drawing:
	addSprite(*m_animationSprite);
}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
ShipSpriteManager* ShipSpriteManager::clone() const {
	return new ShipSpriteManager(*this);
}


/**
 * Returns the correct sprite image for a ship of the current color.
 * Throws exception if the requested sprite isn't found.
 */
Sprite::sprite_image_t ShipSpriteManager::getSpriteImage(
	ShipSpriteManager::ship_sprite_t shipSprite) const {
	
	Sprite::sprite_image_t image = m_shipColorSprites[m_shipColor][shipSprite];

	if (!image) {
		throw std::exception("ShipSpriteManager::init(): \
							 invalid sprite image");
	}

	return image;
}