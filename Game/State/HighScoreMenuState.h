///////////////////////////////////////////////////////////
//  HighScoreMenuState.h
//  Implementation of the Class HighScoreMenuState
//  Created on:      28-mar-2008 10:27:44
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_69CA75BB_8889_487a_8253_7F724CC00E01__INCLUDED_)
#define EA_69CA75BB_8889_487a_8253_7F724CC00E01__INCLUDED_

#include "MenuState.h"
#include "MainMenuState.h"
#include "SinglePlayerPlayState.h"

class HighScoreMenuState : public MenuState
{

public:
	HighScoreMenuState();
	virtual ~HighScoreMenuState();
	HighScoreMenuState(const HighScoreMenuState& theHighScoreMenuState);

	/**
	 * Routes to appropriate function using RTTI.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState = 0);

	/**
	 * Enters the high score menu state, specifying the main menu state from which it
	 * was entered.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const MainMenuState* fromState = 0);

	/**
	 * Enters the high score menu state, specifying the single player play state from
	 * which it was entered.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const SinglePlayerPlayState* fromState = 0);

	/**
	 * Throws illegal fallback exception, as this state is a leaf state.
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const GameState* childState);

	/**
	 * Clones a high score menu state, returning a pointer to the clone.
	 */
	HighScoreMenuState* clone() const;

};
#endif // !defined(EA_69CA75BB_8889_487a_8253_7F724CC00E01__INCLUDED_)
