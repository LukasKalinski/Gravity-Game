///////////////////////////////////////////////////////////
//  GameControlManager.cpp
//  Implementation of the Class GameControlManager
//  Created on:      28-mar-2008 10:26:45
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "GameControlManager.h"


/**
 * Constructs a game control manager for a specific game control.
 */
GameControlManager::GameControlManager(const GameControl& control):
m_control(control.clone()),
m_controlSwitch(false)
{
}


GameControlManager::~GameControlManager() {
	if (m_control) {
		delete m_control;
	}
}


GameControlManager::GameControlManager(const GameControlManager& cm):
m_control(cm.m_control->clone()),
m_controlSwitch(cm.m_controlSwitch)
{
}


/**
 * Returns a pointer to the contained switch. Will be called before making an
 * input listener listen for input, providing it with the switch that it will use
 * to switch according to input status.
 */
bool* GameControlManager::getSwitchPointer() {
	return &m_controlSwitch;
}


/**
 * Synchronizes the contained game control with the status of the m_switch member.
 */
void GameControlManager::refresh() {

	// # 1. If the control is activated and the
	// #    input switch is false, then the control
	// #    is deactivated;
	// # 2. If the control is deactivated and
	// #    the input switch is true, then the
	// #    control is activated;
	// # 3. If the control and the input switch
	// #    have the same status (i.e., both on or both off), then
	// #    nothing happens;

	if (m_control->isActivated() && !m_controlSwitch) {
		m_control->deactivate();
	} else if (!m_control->isActivated() && m_controlSwitch) {
		m_control->activate();
	}
}


/**
 * Deactivates contained control.
 */
void GameControlManager::reset() {
	m_control->deactivate();
	m_controlSwitch = false;
}