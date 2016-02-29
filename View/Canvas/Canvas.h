///////////////////////////////////////////////////////////
//  Canvas.h
//  Implementation of the Class Canvas
//  Created on:      06-Apr-2008 18:44:02
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_32F350EB_A167_479b_8398_9E0CE0F2E95A__INCLUDED_)
#define EA_32F350EB_A167_479b_8398_9E0CE0F2E95A__INCLUDED_

#include <set>
#include <vector>

#include "Coord2d.h"
#include "GameState.h"
#include "SpriteManager.h"
#include "SpawnPointSpriteManager.h"

/**
 * Represents the whole drawable area of a game state, for which it holds and
 * manages related sprite managers. However, in order to get something to draw,
 * the canvas' viewport(s) should be used.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 06-Apr-2008 21:49:26
 */
class Canvas
{

public:
	
	typedef std::set<SpriteManager*> sprite_managers_t;
	typedef const std::set<SpriteManager*> const_sprite_managers_t;

	/**
	 * Constructs a canvas, providing a pointer to the state that it will monitor, as
	 * well as coordinates defining the canvas' area.
	 * 
	 * @param state
	 * @param upperLeft
	 * @param lowerRight
	 */
	Canvas(GameState* state, const Coord2d& upperLeft, const Coord2d& lowerRight);

	Canvas(const Canvas& c);
	virtual ~Canvas();

	/**
	 * Tells whether the canvas is valid an may receive ticks or not. Invalid means
	 * that the canvas should be destroyed by its holder.
	 */
	bool isValid() const;

	/**
	 * Returns the upper left coordinate of the canvas' area.
	 */
	const Coord2d& getUpperLeft() const;

	/**
	 * Returns the lower right coordinate of the canvas' area.
	 */
	const Coord2d& getLowerRight() const;

	/**
	 * Checks whether the left game state is held by the canvas and invalidates the
	 * canvas if that is the case.
	 * 
	 * @param state
	 */
	void notifyGameStateLeave(const GameState* state);

	/**
	 * Updates the sprite managers of the canvas.
	 */
	virtual void update() = 0;

	/**
	 * Initiates the canvas.
	 */
	virtual void init() =0;

protected:

	/**
	 * The game event manager to use.
	 */
	GameEventManager *m_eventManager;

	/**
	 * The sprite managers representing visual elements in the game state.
	 */
	sprite_managers_t m_spriteManagers;

	/**
	 * Tells whether the canvas has been initialized or not.
	 */
	bool m_initialized;

	/**
	 * Makes the canvas invalid.
	 */
	void makeInvalid();

	/**
	 * Returns the sprite managers that are currently valid within the canvas. PLEASE
	 * NOTE that there can be no guarantee about the sprite manager pointers being
	 * valid after a call to tick().
	 */
	const sprite_managers_t& getSpriteManagers() const;

private:

	/**
	 * Tells whether the canvas is valid an may receive ticks or not. Invalid means
	 * that the canvas should be destroyed.
	 */
	bool m_valid;

	/**
	 * The upper left coordinate of the canvas' area.
	 */
	Coord2d m_upperLeft;

	/**
	 * The lower right coordinate of the canvas' area.
	 */
	Coord2d m_lowerRight;

	/**
	 * Keeps track of what state we are monitoring, and if it is left, then we have to
	 * reset our pointer to it.
	 */
	GameState *m_state;

};
#endif // !defined(EA_32F350EB_A167_479b_8398_9E0CE0F2E95A__INCLUDED_)
