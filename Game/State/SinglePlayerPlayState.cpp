///////////////////////////////////////////////////////////
//  SinglePlayerPlayState.cpp
//  Implementation of the Class SinglePlayerPlayState
//  Created on:      28-mar-2008 10:34:16
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "SinglePlayerPlayState.h"
#include "PauseMenuState.h"
#include "InputManager.h"


SinglePlayerPlayState::SinglePlayerPlayState() {

}


SinglePlayerPlayState::~SinglePlayerPlayState() {

}


SinglePlayerPlayState::SinglePlayerPlayState(const SinglePlayerPlayState& state) {

	if (m_initialized) {
		throw std::exception("SinglePlayerPlayState::Copy Constructor: \
							 copying initialized state not allowed.");
	}
}


/**
 * Tries to convert the game state to a MapChoiceMenuState and, if succeeded,
 * forwards call to the corresponding function, otherwise an exception will be
 * thrown.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void SinglePlayerPlayState::enterFrom(const GameState* fromState) {
	
	PlayState::enterFrom(fromState);

	if (fromState == 0) {
		throw std::exception("SinglePlayerPlayState::enterFrom(): \
							 fromState must not be 0");
	}

	// Make sure we enter the state from a MapMenuChoiceState, and do
	// specific enterFrom call if yes:
	if (const MapChoiceMenuState * mapChoiceMenuState =
		dynamic_cast<const MapChoiceMenuState*>(fromState)) {
		enterFrom(mapChoiceMenuState);
	} else {
		throw std::exception("SinglePlayerPlayState::enterFrom(): \
							 must be entered from a \
							 MapChoiceMenuState");
	}
}


/**
 * Initializes the single player play state, fetching its world instance from the
 * provided map choice menu state.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void SinglePlayerPlayState::enterFrom(const MapChoiceMenuState* fromState) {

	// Create a ship template for the player:
	Ship shipTemplate(Ship::BLUE);
	shipTemplate.setLimitFuel(true);
	shipTemplate.setLimitLasers(false);
	shipTemplate.setLimitMissiles(false);

	// Create and add a player to the engine:
	Player player("TESTPLAYER", shipTemplate);
	player.setEventManager(&m_eventManager);
	Player * enginePlayer = m_engine.addPlayer(player);

	m_engine.loadWorld(fromState->getWorld());
	m_engine.setEventManager(&m_eventManager);
	
	m_engine.init();
	
	// Setup input manager:
	m_inputManager.registerLocalPlayerControl(
		ShipLeftControl(enginePlayer),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipRightControl(enginePlayer),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipThrottleControl(enginePlayer),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipMissileFireControl(enginePlayer),
		InputManager::LOCAL_PRIMARY);
	m_inputManager.registerLocalPlayerControl(
		ShipLaserFireControl(enginePlayer),
		InputManager::LOCAL_PRIMARY);
}


/**
 * Notifies this state about a fallback to it from a child state, providing the
 * child state instance. The child game state will be checked, and, when required,
 * proper action will be taken (for example, if the child game state was a pause
 * menu, it may have ordered a "quit", and we should realize it).
 * 
 * @param childState
 */
void SinglePlayerPlayState::handleFallback(const GameState* childState){

	//Throws illegal fallback exception.

}


/**
 * Handles fallback from the pause menu state, checking whether it ordered a game
 * quit or not.
 * 
 * @param childState
 */
void SinglePlayerPlayState::handleFallback(const PauseMenuState* childState){

	// # Handles fallback from the pause menu
	// # state, checking whether it ordered a
	// # game quit or not.

	if (childState->doQuitGame()) {
		finish();
	}
}


/**
 * Handles fallback from a high score menu. The handling will always result in
 * this state being finished, as a preceding enter into the high score menu state
 * from *this* state, was a result of a game over.
 * 
 * @param childState
 */
void SinglePlayerPlayState::handleFallback(const HighScoreMenuState* childState){
	finish();
}


/**
 * Checks whether the game is over or not (by checking the player and his ship)
 * and forwards tick to engine. If finish is awaited, then nothing happens here.
 */
void SinglePlayerPlayState::tick() {

	if (!m_initialized) {
		throw std::exception("SinglePlayerPlayState::tick(): \
							 state not initialized");
	}

	m_inputManager.refresh();
	m_engine.tick();
}


/**
 * Manages a game over by saving a high score (if any) and entering the high score
 * menu state. Called by tick when game over rules are met.
 */
void SinglePlayerPlayState::triggerGameOver() {

	//Saves high score and entes high score
	//menu.


}


/**
 * Clones a single player play state, returning a pointer to the clone.
 */
SinglePlayerPlayState* SinglePlayerPlayState::clone() const {
	return new SinglePlayerPlayState(*this);
}