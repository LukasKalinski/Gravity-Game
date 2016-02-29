///////////////////////////////////////////////////////////
//  CanvasViewport.cpp
//  Implementation of the Class CanvasViewport
//  Created on:      06-Apr-2008 19:11:00
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <algorithm>

#include "CanvasViewport.h"


/**
 * Constructs a viewport, specifying the space in which the viewport
 * will "operate".
 */
CanvasViewport::CanvasViewport(const Coord2d& upperLeft, const Coord2d& lowerRight):
m_center(Coord2d(0,0)),
m_distance(0),
m_cshape(800)
{
}


CanvasViewport::~CanvasViewport() {
}


CanvasViewport::CanvasViewport(const CanvasViewport& viewport):
m_center(viewport.m_center),
m_distance(viewport.m_distance),
m_sprites(viewport.m_sprites),
m_cshape(viewport.m_cshape)
{
}


/**
 * Returns the center coordinate of the screen (i.e., the coordinate that should
 * appear at the center of it).
 */
const Coord2d& CanvasViewport::getCenter() const {
	return m_center;
}


/**
 * Returns the sprites visible in this viewport.
 */
const CanvasViewport::sprites_t& CanvasViewport::getSprites() const {
	return m_sprites;
}


/**
 * Sets the center position of the viewport.
 * 
 * @param position
 */
void CanvasViewport::setCenter(const Coord2d& v) {
	m_center = v;
}


/**
 * Sets the z-axis value representing the distance the viewport has in relation to
 * the contained sprite managers' sprites.
 * 
 * @param zValue
 */
void CanvasViewport::setDistance(float zValue) {
	m_distance = zValue;
}


/**
 * Returns the z-axis value representing the distance the viewport has in relation
 * to the contained sprite managers' sprites.
 */
float CanvasViewport::getDistance() const {
	return m_distance;
}


/**
 * Adds an absolutely positioned sprite to the viewport.
 */
void CanvasViewport::addSprite(const Sprite& sprite) {

	// Don't add sprites that we can't see:
	if (sprite.getPosition().getX() > m_center.getX() - m_cshape.getRadius() && // [<]
		sprite.getPosition().getX() < m_center.getX() + m_cshape.getRadius() && // [>]
		sprite.getPosition().getY() > m_center.getY() - m_cshape.getRadius() && // [^]
		sprite.getPosition().getY() < m_center.getY() + m_cshape.getRadius()) { // [v]
		m_sprites.insert(sprite);
	}
}


/**
 * Clears the sprites contained by this viewport.
 */
void CanvasViewport::clearSprites() {
	m_sprites.clear();
}