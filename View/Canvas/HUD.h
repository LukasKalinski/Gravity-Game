///////////////////////////////////////////////////////////
//  HUD.h
//  Implementation of the Class HUD
//  Created on:      04-May-2008 21:42:26
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_93916BD0_10A4_4e5d_92D3_E412263015D4__INCLUDED_)
#define EA_93916BD0_10A4_4e5d_92D3_E412263015D4__INCLUDED_

#include <vector>

#include "Sprite.h"
#include "WorldMapSpriteManager.h"

/**
 * Responsible for managing a Heads-Up Display (HUD).
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 05-May-2008 22:00:38
 */
class HUD
{

public:

	typedef std::multiset<Sprite> sprites_t;
	typedef std::vector<SpriteManager*> sprite_managers_t;

	/**
	 * @author Lukas Kalinski
	 * @version 1.0
	 * @updated 05-May-2008 22:00:39
	 */

	/**
	 * Creates a heads up display, specifying the width and height of the area in
	 * which it should position itself.
	 * 
	 * @param width
	 * @param height
	 */
	HUD(float width, float height);

	virtual ~HUD();

	/**
	 * Adds a sprite manager for the world map HUD element.
	 * 
	 * @param sm
	 */
	void addSpriteManager(WorldMapSpriteManager& sm);

	/**
	 * Updates and reloads all sprites for this HUD.
	 */
	void reloadSprites();

	/**
	 * Returns the sprites to be drawn within this HUD's area. Positions are relative
	 * to the HUD's upper left corner, which has coord (0,0).
	 */
	sprites_t getSprites() const;

private:

	float m_screenWidth;
	float m_screenHeight;
	sprite_managers_t m_spriteManagers;
	sprites_t m_sprites;

};
#endif // !defined(EA_93916BD0_10A4_4e5d_92D3_E412263015D4__INCLUDED_)
