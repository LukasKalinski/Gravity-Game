///////////////////////////////////////////////////////////
//  Menu.cpp
//  Implementation of the Class Menu
//  Created on:      28-mar-2008 10:29:47
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "Menu.h"


/**
 * Constructs a menu, specifying its title.
 */
Menu::Menu(std::string title):
m_title(title),
m_iterationCountdown(ITERATION_INIT_DELAY),
m_buttonIteration(NONE)
{
}


Menu::~Menu() {
}


Menu::Menu(const Menu& menu):
m_title(menu.m_title),
m_iterationCountdown(ITERATION_INIT_DELAY),
m_buttonIteration(NONE)
{

	// Copy menu buttons:
	buttons_t::const_iterator bit = menu.m_buttons.begin();
	for ( ; bit != menu.m_buttons.end(); ++bit) {
		addButton(*bit);
	}
}


/**
 * Adds a button to the menu. Insert order defines appearance order.
 */
void Menu::addButton(const MenuButton& button) {
	m_buttons.push_back(button);
}


/**
 * Returns a pointer to the currently selected button. The button is a const and
 * should remain that way; in order to press the selected button, use
 * pressSelectedButton().
 */
const MenuButton* Menu::getSelectedButton() const {
	return &(*m_selectedButton);
}


/**
 * Presses the currently selected button.
 */
void Menu::pressSelectedButton() {
	m_selectedButton->press();
}


/**
 * Goes one step forward in the button list, selecting the next button.
 */
void Menu::selectNextButton() {
	if (m_selectedButton != m_buttons.end()) {
		++m_selectedButton;
	} else {
		m_selectedButton = m_buttons.begin();
	}
}


/**
 * Goes one step backward in the button list, selecting the previous button.
 */
void Menu::selectPrevButton() {
	if(m_selectedButton != m_buttons.begin()) {
		--m_selectedButton;
	} else {
		m_selectedButton = m_buttons.end();
	}
}


/**
 * Does button iteration when on.
 */
void Menu::tick() {
	
	if (m_buttonIteration == NONE) {
		m_iterationCountdown = ITERATION_INIT_DELAY;
		return;
	}

	--m_iterationCountdown;

	if (m_iterationCountdown == 0) {
		
		if (m_buttonIteration == FORWARD) {
			selectNextButton();
		} else {
			selectPrevButton();
		}

		// Set new time delay to wait before going to next button:
		m_iterationCountdown = ITERATION_DELAY;
	}
}


/**
 * Toggles the backward iteration over the buttons in the menu.
 */
void Menu::switchBackwardButtonIteration(bool switchTo) {
	if (switchTo) {
		m_buttonIteration = BACKWARD;
	} else {
		m_buttonIteration = NONE;
	}
}


/**
 * Toggles the forward iteration over the buttons in the menu.
 */
void Menu::switchForwardButtonIteration(bool switchTo) {
	if (switchTo) {
		m_buttonIteration = FORWARD;
	} else {
		m_buttonIteration = NONE;
	}
}


/**
 * Returns the buttons constituting the menu.
 */
const Menu::buttons_t& Menu::getButtons() const {
	return m_buttons;
}