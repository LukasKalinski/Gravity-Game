///////////////////////////////////////////////////////////
//  GameState.h
//  Implementation of the Class GameState
//  Created on:      28-mar-2008 10:27:12
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_EC866FE4_BAB3_4ec4_9022_AD4BB26797E9__INCLUDED_)
#define EA_EC866FE4_BAB3_4ec4_9022_AD4BB26797E9__INCLUDED_

#include "Tickable.h"
#include "GameEventManager.h"
#include "InputManager.h"

/**
 * Represents an abstract state that the game may find itself in.
 */
class GameState : public Tickable
{

public:

	GameState();
	virtual ~GameState();
	GameState(const GameState& state);

	void finish();
	GameEventManager* getEventManager();

	/**
	 * Makes sure that the game state hasn't been entered before and 
	 * sets its status to initialized.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState = 0);

	/**
	 * Notifies this state about a fallback to it from a child state, providing the
	 * child state instance. The child game state will be checked, and, when required,
	 * proper action will be taken (for example, if the child game state was a pause
	 * menu, it may have ordered a "quit", and we should realize it).
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const GameState* childState);

	bool isValid() const;
	virtual void tick();

	/**
	 * Clones a game state, returning a pointer to the clone.
	 */
	virtual GameState* clone() const = 0;

protected:

	/**
	 * The event manager used and provided by the game engine.
	 */
	GameEventManager m_eventManager;

	/**
	 * The input manager to use.
	 */
	InputManager m_inputManager;

	/**
	 * Tells whether the game state is initialized or not.
	 */
	bool m_initialized;

private:

	/**
	 * Tells whether the game state is supposed to be run (true) or to be finished
	 * (false).
	 */
	bool m_valid;

};
#endif // !defined(EA_EC866FE4_BAB3_4ec4_9022_AD4BB26797E9__INCLUDED_)
