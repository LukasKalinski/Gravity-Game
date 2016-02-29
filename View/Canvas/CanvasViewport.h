///////////////////////////////////////////////////////////
//  CanvasViewport.h
//  Implementation of the Class CanvasViewport
//  Created on:      06-Apr-2008 19:10:59
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_54736D84_759E_4cae_8E07_9A72FC5FF146__INCLUDED_)
#define EA_54736D84_759E_4cae_8E07_9A72FC5FF146__INCLUDED_

#include <set>

#include "Coord2d.h"
#include "SpriteManager.h"
#include "Canvas.h"
#include "CircularShape.h"

/**
 * Represents a viewport of a canvas. Contains and provides the sprite managers
 * that are positioned within the viewport.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 06-Apr-2008 19:57:43
 */
class CanvasViewport
{

public:

	typedef std::multiset<Sprite> sprites_t;

	// deprecated:
	typedef std::vector<SpriteManager*> sprite_managers_t;

	/**
	 * Constructs a viewport, specifying the space in which the viewport
	 * will "operate".
	 */
	CanvasViewport(const Coord2d& upperLeft, const Coord2d& lowerRight);

	virtual ~CanvasViewport();
	CanvasViewport(const CanvasViewport& viewport);

	/**
	 * Returns the center coordinate of the screen (i.e., the coordinate that should
	 * appear at the center of it).
	 */
	const Coord2d& getCenter() const;

	/**
	 * Returns the sprites visible in this viewport.
	 */
	const sprites_t& getSprites() const;

	/**
	 * Sets the center position of the viewport.
	 * 
	 * @param position
	 */
	void setCenter(const Coord2d& position);

	/**
	 * Sets the z-axis value representing the distance the viewport has in relation to
	 * the contained sprite managers' sprites.
	 * 
	 * @param zValue
	 */
	void setDistance(float zValue);

	/**
	 * Returns the z-axis value representing the distance the viewport has in relation
	 * to the contained sprite managers' sprites.
	 */
	float getDistance() const;

	/**
	 * Adds a sprite to the viewport.
	 */
	void addSprite(const Sprite& sprite);

	/**
	 * Clears the sprites contained by this viewport.
	 */
	void clearSprites();

protected:

	/**
	 * The center coordinate of the viewport (i.e., the coordinate that should appear
	 * at the center of it).
	 */
	Coord2d m_center;

private:

	/**
	 * The z-axis value representing the distance the viewport has in relation to the
	 * contained sprite managers' sprites.
	 */
	float m_distance;

	/**
	 * Sprites in this viewport, having absolute positions.
	 */
	sprites_t m_sprites;

	/**
	 * The circular shape determining what is seen in the viewport.
	 */
	CircularShape m_cshape;

};
#endif // !defined(EA_54736D84_759E_4cae_8E07_9A72FC5FF146__INCLUDED_)
