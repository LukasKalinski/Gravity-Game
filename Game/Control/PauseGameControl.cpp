///////////////////////////////////////////////////////////
//  PauseGameControl.cpp
//  Implementation of the Class PauseGameControl
//  Created on:      28-mar-2008 10:31:10
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "PauseGameControl.h"


PauseGameControl::PauseGameControl() {

}


PauseGameControl::~PauseGameControl() {

}


/**
 * Triggers a transition from a game play state to the pause menu state.
 */
void PauseGameControl::activate() {
	// FIXME
	m_isActivated = true;
}


/**
 * No function (void).
 */
void PauseGameControl::deactivate() {
	// FIXME
	m_isActivated = false;
}


/**
 * Clones the pause game control, returning a pointer to the clone.
 */
PauseGameControl* PauseGameControl::clone() const {
	return new PauseGameControl(*this);
}