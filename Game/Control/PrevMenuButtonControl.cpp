///////////////////////////////////////////////////////////
//  PrevMenuButtonControl.cpp
//  Implementation of the Class PrevMenuButtonControl
//  Created on:      28-mar-2008 10:32:21
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "PrevMenuButtonControl.h"


PrevMenuButtonControl::PrevMenuButtonControl(Menu* menu):
MenuControl(menu)
{
}


PrevMenuButtonControl::~PrevMenuButtonControl() {
}


/**
 * Starts a backward button iteration on the menu.
 */
void PrevMenuButtonControl::activate() {
	if (m_menu) {
		m_menu->switchBackwardButtonIteration(true);
	}
	m_isActivated = true;
}


/**
 * Stops a backward button iteration on the menu.
 */
void PrevMenuButtonControl::deactivate() {
	if (m_menu) {
		m_menu->switchBackwardButtonIteration(false);
	}
	m_isActivated = false;
}


/**
 * Clones the prev menu button control, returning a pointer to the clone.
 */
PrevMenuButtonControl* PrevMenuButtonControl::clone() const {
	return new PrevMenuButtonControl(*this);
}