///////////////////////////////////////////////////////////
//  FinishStateControl.cpp
//  Implementation of the Class FinishStateControl
//  Created on:      28-mar-2008 10:26:08
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "FinishStateControl.h"
#include "GameState.h"


/**
 * Constructs a finish state control for the specified game state.
 */
FinishStateControl::FinishStateControl(GameState* state) {

}


FinishStateControl::~FinishStateControl() {

}


/**
 * Finishes the contained state.
 */
void FinishStateControl::activate() {
	m_state->finish();
	m_isActivated = true;
}


/**
 * Does nothing.
 */
void FinishStateControl::deactivate() {
	// do nothing
	m_isActivated = false;
}


/**
 * Clones the game control, returning a pointer to the clone.
 */
FinishStateControl* FinishStateControl::clone() const {
	return new FinishStateControl(*this);
}