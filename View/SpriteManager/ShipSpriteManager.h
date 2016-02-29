///////////////////////////////////////////////////////////
//  ShipSpriteManager.h
//  Implementation of the Class ShipSpriteManager
//  Created on:      28-Mar-2008 17:26:50
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_42BB6FD9_5A57_4538_BFC8_5F2CBD8A9D44__INCLUDED_)
#define EA_42BB6FD9_5A57_4538_BFC8_5F2CBD8A9D44__INCLUDED_

#include <map>

#include "WorldSpriteManager.h"
#include "Sprite.h"
#include "Ship.h"


/**
 * Responsible for managing sprites for a ship.
 */
class ShipSpriteManager :
	public WorldSpriteManager,
	public WorldObjectDestructionListener
{

public:

	// Use WorldSpriteManager's removal order handling:
	using WorldSpriteManager::notifyEvent;

	ShipSpriteManager(const Ship* ship);
	virtual ~ShipSpriteManager();
	ShipSpriteManager(const ShipSpriteManager& sm);

	virtual void notifyEvent(const WorldObjectDestructionEvent& ev);
	virtual void notifyEvent(const WorldObjectRemoveEvent& ev);

	virtual void init();

	/**
	 * Checks animation sprite (if any) and falls back to a non-animation
	 * sprite if the animation is finished or should not longer be played.
	 * If the animation is a destruction animation, then when it is finished,
	 * the ship sprite manager becomes invalid.
	 */
	virtual void update();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual ShipSpriteManager* clone() const;

private:

	enum ship_sprite_t {
		SHIP,
		SHIP_THROTTLE_F1,
		SHIP_THROTTLE_F2,
		SHIP_THROTTLE_F3
	};

	typedef std::map<Ship::color_t, std::map<ship_sprite_t, Sprite::sprite_image_t> > ship_color_sprites_t;

	/**
	 * Holds sets of sprites available for the ship, depending on its color.
	 */
	static ship_color_sprites_t m_shipColorSprites;

	/**
	 * Pointer to the animation sprite currently used for representation
	 * of the ship. If ship isn't represented by an animation, then this
	 * will be 0.
	 */
	AnimationSprite * m_animationSprite;

	/**
	 * Tells whether the monitored ship is throttling or not.
	 */
	bool m_isThrottling;

	/**
	 * The color of the monitored ship.
	 */
	Ship::color_t m_shipColor;

	/**
	 * Initiates a ship throttle animation sprite.
	 */
	void startShipThrottleAnim();

	/**
	 * Initiates a ship damage animation sprite.
	 */
	void startShipDamageAnim();

	/**
	 * Initiates a ship destruction animation sprite.
	 */
	void startShipDestructionAnim();

	/**
	 * Returns the correct sprite image for a ship of the current color.
	 * Throws exception if the requested sprite isn't found.
	 */
	Sprite::sprite_image_t getSpriteImage(ship_sprite_t shipSprite) const;

};
#endif // !defined(EA_42BB6FD9_5A57_4538_BFC8_5F2CBD8A9D44__INCLUDED_)
