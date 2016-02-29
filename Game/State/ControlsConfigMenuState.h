///////////////////////////////////////////////////////////
//  ControlsConfigMenuState.h
//  Implementation of the Class ControlsConfigMenuState
//  Created on:      28-mar-2008 10:24:48
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_9F5A48DE_B9FD_451b_AEAD_FD84B13149A0__INCLUDED_)
#define EA_9F5A48DE_B9FD_451b_AEAD_FD84B13149A0__INCLUDED_

#include "MenuState.h"

/**
 * The state of the controls configuration loop, i.e., where each control for a
 * single player is reconfigured on a step-by-step basis.
 */
class ControlsConfigMenuState : public MenuState
{

public:
	virtual ~ControlsConfigMenuState();
	ControlsConfigMenuState(const ControlsConfigMenuState& theControlsConfigMenuState);

	ControlsConfigMenuState();
	/**
	 * Enters the game state, and, when possible, lets it know what state it was
	 * entered from (i.e., its parent state). Takes a pointer because we need to be
	 * able to accept 0 as value (when entering main menu, for example).
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState = 0);
	virtual void handleFallback(const GameState& childState);
	virtual void tick();
	/**
	 * Clones a controls config menu state, returning a pointer to the clone.
	 */
	virtual ControlsConfigMenuState* clone() const;

};
#endif // !defined(EA_9F5A48DE_B9FD_451b_AEAD_FD84B13149A0__INCLUDED_)
