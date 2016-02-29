///////////////////////////////////////////////////////////
//  PauseMenuState.cpp
//  Implementation of the Class PauseMenuState
//  Created on:      28-mar-2008 10:31:23
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "PauseMenuState.h"


PauseMenuState::PauseMenuState():
MenuState(Menu("Game Paused"))
{
}


PauseMenuState::~PauseMenuState() {

}


PauseMenuState::PauseMenuState(const PauseMenuState& state):
MenuState(state)
{
}


/**
 * Clones a pause menu state, returning a pointer to the clone.
 */
PauseMenuState* PauseMenuState::clone() const {
	return new PauseMenuState(*this);
}


/**
 * Tells whether the pause menu orders its parent play state quit or not.
 */
bool PauseMenuState::doQuitGame() const {
	return m_quitGame;
}


/**
 * Routes the enter handling depending on type obtained through RTTI.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void PauseMenuState::enterFrom(const GameState* fromState) {
	if (const PlayState * state = dynamic_cast<const PlayState*>(fromState)) {
		enterFrom(state);
	} else {
		throw std::exception("PauseMenuState.cpp: Unsupported game \
							 state to be entered from");
	}
}


/**
 * Enters the pause menu state, specifying the play state from which it is being
 * entered. Does nothing, except for setting up restrictions for what states to
 * accept enter from.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void PauseMenuState::enterFrom(const PlayState* fromState) {
	
}


/**
 * Throws illegal fallback, as this function overload catches all unsupported
 * child states. To support fallback from a state, a corresponding function
 * overload can be added later.
 * 
 * @param childState
 */
void PauseMenuState::handleFallback(const GameState* childState) {
	throw std::exception("PauseMenuState.cpp: fallback from illegal child state");
}


/**
 * Constructs a quit action for the pause menu state's menu "quit" button.
 */
PauseMenuState::LeavePauseMenuStateAction::LeavePauseMenuStateAction(
	PauseMenuState* pauseState) {

}


PauseMenuState::LeavePauseMenuStateAction::~LeavePauseMenuStateAction() {

}


PauseMenuState::LeavePauseMenuStateAction::LeavePauseMenuStateAction(
	const LeavePauseMenuStateAction& action) {

}


/**
 * Finishes the current game state.
 */
void PauseMenuState::LeavePauseMenuStateAction::trigger() {

	//Updates pause menu state, setting
	//m_quitGame=true and calls
	//LeaveStateAction::trigger().


}