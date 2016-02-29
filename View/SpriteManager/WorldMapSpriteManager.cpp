///////////////////////////////////////////////////////////
//  WorldMapSpriteManager.cpp
//  Implementation of the Class WorldMapSpriteManager
//  Created on:      05-May-2008 21:00:11
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "WorldMapSpriteManager.h"
#include "Planet.h"
#include "Ship.h"


const float WorldMapSpriteManager::SIZE = 100.0f;


/**
 * Constructs a world map sprite manager, specifying the engine from which it
 * should read its data.
 * 
 * @param engine
 */
WorldMapSpriteManager::WorldMapSpriteManager(const Engine* engine):
SpriteManager(Coord2d(0,0)),
m_engine(engine)
{
}


WorldMapSpriteManager::~WorldMapSpriteManager() {
}


/**
 * Initializes the sprite manager.
 */
void WorldMapSpriteManager::init() {

	if (!m_engine) {
		throw std::exception("WorldMapSpriteManager::init(): m_engine was 0");
	}
	
	// Create and add background sprite:
	Sprite sprite(Sprite::HUD_WORLD_MAP_BG, CircularShape(50));
	sprite.setPosition(Coord2d(0, 0));
	addSprite(sprite);

	// Create, save and add planet sprites:
	const World & world = m_engine->getWorld();
	float worldWidth = world.getLowerRight().getX() - world.getUpperLeft().getX();
	float worldHeight = world.getLowerRight().getY() - world.getUpperLeft().getY();
	const WorldObjectsManager::world_objects_t & worldObjects =
		world.getWorldObjectsManager().getWorldObjects();

	WorldObjectsManager::world_objects_t::const_iterator wo_it = worldObjects.begin();
	for ( ; wo_it != worldObjects.end(); ++wo_it) {
		if (const Planet * planet = dynamic_cast<const Planet*>(*wo_it)) {
			const Coord2d & planetPos = planet->getPosition();

			// Calculate ship position ratio:
			float xRatio = planetPos.getX() / worldWidth;
			float yRatio = planetPos.getY() / worldHeight;

			float widthRatio = planet->getShape().getRadius() * 2 / worldWidth;
			float heightRatio = planet->getShape().getRadius() * 2 / worldHeight;

			float planetSpriteWidth = SIZE * widthRatio;
			float planetSpriteHeight = SIZE * heightRatio;

			float planetSpriteX = SIZE * xRatio - SIZE / 2;
			float planetSpriteY = SIZE * yRatio - SIZE / 2;

			Sprite planetSprite(Sprite::HUD_WORLD_MAP_PLANET, planetSpriteWidth, planetSpriteHeight);

			planetSprite.setPosition(Coord2d(planetSpriteX, planetSpriteY));
			planetSprite.setRotation(planet->getShape().getOrientation());
			m_planetSprites.push_back(planetSprite);
			addSprite(planetSprite);
		}
	}

	const Engine::players_t & players = m_engine->getPlayers();
	Engine::players_t::const_iterator player_it = players.begin();

	std::vector<Sprite::sprite_image_t> shipSpriteImages;
	shipSpriteImages.push_back(Sprite::HUD_WORLD_MAP_SHIP_1);
	shipSpriteImages.push_back(Sprite::HUD_WORLD_MAP_SHIP_2);
	std::vector<Sprite::sprite_image_t>::iterator shipSpriteImage_it = shipSpriteImages.begin();

	// Create sprites for all players (ships):
	for ( ; player_it != players.end(); ++player_it, ++shipSpriteImage_it) {
		Sprite shipSprite(*shipSpriteImage_it, CircularShape(10));
		m_shipSprites.push_back(shipSprite);
		addSprite(shipSprite);

		if (shipSpriteImage_it == shipSpriteImages.end()) {
			shipSpriteImage_it = shipSpriteImages.begin();
		}
	}

	SpriteManager::init();
}


/**
 * Updates sprites according to new ship positions.
 */
void WorldMapSpriteManager::update() {

	if (!m_initialized) {
		throw std::exception("WorldMapSpriteManager::update(): not initialized");
	}

	const World & world = m_engine->getWorld();
	float worldWidth = world.getLowerRight().getX() - world.getUpperLeft().getX();
	float worldHeight = world.getLowerRight().getY() - world.getUpperLeft().getY();
	const Engine::players_t & players = m_engine->getPlayers();

	if (players.size() != m_shipSprites.size()) {
		throw std::exception("WorldMapSpriteManager::update(): \
							 number of players is not the same as the number of \
							 ship sprites");
	}

	Engine::players_t::const_iterator player_it = players.begin();
	ship_sprites_t::iterator shipSprite_it = m_shipSprites.begin();

	// Clear sprites in parent:
	clearSprites();

	// Add map background:
	addSprite(Sprite(Sprite::HUD_WORLD_MAP_BG, CircularShape(SIZE/2)));
	
	// Add planets:
	planet_sprites_t::iterator planet_it = m_planetSprites.begin();
	for ( ; planet_it != m_planetSprites.end(); ++planet_it) {
		addSprite(*planet_it);
	}

	for ( ; player_it != players.end(); ++player_it, ++shipSprite_it) {

		Ship * ship = (*player_it)->getCurrentShip();

		if (ship) {
			const Coord2d & shipPos = ship->getPosition();

			// Calculate ship position ratio:
			float xRatio = shipPos.getX() / worldWidth;
			float yRatio = shipPos.getY() / worldHeight;

			float shipSpriteX = SIZE * xRatio - SIZE / 2;
			float shipSpriteY = SIZE * yRatio - SIZE / 2;

			shipSprite_it->setPosition(Coord2d(shipSpriteX, shipSpriteY));
			shipSprite_it->setRotation(ship->getShape().getOrientation());
			addSprite(*shipSprite_it);
		}
	}
}


/**
 * Clones the world map sprite manager, returning a pointer to the clone.
 */
WorldMapSpriteManager* WorldMapSpriteManager::clone() const {
	return new WorldMapSpriteManager(*this);
}