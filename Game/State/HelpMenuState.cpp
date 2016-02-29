///////////////////////////////////////////////////////////
//  HelpMenuState.cpp
//  Implementation of the Class HelpMenuState
//  Created on:      28-mar-2008 10:27:41
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "HelpMenuState.h"
#include "MainMenuState.h"


HelpMenuState::HelpMenuState():
MenuState(Menu("Help"))
{
}


HelpMenuState::~HelpMenuState() {

}


HelpMenuState::HelpMenuState(const HelpMenuState& state):
MenuState(state)
{
}


/**
 * Enters the help menu, specifying the game state from which it was entered.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void HelpMenuState::enterFrom(const GameState* fromState) {
	if (const MainMenuState * state = dynamic_cast<const MainMenuState*>(fromState)) {
		// currently no handling is required
	} else {
		throw std::exception("HelpMenuState.cpp: Unsupported game \
							 state to be entered from");
	}
}


/**
 * Throws an exception, as there is no valid fallback to the help menu state.
 * 
 * @param childState
 */
void HelpMenuState::handleFallback(const GameState* childState){

	//Throws illegal falback exception.


}


/**
 * Clones a help menu state, returning a pointer to the clone.
 */
HelpMenuState* HelpMenuState::clone() const {
	return new HelpMenuState(*this);
}