///////////////////////////////////////////////////////////
//  MenuState.cpp
//  Implementation of the Class MenuState
//  Created on:      28-mar-2008 10:30:19
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#include "MenuState.h"


MenuState::MenuState(const Menu& menu):
m_menu(menu)
{
}


MenuState::~MenuState() {

}


MenuState::MenuState(const MenuState& state):
m_menu(state.m_menu)
{
}


/**
 * Returns the menu that is used in the menu state.
 */
Menu& MenuState::getMenu() {
	return m_menu;
}


/**
 * Sets the menu and registers menu controls for it in input manager. This
 * function must not be called more than once.
 */
void MenuState::initMenu(Menu menu) {

}


/**
 * Makes the menu state to self-update according to the status of the controller
 * module.
 */
void MenuState::tick() {

	//Polls controller and updates contained
	//menu if necessary.


}
