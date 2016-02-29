///////////////////////////////////////////////////////////
//  WorldMapSpriteManager.h
//  Implementation of the Class WorldMapSpriteManager
//  Created on:      05-May-2008 21:00:09
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_72178CF0_C9E1_4c7a_816E_C8459EA094F3__INCLUDED_)
#define EA_72178CF0_C9E1_4c7a_816E_C8459EA094F3__INCLUDED_

#include "SpriteManager.h"
#include "Engine.h"

/**
 * Represents the world map showing where the ships are.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 05-May-2008 21:24:16
 */
class WorldMapSpriteManager : public SpriteManager
{

public:

	/**
	 * Constructs a world map sprite manager, specifying the engine from which it
	 * should read its data.
	 * 
	 * @param engine
	 */
	WorldMapSpriteManager(const Engine* engine);

	virtual ~WorldMapSpriteManager();

	/**
	 * Initializes the sprite manager.
	 */
	virtual void init();

	/**
	 * Updates sprites according to new ship positions.
	 */
	virtual void update();
	
	/**
	 * Clones the world map sprite manager, returning a pointer to the clone.
	 */
	virtual WorldMapSpriteManager* clone() const;

private:

	typedef std::vector<Sprite> planet_sprites_t;
	typedef std::vector<Sprite> ship_sprites_t;

	/**
	 * Defines the size (width and height) of the map HUD element.
	 */
	static const float SIZE;

	/**
	 * The engine instance to read data from.
	 */
	const Engine *m_engine;

	/**
	 * Contains the sprites that represent ships on the mini-map.
	 */
	ship_sprites_t m_shipSprites;

	/**
	 * Contains the planets available in the world.
	 */
	planet_sprites_t m_planetSprites;

};
#endif // !defined(EA_72178CF0_C9E1_4c7a_816E_C8459EA094F3__INCLUDED_)
