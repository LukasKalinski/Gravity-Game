///////////////////////////////////////////////////////////
//  MenuControl.cpp
//  Implementation of the Class MenuControl
//  Created on:      28-mar-2008 10:30:11
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "MenuControl.h"


/**
 * Constructs a menu control, specifying the menu that it should control.
 */
MenuControl::MenuControl(Menu* menu):
m_menu(menu)
{
	if (!menu) {
		throw std::exception("MenuControl::Constructor: menu must not be 0");
	}
}


MenuControl::~MenuControl() {
}


/**
 * Does nothing, as we, by default, haven't turned anything on with activate() -
 * just performed a one-time action on the menu state's menu.
 */
void MenuControl::deactivate() {
	// Do nothing by default.
	m_isActivated = false;
}