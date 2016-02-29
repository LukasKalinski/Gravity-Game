///////////////////////////////////////////////////////////
//  SinglePlayerPlayState.h
//  Implementation of the Class SinglePlayerPlayState
//  Created on:      28-mar-2008 10:34:12
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_00F95990_0F9F_43a2_8E1B_F4F85A3BBD54__INCLUDED_)
#define EA_00F95990_0F9F_43a2_8E1B_F4F85A3BBD54__INCLUDED_

#include "PlayState.h"
#include "MapChoiceMenuState.h"
class HighScoreMenuState;
class PauseMenuState;


/**
 * Responsible for starting a single player game and keeping it going until game
 * over rules are met, resulting in entering the high score menu.
 */
class SinglePlayerPlayState : public PlayState
{

public:

	using PlayState::enterFrom;

	SinglePlayerPlayState();
	virtual ~SinglePlayerPlayState();
	SinglePlayerPlayState(const SinglePlayerPlayState& state);

	/**
	 * Tries to convert the game state to a MapChoiceMenuState and, if succeeded,
	 * forwards call to the corresponding function, otherwise an exception will be
	 * thrown.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState = 0);

	/**
	 * Initializes the single player play state, fetching its world instance from the
	 * provided map choice menu state.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const MapChoiceMenuState* fromState = 0);

	/**
	 * Notifies this state about a fallback to it from a child state, providing the
	 * child state instance. The child game state will be checked, and, when required,
	 * proper action will be taken (for example, if the child game state was a pause
	 * menu, it may have ordered a "quit", and we should realize it).
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const GameState* childState);

	virtual void tick();

	/**
	 * Clones a single player play state, returning a pointer to the clone.
	 */
	virtual SinglePlayerPlayState* clone() const;

private:

	void triggerGameOver();

	/**
	 * Handles fallback from the pause menu state, checking whether it ordered a game
	 * quit or not.
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const PauseMenuState* childState);

	/**
	 * Handles fallback from a high score menu. The handling will always result in
	 * this state being finished, as a preceding enter into the high score menu state
	 * from *this* state, was a result of a game over.
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const HighScoreMenuState* childState);

};
#endif // !defined(EA_00F95990_0F9F_43a2_8E1B_F4F85A3BBD54__INCLUDED_)
