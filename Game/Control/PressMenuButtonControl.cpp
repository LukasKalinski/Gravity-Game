///////////////////////////////////////////////////////////
//  PressMenuButtonControl.cpp
//  Implementation of the Class PressMenuButtonControl
//  Created on:      28-mar-2008 10:32:14
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "PressMenuButtonControl.h"


PressMenuButtonControl::PressMenuButtonControl(Menu* menu):
MenuControl(menu) {
}


PressMenuButtonControl::~PressMenuButtonControl() {
}


/**
 * Presses the currently selected button in the current menu state's menu.
 */
void PressMenuButtonControl::activate() {
	if (m_menu) {
		m_menu->pressSelectedButton();
	}
	m_isActivated = true;
}


/**
 * Clones the press menu button control, returning a pointer to the clone.
 */
PressMenuButtonControl* PressMenuButtonControl::clone() const {
	return new PressMenuButtonControl(*this);
}