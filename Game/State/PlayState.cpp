///////////////////////////////////////////////////////////
//  PlayState.cpp
//  Implementation of the Class PlayState
//  Created on:      28-mar-2008 10:32:07
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#include "PlayState.h"
#include "MapChoiceMenuState.h"

PlayState::PlayState():
m_awaitsFinish(false)
{
}


PlayState::~PlayState() {
}


PlayState::PlayState(const PlayState& state) {

}


/**
 * Forwards call to parent.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void PlayState::enterFrom(const GameState* fromState) {
	GameState::enterFrom(fromState);
}


/**
 * Returns the play state's game engine.
 */
Engine& PlayState::getEngine() {
	return m_engine;
}


/**
 * Notifies this state about a fallback to it from a child state, providing the
 * child state instance. The child game state will be checked, and, when required,
 * proper action will be taken (for example, if the child game state was a pause
 * menu, it may have ordered a "quit", and we should realize it).
 * 
 * @param childState
 */
void PlayState::handleFallback(const GameState* childState){

	//Throws illegal fallback exception.

}


/**
 * Tells whether the play state is awaiting finish on game over, i.e., the "press
 * any key to continue" stuff, or not.
 */
bool PlayState::isAwaitingFinish() {

	return false;
}


/**
 * Handles fallback from a pause menu state.
 * 
 * @param childState
 */
void PlayState::handleFallback(const PauseMenuState* childState){

}