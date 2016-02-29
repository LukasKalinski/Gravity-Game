///////////////////////////////////////////////////////////
//  HUD.cpp
//  Implementation of the Class HUD
//  Created on:      04-May-2008 21:42:29
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "HUD.h"


/**
 * Creates a heads up display, specifying the width and height of the area in
 * which it should position itself.
 * 
 * @param width
 * @param height
 */
HUD::HUD(float width, float height):
m_screenWidth(width),
m_screenHeight(height)
{
}


HUD::~HUD() {
	// FIXME: Delete sprite manager pointers!
}


/**
 * Adds a sprite manager for the world map HUD element.
 * 
 * @param sm
 */
void HUD::addSpriteManager(WorldMapSpriteManager& sm) {

	//Calculate and set the sprite manager's
	//positon and add it to the collection of
	//sprite managers.

	SpriteManager * insertedSm = sm.clone();
	m_spriteManagers.push_back(insertedSm);
	insertedSm->setReferencePoint(Coord2d(0, 0));
	insertedSm->init();
}


/**
 * Updates and reloads all sprites for this HUD.
 */
void HUD::reloadSprites() {

	m_sprites.clear();

	sprite_managers_t::iterator sm_it = m_spriteManagers.begin();
	for ( ; sm_it != m_spriteManagers.end(); ++sm_it) {

		(*sm_it)->update();

		const SpriteManager::sprites_t & sm_sprites = (*sm_it)->getSprites();
		SpriteManager::sprites_t::const_iterator sm_sprites_it = sm_sprites.begin();

		for ( ; sm_sprites_it != sm_sprites.end(); ++sm_sprites_it) {
			Sprite sprite = *sm_sprites_it;

			// Set sprite position according to its sprite manager's reference point:
			sprite.setPosition((*sm_it)->getReferencePoint() + sprite.getPosition());
			m_sprites.insert(sprite);
		}
	}
}


/**
 * Returns the sprites to be drawn within this HUD's area. Positions are relative
 * to the HUD's lower left corner, which has coord (0,0).
 */
HUD::sprites_t HUD::getSprites() const {
	return m_sprites;
}