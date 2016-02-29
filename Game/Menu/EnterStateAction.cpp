///////////////////////////////////////////////////////////
//  EnterStateAction.cpp
//  Implementation of the Class EnterStateAction
//  Created on:      28-mar-2008 10:25:48
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "EnterStateAction.h"
#include "Game.h"


/**
 * Constructs an enter game state action, specifying what game
 * state to enter.
 */
EnterStateAction::EnterStateAction(const GameState& state):
m_state(state.clone())
{
}


EnterStateAction::~EnterStateAction() {
	delete m_state;
}

/**
 * Copies pointed state template from target.
 */
EnterStateAction::EnterStateAction(const EnterStateAction& action):
m_state(action.m_state->clone())
{
}


/**
 * Triggers a transition from current game state to a new game state.
 */
void EnterStateAction::trigger() {

	Game::instance()->enterState(*m_state);
}


/**
 * Clones an enter state action, returning a pointer to the created clone.
 */
EnterStateAction* EnterStateAction::clone() const {
	return new EnterStateAction(*this);
}