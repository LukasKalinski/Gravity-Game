///////////////////////////////////////////////////////////
//  MenuButton.cpp
//  Implementation of the Class MenuButton
//  Created on:      28-mar-2008 10:29:57
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "MenuButton.h"


/**
 * Constructs a button with name set to "UNDEFINED".
 */
MenuButton::MenuButton():
m_name("UNDEFINED")
{
}


/**
 * Constructs a button, specifying its name.
 */
MenuButton::MenuButton(const std::string& name):
m_name(name)
{
}


MenuButton::~MenuButton() {

	// Delete action pointers:
	actions_t::iterator actions_it = m_actions.begin();
	for ( ; actions_it != m_actions.end(); ++actions_it) {
		delete *actions_it;
		*actions_it = 0;
	}

	m_actions.clear();
}


MenuButton::MenuButton(const MenuButton& button) {
	
	// Copy action pointers and their targets:
	actions_t::const_iterator actions_it = button.m_actions.begin();
	for ( ; actions_it != button.m_actions.end(); ++actions_it) {
		addAction(**actions_it);
	}
}


/**
 * Adds an action to trigger when the menu button is pressed. First in first out.
 */
void MenuButton::addAction(const MenuAction& action) {
	m_actions.push_back(action.clone());
}


/**
 * Returns the button's name.
 */
const std::string& MenuButton::getName() const {
	return m_name;
}


/**
 * Triggers the contained action(s).
 */
void MenuButton::press() const {
	actions_t::const_iterator actions_it = m_actions.begin();
	for ( ; actions_it != m_actions.end(); ++actions_it) {
		(*actions_it)->trigger();
	}
}