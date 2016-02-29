///////////////////////////////////////////////////////////
//  MainMenuState.h
//  Implementation of the Class MainMenuState
//  Created on:      28-mar-2008 10:29:18
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_2333D65F_3D68_4145_B7A0_C8CEAC57F297__INCLUDED_)
#define EA_2333D65F_3D68_4145_B7A0_C8CEAC57F297__INCLUDED_

#include "MenuState.h"

class MainMenuState : public MenuState
{

public:
	MainMenuState();
	virtual ~MainMenuState();
	MainMenuState(const MainMenuState& theMainMenuState);

	/**
	 * Enters the main menu state, only accepting fromState == 0. If fromState isn't
	 * zero, then an exception will be thrown.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState = 0);

	/**
	 * Clones a main menu state, returning a pointer to the clone.
	 */
	virtual MainMenuState* clone() const;

private:

	void init();
};
#endif // !defined(EA_2333D65F_3D68_4145_B7A0_C8CEAC57F297__INCLUDED_)
