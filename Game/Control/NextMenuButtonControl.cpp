///////////////////////////////////////////////////////////
//  NextMenuButtonControl.cpp
//  Implementation of the Class NextMenuButtonControl
//  Created on:      28-mar-2008 10:30:54
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "NextMenuButtonControl.h"


NextMenuButtonControl::NextMenuButtonControl(Menu* menu):
MenuControl(menu)
{
}


NextMenuButtonControl::~NextMenuButtonControl() {
}


/**
 * Starts a forward button iteration on the menu.
 */
void NextMenuButtonControl::activate() {
	if (m_menu) {
		m_menu->switchBackwardButtonIteration(true);
	}
	m_isActivated = true;
}


/**
 * Stops a forward button iteration on the menu.
 */
void NextMenuButtonControl::deactivate() {
	if (m_menu) {
		m_menu->switchBackwardButtonIteration(false);
	}
	m_isActivated = false;
}


/**
 * Clones the next menu button control, returning a pointer to the clone.
 */
NextMenuButtonControl* NextMenuButtonControl::clone() const {
	return new NextMenuButtonControl(*this);
}