///////////////////////////////////////////////////////////
//  ControlsConfigMenuState.cpp
//  Implementation of the Class ControlsConfigMenuState
//  Created on:      28-mar-2008 10:24:52
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ControlsConfigMenuState.h"


ControlsConfigMenuState::ControlsConfigMenuState()
MenuState(Menu("Controls Config"))
{
}


ControlsConfigMenuState::~ControlsConfigMenuState()
{
}


ControlsConfigMenuState::ControlsConfigMenuState(const ControlsConfigMenuState& state):
MenuState(state)
{

}


/**
 * Enters the game state, and, when possible, lets it know what state it was
 * entered from (i.e., its parent state). Takes a pointer because we need to be
 * able to accept 0 as value (when entering main menu, for example).
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void ControlsConfigMenuState::enterFrom(const GameState* fromState) {

}


/**
 * Notifies this state about a fallback to it from a child state, providing the
 * child state instance. The child game state will be checked, and, when required,
 * proper action will be taken (for example, if the child game state was a pause
 * menu, it may have ordered a "quit", and we should realize it).
 */
void ControlsConfigMenuState::handleFallback(const GameState& childState) {

	//does nothing by default


}


/**
 * Makes the menu state to self-update according to the status of the controller
 * module.
 */
void ControlsConfigMenuState::tick() {

	//Polls controller and updates contained
	//menu if necessary.


}


/**
 * Clones a controls config menu state, returning a pointer to the clone.
 */
ControlsConfigMenuState* ControlsConfigMenuState::clone() const {

	return  NULL;
}
