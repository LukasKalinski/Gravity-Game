///////////////////////////////////////////////////////////
//  ControlsMenuState.h
//  Implementation of the Class ControlsMenuState
//  Created on:      28-mar-2008 10:24:56
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_AE6263F0_50A2_40f0_9F43_06C3E0AB3D96__INCLUDED_)
#define EA_AE6263F0_50A2_40f0_9F43_06C3E0AB3D96__INCLUDED_

#include "MenuState.h"
#include "ControlsConfigMenuState.h"

class ControlsMenuState : public MenuState
{

public:

	ControlsMenuState();
	virtual ~ControlsMenuState();
	ControlsMenuState(const ControlsMenuState& state);

	/**
	 * Enters the game controls configuration state from any other state (except for
	 * this one, of course).
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

	/**
	 * Clones a controls menu state, returning a pointer to the clone.
	 */
	ControlsMenuState* clone() const;


private:

	/**
	 * Handles fallback from game controls config menu state. Other states won't be
	 * supported to fallback from.
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const ControlsConfigMenuState* childState);
};
#endif // !defined(EA_AE6263F0_50A2_40f0_9F43_06C3E0AB3D96__INCLUDED_)
