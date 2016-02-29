///////////////////////////////////////////////////////////
//  Sprite.h
//  Implementation of the Class Sprite
//  Created on:      28-mar-2008 10:34:44
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_A1327F57_78D3_4d2a_8779_DCF625DF8CBA__INCLUDED_)
#define EA_A1327F57_78D3_4d2a_8779_DCF625DF8CBA__INCLUDED_

#include <exception>
#include <string>

#include "Shape.h"
#include "Coord2d.h"
#include "CircularShape.h"

#define SPRITE_WORLD_LAYER				1000
#define SPRITE_WORLD_BACKGROUND_LAYER	SPRITE_WORLD_LAYER
#define SPRITE_WORLD_SPAWNPOINT_LAYER	SPRITE_WORLD_LAYER + 100
#define SPRITE_WORLD_PLANET_LAYER		SPRITE_WORLD_LAYER + 200
#define SPRITE_WORLD_ASTEROID_LAYER		SPRITE_WORLD_LAYER + 300
#define SPRITE_WORLD_ITEM_LAYER			SPRITE_WORLD_LAYER + 400
#define SPRITE_WORLD_PROJECTILE_LAYER	SPRITE_WORLD_LAYER + 500
#define SPRITE_WORLD_SHIP_LAYER			SPRITE_WORLD_LAYER + 600

#define SPRITE_HUD_LAYER				2000
#define SPRITE_MENU_LAYER				3000

class Sprite
{
private:

	/**
	 * Sprite image width.
	 */
	float m_width;

	/**
	 * Sprite image height.
	 */
	float m_height;

public:

	enum sprite_image_t {
		__NOIMAGE__						= 0,	// Corresponds to "NULL"...
		ASTEROID						= SPRITE_WORLD_ASTEROID_LAYER + 1,
		ASTEROID_INSERT_F1				= SPRITE_WORLD_ASTEROID_LAYER + 2,
		ASTEROID_INSERT_F2				= SPRITE_WORLD_ASTEROID_LAYER + 3,
		ASTEROID_INSERT_F3				= SPRITE_WORLD_ASTEROID_LAYER + 4,
		ASTEROID_INSERT_F4				= SPRITE_WORLD_ASTEROID_LAYER + 5,
		ASTEROID_INSERT_F5				= SPRITE_WORLD_ASTEROID_LAYER + 6,
		ASTEROID_INSERT_F6				= SPRITE_WORLD_ASTEROID_LAYER + 7,
		ASTEROID_INSERT_F7				= SPRITE_WORLD_ASTEROID_LAYER + 8,
		ASTEROID_INSERT_F8				= SPRITE_WORLD_ASTEROID_LAYER + 9,
		ASTEROID_DESTROY_F1				= SPRITE_WORLD_ASTEROID_LAYER + 10,
		ASTEROID_DESTROY_F2				= SPRITE_WORLD_ASTEROID_LAYER + 11,
		ASTEROID_DESTROY_F3				= SPRITE_WORLD_ASTEROID_LAYER + 12,
		ASTEROID_DESTROY_F4				= SPRITE_WORLD_ASTEROID_LAYER + 13,
		BACKGROUND_1					= SPRITE_WORLD_BACKGROUND_LAYER,
		CHAR_0							= SPRITE_MENU_LAYER + 1,
		CHAR_1							= SPRITE_MENU_LAYER + 2,
		CHAR_2							= SPRITE_MENU_LAYER + 3,
		CHAR_3							= SPRITE_MENU_LAYER + 4,
		CHAR_4							= SPRITE_MENU_LAYER + 5,
		CHAR_5							= SPRITE_MENU_LAYER + 6,
		CHAR_6							= SPRITE_MENU_LAYER + 7,
		CHAR_7							= SPRITE_MENU_LAYER + 8,
		CHAR_8							= SPRITE_MENU_LAYER + 9,
		CHAR_9							= SPRITE_MENU_LAYER + 10,
		CHAR_COLON						= SPRITE_MENU_LAYER + 11,
		CHAR_COMMA						= SPRITE_MENU_LAYER + 12,
		CHAR_EXCLAMATION				= SPRITE_MENU_LAYER + 13,
		CHAR_PERIOD						= SPRITE_MENU_LAYER + 14,
		CHAR_QUESTION					= SPRITE_MENU_LAYER + 15,
		CHAR_SPACE						= SPRITE_MENU_LAYER + 16,
		CHAR_UC_A						= SPRITE_MENU_LAYER + 17,
		CHAR_UC_B						= SPRITE_MENU_LAYER + 18,
		CHAR_UC_C						= SPRITE_MENU_LAYER + 19,
		CHAR_UC_D						= SPRITE_MENU_LAYER + 20,
		CHAR_UC_E						= SPRITE_MENU_LAYER + 21,
		CHAR_UC_F						= SPRITE_MENU_LAYER + 22,
		CHAR_UC_G						= SPRITE_MENU_LAYER + 23,
		CHAR_UC_H						= SPRITE_MENU_LAYER + 24,
		CHAR_UC_I						= SPRITE_MENU_LAYER + 25,
		CHAR_UC_J						= SPRITE_MENU_LAYER + 26,
		CHAR_UC_K						= SPRITE_MENU_LAYER + 27,
		CHAR_UC_L						= SPRITE_MENU_LAYER + 28,
		CHAR_UC_M						= SPRITE_MENU_LAYER + 29,
		CHAR_UC_N						= SPRITE_MENU_LAYER + 30,
		CHAR_UC_O						= SPRITE_MENU_LAYER + 31,
		CHAR_UC_P						= SPRITE_MENU_LAYER + 32,
		CHAR_UC_Q						= SPRITE_MENU_LAYER + 33,
		CHAR_UC_R						= SPRITE_MENU_LAYER + 34,
		CHAR_UC_S						= SPRITE_MENU_LAYER + 35,
		CHAR_UC_T						= SPRITE_MENU_LAYER + 36,
		CHAR_UC_U						= SPRITE_MENU_LAYER + 37,
		CHAR_UC_V						= SPRITE_MENU_LAYER + 38,
		CHAR_UC_W						= SPRITE_MENU_LAYER + 39,
		CHAR_UC_X						= SPRITE_MENU_LAYER + 40,
		CHAR_UC_Y						= SPRITE_MENU_LAYER + 41,
		CHAR_UC_Z						= SPRITE_MENU_LAYER + 42,
		FUEL_ITEM						= SPRITE_WORLD_ITEM_LAYER + 1,
		HUD_LIVES_LEFT					= SPRITE_HUD_LAYER + 1,
		HUD_SHIP_ENERGY_0				= SPRITE_HUD_LAYER + 2,
		HUD_SHIP_ENERGY_20				= SPRITE_HUD_LAYER + 3,
		HUD_SHIP_ENERGY_40				= SPRITE_HUD_LAYER + 4,
		HUD_SHIP_ENERGY_60				= SPRITE_HUD_LAYER + 5,
		HUD_SHIP_ENERGY_80				= SPRITE_HUD_LAYER + 6,
		HUD_SHIP_ENERGY_100				= SPRITE_HUD_LAYER + 7,
		HUD_SHIP_FUEL_0					= SPRITE_HUD_LAYER + 8,
		HUD_SHIP_FUEL_10				= SPRITE_HUD_LAYER + 9,
		HUD_SHIP_FUEL_20				= SPRITE_HUD_LAYER + 10,
		HUD_SHIP_FUEL_30				= SPRITE_HUD_LAYER + 11,
		HUD_SHIP_FUEL_40				= SPRITE_HUD_LAYER + 12,
		HUD_SHIP_FUEL_50				= SPRITE_HUD_LAYER + 13,
		HUD_SHIP_FUEL_60				= SPRITE_HUD_LAYER + 14,
		HUD_SHIP_FUEL_70				= SPRITE_HUD_LAYER + 15,
		HUD_SHIP_FUEL_80				= SPRITE_HUD_LAYER + 16,
		HUD_SHIP_FUEL_90				= SPRITE_HUD_LAYER + 17,
		HUD_SHIP_FUEL_100				= SPRITE_HUD_LAYER + 18,
		HUD_WORLD_MAP_BG				= SPRITE_HUD_LAYER + 19,
		HUD_WORLD_MAP_PLANET			= SPRITE_HUD_LAYER + 20,
		HUD_WORLD_MAP_SHIP_1			= SPRITE_HUD_LAYER + 21,
		HUD_WORLD_MAP_SHIP_2			= SPRITE_HUD_LAYER + 22,
		LASER							= SPRITE_WORLD_PROJECTILE_LAYER + 1,
		MENU_SELECTED_PREFIX			= SPRITE_MENU_LAYER + 44,
		MISSILE							= SPRITE_WORLD_PROJECTILE_LAYER + 2,
		MISSILE_ITEM					= SPRITE_WORLD_ITEM_LAYER + 2,
		PLANET_MARS						= SPRITE_WORLD_PLANET_LAYER + 1,
		PLANET_EARTH					= SPRITE_WORLD_PLANET_LAYER + 2,
		PLANET_PLUTO					= SPRITE_WORLD_PLANET_LAYER + 3,
		SHIP_RED						= SPRITE_WORLD_SHIP_LAYER + 1,
		SHIP_BLUE						= SPRITE_WORLD_SHIP_LAYER + 2,
		SHIP_DESTROY_F1					= SPRITE_WORLD_SHIP_LAYER + 3,
		SHIP_DESTROY_F2					= SPRITE_WORLD_SHIP_LAYER + 4,
		SHIP_DESTROY_F3					= SPRITE_WORLD_SHIP_LAYER + 5,
		SHIP_DESTROY_F4					= SPRITE_WORLD_SHIP_LAYER + 6,
		SHIP_BLUE_THROTTLE_F1			= SPRITE_WORLD_SHIP_LAYER + 7,
		SHIP_BLUE_THROTTLE_F2			= SPRITE_WORLD_SHIP_LAYER + 8,
		SHIP_BLUE_THROTTLE_F3			= SPRITE_WORLD_SHIP_LAYER + 9,
		SHIP_RED_THROTTLE_F1			= SPRITE_WORLD_SHIP_LAYER + 10,
		SHIP_RED_THROTTLE_F2			= SPRITE_WORLD_SHIP_LAYER + 11,
		SHIP_RED_THROTTLE_F3			= SPRITE_WORLD_SHIP_LAYER + 12,
		SPAWN_POINT_FREE				= SPRITE_WORLD_SPAWNPOINT_LAYER + 1,
		SPAWN_POINT_OCCUPIED			= SPRITE_WORLD_SPAWNPOINT_LAYER + 2
	};

	/**
	 * Constructs a sprite, specifying the image it should represent as well as the
	 * shape that it should use for size calculation.
	 * 
	 * @param image
	 * @param shape
	 */
	Sprite(sprite_image_t image, const Shape& shape);

	/**
	 * Constructs a sprite, specifying the image it should represent as well as its
	 * size (width + height).
	 * 
	 * @param image
	 * @param width
	 * @param height
	 */
	Sprite(sprite_image_t image, float width, float height);

	virtual ~Sprite();

	sprite_image_t getImage() const;

	/**
	 * Returns the sprite image width.
	 */
	float getWidth() const;

	/**
	 * Returns the sprite image height.
	 */
	float getHeight() const;

	/**
	 * Clones the sprite, returning a pointer to the cloned one.
	 */
	virtual Sprite* clone() const;

	/**
	 * Sets the sprite's rotation according to the unit circle.
	 * 
	 * @param rotation
	 */
	void setRotation(float rotation);

	/**
	 * Sets the sprite's position.
	 * 
	 * @param position
	 */
	void setPosition(const Coord2d& position);

	/**
	 * Sets the sprite's rotation according to the unit circle.
	 */
	float getRotation() const;

	float getRotationDeg() const;

	/**
	 * Sets the sprite's position.
	 */
	const Coord2d& getPosition() const;

	virtual bool operator<(const Sprite& sprite) const;

protected:

	/**
	 * The sprite alias (see IMG_* constants).
	 */
	sprite_image_t m_image;

	/**
	 * Constructs a sprite, specifying the shape that it should use for size
	 * calculation. Used by children to this class, that can't set an image in the
	 * init list.
	 * 
	 * @param shape
	 */
	Sprite(const Shape& shape);

	/**
	 * Constructs a sprite, specifying its size. Used by children to this class, that
	 * can't set an image in the init list.
	 * 
	 * @param width
	 * @param height
	 */
	Sprite(float width, float height);

private:

	/**
	 * The rotation of the sprite according to the unit circle.
	 */
	float m_rotation;

	/**
	 * The position of the sprite in its context.
	 */
	Coord2d m_position;

	/**
	 * Catches the unknown shape case.
	 * 
	 * @param shape
	 */
	void setSizeFromShape(const Shape& shape);

	/**
	 * Sets the sprite size, which is calculated by using a circular shape.
	 * 
	 * @param shape
	 */
	void setSizeFromShape(const CircularShape& shape);

};

#endif // !defined(EA_A1327F57_78D3_4d2a_8779_DCF625DF8CBA__INCLUDED_)
