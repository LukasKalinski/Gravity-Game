///////////////////////////////////////////////////////////
//  HighScoreMenuState.cpp
//  Implementation of the Class HighScoreMenuState
//  Created on:      28-mar-2008 10:27:48
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "HighScoreMenuState.h"


HighScoreMenuState::HighScoreMenuState():
MenuState(Menu("High Scores"))
{
}


HighScoreMenuState::~HighScoreMenuState() {

}


HighScoreMenuState::HighScoreMenuState(const HighScoreMenuState& state):
MenuState(state)
{
}


/**
 * Routes to appropriate function using RTTI.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void HighScoreMenuState::enterFrom(const GameState* fromState) {
	if (const MainMenuState * state =
		dynamic_cast<const MainMenuState*>(fromState)) {
		enterFrom(state);
	} else if (const SinglePlayerPlayState * state =
		dynamic_cast<const SinglePlayerPlayState*>(fromState)) {
		enterFrom(state);
	} else {
		throw std::exception("HighScoreMenuState.cpp: Unsupported game \
							 state to be entered from");
	}
}


/**
 * Enters the high score menu state, specifying the main menu state from which it
 * was entered.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void HighScoreMenuState::enterFrom(const MainMenuState* fromState) {

}


/**
 * Enters the high score menu state, specifying the single player play state from
 * which it was entered.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void HighScoreMenuState::enterFrom(const SinglePlayerPlayState* fromState) {

}


/**
 * Throws illegal fallback exception, as this state is a leaf state.
 * 
 * @param childState
 */
void HighScoreMenuState::handleFallback(const GameState* childState){
	throw std::exception("HighScoreMenuState.cpp: fallback from illegal child state");
}


/**
 * Clones a high score menu state, returning a pointer to the clone.
 */
HighScoreMenuState* HighScoreMenuState::clone() const {
	return new HighScoreMenuState(*this);
}