///////////////////////////////////////////////////////////
//  PlanetSpriteManager.cpp
//  Implementation of the Class PlanetSpriteManager
//  Created on:      28-mar-2008 10:31:40
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "PlanetSpriteManager.h"


PlanetSpriteManager::PlanetSpriteManager(const Planet* planet):
WorldSpriteManager(planet),
m_planetType(planet->getType())
{
}


PlanetSpriteManager::~PlanetSpriteManager() {
}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
PlanetSpriteManager* PlanetSpriteManager::clone() const {
	return new PlanetSpriteManager(*this);
}


void PlanetSpriteManager::init() {
	WorldSpriteManager::init();

	Sprite::sprite_image_t image;

	switch (m_planetType) {
		case Planet::EARTH:
			image = Sprite::PLANET_EARTH;
			break;
		case Planet::MARS:
			image = Sprite::PLANET_MARS;
			break;
		case Planet::PLUTO:
			image = Sprite::PLANET_PLUTO;
			break;
		default:
			throw std::exception("PlanetSpriteManager::init(): \
								 invalid planet type");
	}

	addSprite(Sprite(image, m_worldObject->getShape()));
}