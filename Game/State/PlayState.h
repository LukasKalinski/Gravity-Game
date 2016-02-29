///////////////////////////////////////////////////////////
//  PlayState.h
//  Implementation of the Class PlayState
//  Created on:      28-mar-2008 10:32:03
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#if !defined(EA_D5B53BF0_1DC2_409b_BC51_9B8CB244C02C__INCLUDED_)
#define EA_D5B53BF0_1DC2_409b_BC51_9B8CB244C02C__INCLUDED_

#include "GameState.h"
#include "Engine.h"

class PauseMenuState;
class MapChoiceMenuState;

/**
 * The game state to be in when a game session is active. Responsible for setting
 * up and managing the game engine.
 */
class PlayState : public GameState
{

public:

	PlayState();
	virtual ~PlayState();
	PlayState(const PlayState& state);

	/**
	 * Forwards call to parent.
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

	Engine& getEngine();
	bool isAwaitingFinish();

	/**
	 * Clones a play state, returning a pointer to the clone.
	 */
	virtual PlayState* clone() const = 0;

protected:

	/**
	 * Tells whether the play state is awaiting finish (i.e., "press any key to
	 * continue" when game was over) or not.
	 */
	bool m_awaitsFinish;

	/**
	 * The game engine used by the play state.
	 */
	Engine m_engine;

private:

	/**
	 * Handles fallback from a pause menu state.
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const PauseMenuState* childState);
};
#endif // !defined(EA_D5B53BF0_1DC2_409b_BC51_9B8CB244C02C__INCLUDED_)
