///////////////////////////////////////////////////////////
//  PauseMenuState.h
//  Implementation of the Class PauseMenuState
//  Created on:      28-mar-2008 10:31:16
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_6B6BB2BE_18F4_47d0_99D9_88624A3FBB3D__INCLUDED_)
#define EA_6B6BB2BE_18F4_47d0_99D9_88624A3FBB3D__INCLUDED_

#include "LeaveStateAction.h"
#include "MenuState.h"
#include "PlayState.h"

class PauseMenuState : public MenuState
{

public:

	/**
	 * Responsible for handling a press on the pause menu's "Quit Game" button.
	 */
	class LeavePauseMenuStateAction : public LeaveStateAction
	{

	public:

		LeavePauseMenuStateAction(PauseMenuState* pauseState);
		virtual ~LeavePauseMenuStateAction();
		LeavePauseMenuStateAction(const LeavePauseMenuStateAction& action);

		virtual void trigger();

	};

	PauseMenuState();
	virtual ~PauseMenuState();
	PauseMenuState(const PauseMenuState& state);

	bool doQuitGame() const;

	/**
	 * Routes the enter handling depending on type obtained through RTTI.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState);

	/**
	 * Throws illegal fallback, as this function overload catches all unsupported
	 * child states. To support fallback from a state, a corresponding function
	 * overload can be added later.
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const GameState* childState);

	/**
	 * Clones a pause menu state, returning a pointer to the clone.
	 */
	virtual PauseMenuState* clone() const;

	/**
	 * Enters the pause menu state, specifying the play state from which it is being
	 * entered. Does nothing, except for setting up restrictions for what states to
	 * accept enter from.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const PlayState* fromState = 0);

private:

	/**
	 * Tells whether the pause menu button "quit game" was pressed or not.
	 */
	bool m_quitGame;

};
#endif // !defined(EA_6B6BB2BE_18F4_47d0_99D9_88624A3FBB3D__INCLUDED_)
