///////////////////////////////////////////////////////////
//  TwoPlayersPlayState.h
//  Implementation of the Class TwoPlayersPlayState
//  Created on:      28-mar-2008 10:35:36
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_F90B32EF_F5BC_4c90_A341_57087A512CD4__INCLUDED_)
#define EA_F90B32EF_F5BC_4c90_A341_57087A512CD4__INCLUDED_

#include "PlayState.h"
#include "MapChoiceMenuState.h"
#include "PauseMenuState.h"

/**
 * Responsible for starting a two player game and keeping it going until game over
 * rules are met.
 */
class TwoPlayersPlayState : public PlayState
{

public:
	TwoPlayersPlayState();
	virtual ~TwoPlayersPlayState();
	TwoPlayersPlayState(const TwoPlayersPlayState& theTwoPlayersPlayState);

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
	 * Initializes the two players play state, fetching its world instance from the
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
	 * Clones a two players play state, returning a pointer to the clone.
	 */
	virtual TwoPlayersPlayState* clone() const;

private:

	void triggerGameOver();
	
	/**
	 * Handles fallback from the pause menu state, checking whether it ordered a game
	 * quit or not.
	 * 
	 * @param pauseState
	 */
	virtual void handleFallback(const PauseMenuState* pauseState);

};
#endif // !defined(EA_F90B32EF_F5BC_4c90_A341_57087A512CD4__INCLUDED_)
