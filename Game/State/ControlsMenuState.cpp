///////////////////////////////////////////////////////////
//  ControlsMenuState.cpp
//  Implementation of the Class ControlsMenuState
//  Created on:      28-mar-2008 10:24:59
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ControlsMenuState.h"


ControlsMenuState::ControlsMenuState():
MenuState(Menu("Current Controls"))
{
}


ControlsMenuState::~ControlsMenuState() {

}


ControlsMenuState::ControlsMenuState(const ControlsMenuState& state):
MenuState(state)
{
}


/**
 * Enters the game controls configuration state from any other state (except for
 * this one, of course).
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void ControlsMenuState::enterFrom(const GameState* fromState) {

}


/**
 * Handles fallback from game controls config menu state. Other states won't be
 * supported to fallback from.
 * 
 * @param childState
 */
void ControlsMenuState::handleFallback(const ControlsConfigMenuState* childState){

	//Does nothing, except for restricting
	//states to accept fallback from.


}


/**
 * Notifies this state about a fallback to it from a child state, providing the
 * child state instance. The child game state will be checked, and, when required,
 * proper action will be taken (for example, if the child game state was a pause
 * menu, it may have ordered a "quit", and we should realize it).
 * 
 * @param childState
 */
void ControlsMenuState::handleFallback(const GameState* childState){

	//does nothing by default


}


/**
 * Clones a controls menu state, returning a pointer to the clone.
 */
ControlsMenuState* ControlsMenuState::clone() const {
	return new ControlsMenuState(*this);
}