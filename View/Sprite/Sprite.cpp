///////////////////////////////////////////////////////////
//  Sprite.cpp
//  Implementation of the Class Sprite
//  Created on:      28-mar-2008 10:35:04
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "Sprite.h"

#ifndef M_PI
#define M_PI 3.1415926535897932385f
#endif

/**
 * Constructs a sprite, specifying the image it should represent as well as the
 * shape that it should use for size calculation.
 * 
 * @param image
 * @param shape
 */
Sprite::Sprite(sprite_image_t image, const Shape& shape):
m_image(image),
m_position(Coord2d(0,0)),
m_rotation(0)
{
	setSizeFromShape(shape);
}


/**
 * Constructs a sprite, specifying the image it should represent as well as its
 * size (width + height).
 * 
 * @param image
 * @param width
 * @param height
 */
Sprite::Sprite(sprite_image_t image, float width, float height):
m_image(image),
m_width(width),
m_height(height),
m_rotation(0),
m_position(Coord2d(0,0))
{
}


/**
 * Constructs a sprite, specifying the shape that it should use for size
 * calculation. Used by children to this class, that can't set an image in the
 * init list.
 * 
 * @param shape
 */
Sprite::Sprite(const Shape& shape):
m_image(Sprite::__NOIMAGE__)
{
	setSizeFromShape(shape);
}


/**
 * Constructs a sprite, specifying its size. Used by children to this class, that
 * can't set an image in the init list.
 * 
 * @param width
 * @param height
 */
Sprite::Sprite(float width, float height):
m_width(width),
m_height(height),
m_image(Sprite::__NOIMAGE__),
m_rotation(0),
m_position(Coord2d(0,0))
{
}


Sprite::~Sprite() {
}


/**
 * Returns the sprite's image constant value.
 */
Sprite::sprite_image_t Sprite::getImage() const {
	return m_image;
}


/**
 * Returns the sprite image width.
 */
float Sprite::getWidth() const {
	return m_width;
}


/**
 * Returns the sprite image height.
 */
float Sprite::getHeight() const {
	return m_height;
}


/**
 * Clones the sprite, returning a pointer to the cloned one.
 */
Sprite* Sprite::clone() const {
	return new Sprite(*this);
}


/**
 * Catches the unknown shape case.
 * 
 * @param shape
 */
void Sprite::setSizeFromShape(const Shape& shape) {

	if (const CircularShape * cshape =
		dynamic_cast<const CircularShape*>(&shape)) {
		setSizeFromShape(*cshape);
	} else {
		throw std::exception("Sprite::setSizeFromShape(): \
							 unsupported shape type");
	}
}


/**
 * Sets the sprite size, which is calculated by using a circular shape.
 * 
 * @param shape
 */
void Sprite::setSizeFromShape(const CircularShape& shape) {
	m_width = m_height = shape.getRadius() * 2;
}


/**
 * Sets the sprite's rotation according to the unit circle.
 * 
 * @param rotation
 */
void Sprite::setRotation(float rotation) {
	m_rotation = rotation;
}


/**
 * Sets the sprite's position.
 * 
 * @param position
 */
void Sprite::setPosition(const Coord2d& position) {
	m_position = position;
}


/**
 * Sets the sprite's rotation according to the unit circle.
 */
float Sprite::getRotation() const {
	return m_rotation;
}


/**
 * Gets the sprite's rotation in degrees
 */
float Sprite::getRotationDeg() const {
	return m_rotation * (180.0f/M_PI);
}


/**
 * Sets the sprite's position.
 */
const Coord2d& Sprite::getPosition() const {
	return m_position;
}


bool Sprite::operator<(const Sprite& sprite) const {
	return m_image < sprite.m_image;
}