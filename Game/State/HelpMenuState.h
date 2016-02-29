///////////////////////////////////////////////////////////
//  HelpMenuState.h
//  Implementation of the Class HelpMenuState
//  Created on:      28-mar-2008 10:27:38
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_42B9AED2_45D8_439f_93FA_3DB044DFD16B__INCLUDED_)
#define EA_42B9AED2_45D8_439f_93FA_3DB044DFD16B__INCLUDED_

#include "MenuState.h"

class HelpMenuState : public MenuState
{

public:

	HelpMenuState();
	virtual ~HelpMenuState();
	HelpMenuState(const HelpMenuState& theHelpMenuState);

	/**
	 * Enters the help menu, specifying the game state from which it was entered.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState = 0);

	/**
	 * Throws an exception, as there is no valid fallback to the help menu state.
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const GameState* childState);

	/**
	 * Clones a help menu state, returning a pointer to the clone.
	 */
	virtual HelpMenuState* clone() const;

};
#endif // !defined(EA_42B9AED2_45D8_439f_93FA_3DB044DFD16B__INCLUDED_)
