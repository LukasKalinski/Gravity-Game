///////////////////////////////////////////////////////////
//  ConfigKeyboardMapControl.cpp
//  Implementation of the Class ConfigKeyboardMapControl
//  Created on:      28-mar-2008 10:24:35
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ConfigKeyboardMapControl.h"


/**
 * Constructs a keyboard map reconfig control, specifying the alias for the
 * control that is to be reconfigured.
 * 
 * @param controlAlias    Must be one of the CTRL_* constants in this class.
 */
ConfigKeyboardMapControl::ConfigKeyboardMapControl(unsigned int controlAlias) {

}


ConfigKeyboardMapControl::~ConfigKeyboardMapControl() {

}


/**
 * Saves the new key by overwriting the old setting.
 */
void ConfigKeyboardMapControl::activate() {
	m_isActivated = true;
}


/**
 * Updates the state of this control to "done".
 */
void ConfigKeyboardMapControl::deactivate() {
	m_isActivated = false;
}


/**
 * Tells whether the reconfiguration has been done or not.
 */
bool ConfigKeyboardMapControl::isDone() {

	return false;
}


/**
 * Sets the new keyboard key for the control. Will be called by keyboard when a
 * key press is detected. Note, however, that this function will not actually save
 * the new key, it will just update the class' state. To save the key, activate()
 * must be called.
 */
void ConfigKeyboardMapControl::setNewKey(unsigned int key) {

}


/**
 * Clones the config keyboard map control, returning a pointer to the clone.
 */
ConfigKeyboardMapControl* ConfigKeyboardMapControl::clone() const {
	return new ConfigKeyboardMapControl(*this);
}