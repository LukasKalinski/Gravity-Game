///////////////////////////////////////////////////////////
//  TwoPlayersPlayState.cpp
//  Implementation of the Class TwoPlayersPlayState
//  Created on:      28-mar-2008 10:35:40
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "TwoPlayersPlayState.h"
#include "PauseMenuState.h"
#include "MapChoiceMenuState.h"


TwoPlayersPlayState::TwoPlayersPlayState() {

}


TwoPlayersPlayState::~TwoPlayersPlayState() {

}


TwoPlayersPlayState::TwoPlayersPlayState(const TwoPlayersPlayState& state) {

}

/**
 * Tries to convert the game state to a MapChoiceMenuState and, if succeeded,
 * forwards call to the corresponding function, otherwise an exception will be
 * thrown.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void TwoPlayersPlayState::enterFrom(const GameState* fromState) {
	
	PlayState::enterFrom(fromState);

	if (fromState == 0) {
		throw std::exception("TwoPlayersPlayState::enterFrom(): \
							 fromState must not be 0");
	}

	// Make sure we enter the state from a MapMenuChoiceState, and do
	// specific enterFrom call if yes:
	if (const MapChoiceMenuState * mapChoiceMenuState =
		dynamic_cast<const MapChoiceMenuState*>(fromState)) {
		enterFrom(mapChoiceMenuState);
	} else {
		throw std::exception("TwoPlayersPlayState::enterFrom(): \
							 must be entered from a \
							 MapChoiceMenuState");
	}
}

/**
 * Initializes the two players play state, fetching its world instance from the
 * provided map choice menu state.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void TwoPlayersPlayState::enterFrom(const MapChoiceMenuState* fromState) {

	// Create ship templates for the players:
	Ship p1ShipTemplate(Ship::BLUE);
	p1ShipTemplate.setLimitFuel(true);
	p1ShipTemplate.setLimitLasers(false);
	p1ShipTemplate.setLimitMissiles(false);

	Ship p2ShipTemplate(Ship::RED);
	p2ShipTemplate.setLimitFuel(true);
	p2ShipTemplate.setLimitLasers(false);
	p2ShipTemplate.setLimitMissiles(false);

	// Create and add a player to the engine
	Player player1("TESTPLAYER", p1ShipTemplate);
	player1.setEventManager(&m_eventManager);
	Player * enginePlayer1 = m_engine.addPlayer(player1);

	// Create and add a second player to the engine
	Player player2("TESTPLAYER2", p2ShipTemplate);
	player2.setEventManager(&m_eventManager);
	Player * enginePlayer2 = m_engine.addPlayer(player2);

	m_engine.loadWorld(fromState->getWorld());
	m_engine.setEventManager(&m_eventManager);
	
	m_engine.init();
	
	// Setup input manager for player 1
	m_inputManager.registerLocalPlayerControl(
		ShipLeftControl(enginePlayer1),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipRightControl(enginePlayer1),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipThrottleControl(enginePlayer1),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipMissileFireControl(enginePlayer1),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipLaserFireControl(enginePlayer1),
		InputManager::LOCAL_PRIMARY);

	// Setup input manager for player 2
	m_inputManager.registerLocalPlayerControl(
		ShipLeftControl(enginePlayer2),
		InputManager::LOCAL_SECONDARY);
	m_inputManager.registerLocalPlayerControl(
		ShipRightControl(enginePlayer2),
		InputManager::LOCAL_SECONDARY);
	m_inputManager.registerLocalPlayerControl(
		ShipThrottleControl(enginePlayer2),
		InputManager::LOCAL_SECONDARY);
	m_inputManager.registerLocalPlayerControl(
		ShipMissileFireControl(enginePlayer2),
		InputManager::LOCAL_SECONDARY);
	m_inputManager.registerLocalPlayerControl(
		ShipLaserFireControl(enginePlayer2),
		InputManager::LOCAL_SECONDARY);
}


/**
 * Notifies this state about a fallback to it from a child state, providing the
 * child state instance. The child game state will be checked, and, when required,
 * proper action will be taken (for example, if the child game state was a pause
 * menu, it may have ordered a "quit", and we should realize it).
 * 
 * @param childState
 */
void TwoPlayersPlayState::handleFallback(const GameState* childState){

	//Throws illegal fallback exception.

}


/**
 * Handles fallback from the pause menu state, checking whether it ordered a game
 * quit or not.
 * 
 * @param pauseState
 */
void TwoPlayersPlayState::handleFallback(const PauseMenuState* pauseState){

	// # Handles fallback from the pause menu
	// # state, checking whether it ordered a
	// # game quit or not.

	if (pauseState->doQuitGame()) {
		finish();
	}
}


/**
 * Checks whether the game is over or not (by checking the players and their
 * ships) and forwards tick to engine.
 */
void TwoPlayersPlayState::tick() {

	if (!m_initialized) {
		throw std::exception("TwoPlayersPlayState::tick(): \
							 state not initialized");
	}

	m_inputManager.refresh();
	m_engine.tick();
}


/**
 * Requests user input to continue to the main menu. Called by tick when game over
 * rules are met.
 */
void TwoPlayersPlayState::triggerGameOver() {

}


/**
 * Clones a two players play state, returning a pointer to the clone.
 */
TwoPlayersPlayState* TwoPlayersPlayState::clone() const {
	return new TwoPlayersPlayState(*this);
}