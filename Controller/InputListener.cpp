///////////////////////////////////////////////////////////
//  InputListener.cpp
//  Implementation of the Class InputListener
//  Created on:      28-mar-2008 10:28:03
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "InputListener.h"


InputListener::InputListener() {

}


InputListener::~InputListener() {

}


InputListener::InputListener(const InputListener& listener) {
	throw std::exception("InputListener.cpp: Cannot happen. Copy constructor called!");
}


/**
 * Enables listening for input associated with a control, by specifying the alias
 * for that control, and to manipulate the provided boolean pointer depending on
 * whether the input says that the control should be "switched on"=true or
 * "switched off"=false.
 */
void InputListener::enableListen(unsigned short controlAlias, bool* controlSwitch) {
	m_switches[controlAlias] = controlSwitch;
}


/**
 * Sets the boolean pointer associated with the specified control alias to false.
 */
void InputListener::switchOff(unsigned short controlAlias) {
	
	std::map<unsigned short, bool*>::iterator it;
	it = m_switches.find(controlAlias);
	if (it != m_switches.end()) {
		*(it->second) = false;
	}
}


/**
 * Sets the boolean pointer associated with the specified control alias to true.
 */
void InputListener::switchOn(unsigned short controlAlias) {

	std::map<unsigned short, bool*>::iterator it;
	it = m_switches.find(controlAlias);
	if (it != m_switches.end()) {
		*(it->second) = true;
	}
}