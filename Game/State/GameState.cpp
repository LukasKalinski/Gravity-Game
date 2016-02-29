///////////////////////////////////////////////////////////
//  GameState.cpp
//  Implementation of the Class GameState
//  Created on:      28-mar-2008 10:27:23
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "GameState.h"


GameState::GameState():
m_initialized(false),
m_valid(true)
{
}


GameState::~GameState() {

}


GameState::GameState(const GameState& state):
m_valid(state.m_valid),
m_initialized(state.m_initialized)
{
}


/**
 * Sets m_valid to false, causing the game state to finish when isValid() is
 * checked by Game.
 */
void GameState::finish() {
	m_valid = false;
}


/**
 * Provides the event manager for the game state.
 */
GameEventManager* GameState::getEventManager() {
	return &m_eventManager;
}


/**
 * Makes sure that the game state hasn't been entered before and 
 * sets its status to initialized.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void GameState::enterFrom(const GameState* fromState) {

	if (m_initialized) {
		throw std::exception("PlayState::enterFrom(): state has \
							 already been entered");
	}

	m_initialized = true;
}

/**
 * Notifies this state about a fallback to it from a child state, providing the
 * child state instance. The child game state will be checked, and, when required,
 * proper action will be taken (for example, if the child game state was a pause
 * menu, it may have ordered a "quit", and we should realize it).
 * 
 * @param childState
 */
void GameState::handleFallback(const GameState* childState){

	//does nothing by default

}


/**
 * Tells whether the game state is supposed to be run (true) or to be finished
 * (false).
 */
bool GameState::isValid() const {
	return m_valid;
}


/**
 * Notifies the object about that the time is being incremented with one time unit.
 */
void GameState::tick() {

}