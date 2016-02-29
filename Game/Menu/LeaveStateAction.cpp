///////////////////////////////////////////////////////////
//  LeaveStateAction.cpp
//  Implementation of the Class LeaveStateAction
//  Created on:      28-mar-2008 10:29:14
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "LeaveStateAction.h"


/**
 * Constructs a leave game state action.
 */
LeaveStateAction::LeaveStateAction() {

}


LeaveStateAction::~LeaveStateAction() {

}


LeaveStateAction::LeaveStateAction(const LeaveStateAction& action) {

}


/**
 * Finishes the current game state.
 */
void LeaveStateAction::trigger() {

	//Accesses the current state through the
	//Game singleton and calls its finish()
	//function.
}


/**
 * Clones a leave state action, returning a pointer to the created clone.
 */
LeaveStateAction* LeaveStateAction::clone() const {
	return new LeaveStateAction(*this);
}