///////////////////////////////////////////////////////////
//  Canvas.cpp
//  Implementation of the Class Canvas
//  Created on:      06-Apr-2008 18:44:03
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "Canvas.h"

#include "Debug.h"

/**
 * Constructs a canvas, providing a pointer to the state that it will monitor, as
 * well as coordinates defining the canvas' area.
 * 
 * @param state
 * @param upperLeft
 * @param lowerRight
 */
Canvas::Canvas(GameState* state, const Coord2d& upperLeft, const Coord2d& lowerRight):
m_state(state),
m_upperLeft(upperLeft),
m_lowerRight(lowerRight),
m_initialized(false),
m_eventManager(state->getEventManager()),
m_valid(true)
{
	if (state->getEventManager() == 0) {
		throw std::exception("Canvas::Constructor: event \
							 manager must not be 0");
	}
}


Canvas::Canvas(const Canvas& c):
m_state(c.m_state),
m_upperLeft(c.m_upperLeft),
m_lowerRight(c.m_lowerRight),
m_initialized(false),
m_eventManager(c.m_eventManager),
m_valid(c.m_valid)
{
	Debug::instance()->printString("Canvas copied.");
	if (c.m_initialized) {
		throw std::exception("Canvas::Copy Constructor: \
							 copy of initialized canvas \
							 not allowed");
	}
}


Canvas::~Canvas() {

	// Delete sprite manager pointers:
	sprite_managers_t::iterator sm_it = m_spriteManagers.begin();
	for ( ; sm_it != m_spriteManagers.end(); ++sm_it) {
		delete *sm_it;
		*sm_it = 0;
	}
}


/**
 * Tells whether the canvas is valid an may receive ticks or not. Invalid means
 * that the canvas should be destroyed by its holder.
 */
bool Canvas::isValid() const {
	return m_valid;
}


/**
 * Returns the upper left coordinate of the canvas' area.
 */
const Coord2d& Canvas::getUpperLeft() const {
	return m_upperLeft;
}


/**
 * Returns the lower right coordinate of the canvas' area.
 */
const Coord2d& Canvas::getLowerRight() const {
	return m_lowerRight;
}


/**
 * Returns the sprite managers that are currently valid within the canvas. PLEASE
 * NOTE that there can be no guarantee about the sprite manager pointers being
 * valid after a call to tick().
 */
const Canvas::sprite_managers_t& Canvas::getSpriteManagers() const  {
	return m_spriteManagers;
}


/**
 * Makes the canvas invalid.
 */
void Canvas::makeInvalid() {
	m_valid = false;
}


/**
 * Checks whether the left game state is held by the canvas and invalidates the
 * canvas if that is the case.
 * 
 * @param state
 */
void Canvas::notifyGameStateLeave(const GameState* state) {
	if (m_state == state) {
		m_state = 0;
		makeInvalid();
	}
}
