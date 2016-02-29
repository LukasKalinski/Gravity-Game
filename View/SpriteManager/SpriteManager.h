///////////////////////////////////////////////////////////
//  SpriteManager.h
//  Implementation of the Class SpriteManager
//  Created on:      28-mar-2008 10:35:08
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_274F65F0_3DD1_4aac_BD43_88BA32986989__INCLUDED_)
#define EA_274F65F0_3DD1_4aac_BD43_88BA32986989__INCLUDED_

#include <vector>

#include "GameEventManager.h"
#include "Sprite.h"
#include "AnimationSprite.h"
#include "Vector2d.h"

/**
 * A sprite manager is responsible for managing the sprites associated with a game
 * state (e.g., the main menu) or a single visual game element (e.g., a ship or a
 * menu button).
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 05-Apr-2008 16:47:13
 */
class SpriteManager
{

public:

	typedef std::vector<Sprite> sprites_t;

	/**
	 * Constructs a sprite manager, specifying the reference point coordinate to use.
	 * 
	 * @param refPoint
	 */
	SpriteManager(const Vector2d& refPoint);

	virtual ~SpriteManager();
	SpriteManager(const SpriteManager& sm);

	bool isValid() const;

	/**
	 * Updates sprite manager.
	 */
	virtual void update();

	/**
	 * Set the game event manager to use within the sprite manager.
	 */
	virtual void setEventManager(GameEventManager* eventManager);

	virtual void init();

	/**
	 * Returns the coordinate in relation to which all sprites
	 * are to be drawn. (Hint: move coordinate system to this
	 * coordinate before drawing.)
	 */
	const Vector2d& getReferencePoint() const;

	void setReferencePoint(const Vector2d& refPoint);

	/**
	 * Returns a vector of the sprites that are available for drawing.
	 */
	const sprites_t& getSprites() const;

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual SpriteManager* clone() const = 0;

protected:

	/**
	 * Game event manager to register/unregister self in/from.
	 */
	GameEventManager * m_eventManager;

	/**
	 * Tells whether the sprite manager is initialized or not.
	 */
	bool m_initialized;

	/**
	 * Tells whether the sprite manager is valid or not.
	 */
	bool m_valid;

	/**
	 * Reference coordinate in relation to which all contained
	 * sprites' coordinates are expressed.
	 */
	Vector2d m_refPoint;

	/**
	 * Adds a sprite, making it available for drawing.
	 * 
	 * @param sprite
	 */
	void addSprite(const Sprite& sprite);

	/**
	 * Clears all sprites that were available for drawing.
	 */
	void clearSprites();

	/**
	 * Contains the sprites that are available for drawing.
	 */
	sprites_t m_sprites;

};
#endif // !defined(EA_274F65F0_3DD1_4aac_BD43_88BA32986989__INCLUDED_)
