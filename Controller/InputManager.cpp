///////////////////////////////////////////////////////////
//  InputManager.cpp
//  Implementation of the Class InputManager
//  Created on:      28-mar-2008 10:28:11
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#include "InputManager.h"
#include "KeyboardListener.h"


InputManager::player_control_alias_map_t InputManager::m_playerControlAliasMap;


/**
 * Loads static members with data.
 */
void InputManager::loadStaticData() {

	// Define primary player actions:
	m_playerControlAliasMap[LOCAL_PRIMARY][SHIP_THROTTLE] =
		KeyboardListener::GAMEPLAY_P1_SHIP_THROTTLE;

	m_playerControlAliasMap[LOCAL_PRIMARY][SHIP_LEFT] =
		KeyboardListener::GAMEPLAY_P1_SHIP_LEFT;

	m_playerControlAliasMap[LOCAL_PRIMARY][SHIP_RIGHT] =
		KeyboardListener::GAMEPLAY_P1_SHIP_RIGHT;

	m_playerControlAliasMap[LOCAL_PRIMARY][SHIP_FIRE_MISSILE] =
		KeyboardListener::GAMEPLAY_P1_SHIP_FIRE_MISSILE;

	m_playerControlAliasMap[LOCAL_PRIMARY][SHIP_FIRE_LASER] =
		KeyboardListener::GAMEPLAY_P1_SHIP_FIRE_LASER;


	// Define secondary player actions:
	m_playerControlAliasMap[LOCAL_SECONDARY][SHIP_THROTTLE] =
		KeyboardListener::GAMEPLAY_P2_SHIP_THROTTLE;

	m_playerControlAliasMap[LOCAL_SECONDARY][SHIP_LEFT] =
		KeyboardListener::GAMEPLAY_P2_SHIP_LEFT;

	m_playerControlAliasMap[LOCAL_SECONDARY][SHIP_RIGHT] =
		KeyboardListener::GAMEPLAY_P2_SHIP_RIGHT;

	m_playerControlAliasMap[LOCAL_SECONDARY][SHIP_FIRE_MISSILE] =
		KeyboardListener::GAMEPLAY_P2_SHIP_FIRE_MISSILE;

	m_playerControlAliasMap[LOCAL_SECONDARY][SHIP_FIRE_LASER] =
		KeyboardListener::GAMEPLAY_P2_SHIP_FIRE_LASER;
}


InputManager::InputManager():
m_listener(new KeyboardListener())
{
	m_controlManagers.reserve(100);
	if (m_playerControlAliasMap.empty()) {
		loadStaticData();
	}
}


InputManager::~InputManager() {
	if (m_listener) {
		delete m_listener;
	}

	// Delete control manager pointers:
	control_managers_t::iterator controlManager_it;
	for (controlManager_it = m_controlManagers.begin();
		 controlManager_it != m_controlManagers.end();
		 ++controlManager_it) {
		delete *controlManager_it;
	}
	m_controlManagers.clear();
}


InputManager::InputManager(const InputManager& im) {
	throw std::exception("InputManager.cpp: Copy constructor should not be called!");
}


/**
 * Loops through the game control managers vector, refreshing each one of these.
 */
void InputManager::refresh() {

	m_listener->refresh();

	control_managers_t::iterator controlManager_it = m_controlManagers.begin();
	for ( ; controlManager_it != m_controlManagers.end(); ++controlManager_it) {
		(*controlManager_it)->refresh();
	}
}


void InputManager::registerLocalControl(const NextMenuButtonControl& control) {

	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		KeyboardListener::MENU_BTN_NEXT,
		gcm->getSwitchPointer());
}


void InputManager::registerLocalControl(const PrevMenuButtonControl& control) {

	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		KeyboardListener::MENU_BTN_PREV,
		gcm->getSwitchPointer());
}


void InputManager::registerLocalControl(const PressMenuButtonControl& control) {

	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		KeyboardListener::MENU_BTN_PRESS,
		gcm->getSwitchPointer());
}


void InputManager::registerLocalControl(const PauseGameControl& control) {

	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		KeyboardListener::GAMEPLAY_PAUSE,
		gcm->getSwitchPointer());
}


void InputManager::registerLocalControl(const FinishStateControl& control) {

	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		KeyboardListener::FINISH_GAME_STATE,
		gcm->getSwitchPointer());
}


void InputManager::registerLocalControl(const ConfigKeyboardMapControl& control) {

	throw std::exception("InputManager.cpp: control not yet \
						 supported (delayed to next version)");
}


/**
 * Registers the ship throttle control for a local player, specifying the player
 * type (primary or secondary).
 */
void InputManager::registerLocalPlayerControl(const ShipThrottleControl& control,
											  player_t playerType) {

	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		m_playerControlAliasMap[playerType][SHIP_THROTTLE],
		gcm->getSwitchPointer());
}


/**
 * Registers a ship control for a local player, specifying the player type
 * (primary or secondary).
 */
void InputManager::registerLocalPlayerControl(const ShipLeftControl& control,
											  player_t playerType) {
	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		m_playerControlAliasMap[playerType][SHIP_LEFT],
		gcm->getSwitchPointer());
}


/**
 * Registers a ship control for a local player, specifying the player type
 * (primary or secondary).
 */
void InputManager::registerLocalPlayerControl(const ShipRightControl& control,
											  player_t playerType) {
	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		m_playerControlAliasMap[playerType][SHIP_RIGHT],
		gcm->getSwitchPointer());
}


/**
 * Registers a ship control for a local player, specifying the player type
 * (primary or secondary).
 */
void InputManager::registerLocalPlayerControl(const ShipLaserFireControl& control,
											  player_t playerType) {							
	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		m_playerControlAliasMap[playerType][SHIP_FIRE_LASER],
		gcm->getSwitchPointer());

}


/**
 * Registers a ship control for a local player, specifying the player type
 * (primary or secondary).
 */
void InputManager::registerLocalPlayerControl(const ShipMissileFireControl& control,
											  player_t playerType) {
	
	GameControlManager * gcm = new GameControlManager(control);
	m_controlManagers.push_back(gcm);
	m_listener->enableListen(
		m_playerControlAliasMap[playerType][SHIP_FIRE_MISSILE],
		gcm->getSwitchPointer());
}


/**
 * Deactivates all currently active controls. Useful when switching to a child
 * game state and want to avoid having controls left activated when falling back
 * again.
 */
void InputManager::reset() {

	//Loops through the game control managers
	//vector, setting their control switch to
	//false and refreshing them.
	control_managers_t::iterator controlManager_it = m_controlManagers.begin();
	for ( ; controlManager_it != m_controlManagers.end(); ++controlManager_it) {
		(*controlManager_it)->reset();
	}
}
