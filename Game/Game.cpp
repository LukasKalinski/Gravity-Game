///////////////////////////////////////////////////////////
//  Game.cpp
//  Implementation of the Class Game
//  Created on:      28-mar-2008 10:26:30
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#include <iostream>

#include "Game.h"
#include "OpenGLRenderer.h"
#include "SoundManager.h"


Game * Game::m_singleton = 0;


/**
 * Creates a new Game instance if not already created and returns it.
 */
Game* Game::instance() {

	if (!m_singleton) {
	  m_singleton = new Game();
	}
	return m_singleton;
}


Game::Game():
m_currentState(0),
m_initialized(false),
m_stateTickables(new state_tickables_t())
{
}


Game::~Game() {
	if(m_currentState) {
		delete m_currentState;
	}

	if (m_stateTickables) {
		delete m_stateTickables;
	}

	while (!m_stateTickablesStack.empty()) {
		state_tickables_t * tickableSet = m_stateTickablesStack.top();
		m_stateTickablesStack.pop();
		delete tickableSet;
	}

	
	while (!m_soundManagersStack.empty()) {
		SoundManager* soundManagerset = m_soundManagersStack.top();
		m_soundManagersStack.pop();
		delete soundManagerset;
	}
}


Game::Game(const Game& game) {
	throw std::exception("Game::Copy Constructor: copying \
						 Game singleton not allowed");
}


/**
 * Enters a game state, pushing the previous one on a stack.
 */
void Game::enterState(const GameState& state) {

	if (!m_initialized) {
		throw std::exception("Game::enterState(): game not initialized");
	}

	// Save pointer to the state that is being left
	// (note that it is allowed to be 0, see below):
	GameState* oldState = m_currentState;

	// Push current state on state stack, if present:
	if (m_currentState) {
		m_stateStack.push(m_currentState);

		// Create a new set for the entered state's tickables:
		m_stateTickablesStack.push(m_stateTickables);
		m_stateTickables = new state_tickables_t();
	}

	// Set new current state:
	m_currentState = state.clone();


	// Notify the entered state about what state it was entered from:
	m_currentState->enterFrom(oldState);

	// Notify view that a state is being entered, providing
	// the entered state:
	m_viewRenderer->notifyGameStateEnter(m_currentState);

	SoundManager* sm = new SoundManager(m_currentState);
	sm->init();
	m_soundManagersStack.push(sm);
	
}


/**
 * Leaves the current game state, entering the previous one if any, or exiting the
 * game otherwise.
 */
void Game::leaveState() {

	if (!m_initialized) {
		throw std::exception("Game::leaveState(): game not initialized");
	}

	// Notify view about that a state is being left, providing
	// the state in question:
	m_viewRenderer->notifyGameStateLeave(m_currentState);

	// If there are underlying states, fallback to the one on top:
	if (m_stateStack.size() > 0) {

		// Get underlying state:
		GameState* tmp = m_stateStack.top();

		// Notify it about what state was above it:
		tmp->handleFallback(m_currentState);

		// Clean up current state:
		delete m_currentState;

		// Switch current state to the underlying one:
		m_currentState = tmp;

		// Pop the state that we fell back to from the states stack:
		m_stateStack.pop();

		// Get rid of left state's tickables and fallback to previous
		// set of tickables:
		delete m_stateTickables;
		m_stateTickables = m_stateTickablesStack.top();
		m_stateTickablesStack.pop();

	} else { // No states left, clean up state pointer:
		delete m_currentState;
		m_currentState = 0;
		delete m_stateTickables;
		m_stateTickables = 0;
	}

	if (m_soundManagersStack.size() > 0) {
		SoundManager* sm  = m_soundManagersStack.top();
		delete sm;
		m_soundManagersStack.pop();
	}
}


/**
 * Runs initialization code and starts the game by starting up the main menu state
 * loop by calling run().
 */
void Game::init() {

	// Initialize view:
	m_viewRenderer = new OpenGLRenderer();
	m_viewRenderer->init();

	m_initialized = true;
}


/**
 * Runs the main game loop.
 */
void Game::run() {

	Uint32 time_last = SDL_GetTicks();

	if (!m_initialized) {
		throw std::exception("Game::run(): game not initialized");
	}

	// Remove later (just for testing):
	// Simulates flow: main menu -> map choice menu -> single player game play:
	if(true) {
		// Create main menu state and enter it:
		enterState(MainMenuState());

		// Enter map choice menu state, specifying the play state
		// to enter when a map is chosen:
		//enterState(MapChoiceMenuState(SinglePlayerPlayState()));
		enterState(MapChoiceMenuState(TwoPlayersPlayState()));

		if (MapChoiceMenuState * state = dynamic_cast<MapChoiceMenuState*>(m_currentState)) {
			// Press the one and only "map button":
			state->getMenu().getButtons()[0].press();
		} else {
			throw std::exception("Game::init(): current state was not map choice state");
		}
	}
	// end of menu flow simulation

	// Run the game loop:
	while (m_currentState) {

		// Update current state:
		m_currentState->tick();
		
		// Update tickables that associated themselves with this state:
		state_tickables_t::iterator tickable_it = m_stateTickables->begin();
		for ( ; tickable_it != m_stateTickables->end(); ++tickable_it) {
			(*tickable_it)->tick();
		}

		// Fallback to previous state if current turned invalid:
		if (!m_currentState->isValid()) {
			leaveState();
		}

		// SDL_Delay(m_millis_per_tick/2);

		// Render view:
		m_viewRenderer->render();

		Uint32 time_current = SDL_GetTicks();
		//std::cout << "time_current: "  << time_current << std::endl;
		//std::cout << m_millis_per_tick - (time_current - time_last) << std::endl;

		if(time_current - time_last < m_millis_per_tick) {
			SDL_Delay(m_millis_per_tick - (time_current - time_last));
		}
		time_last += m_millis_per_tick;
		
	}
}


/**
 * Registers a tickable object to be ticked only when the current state is active.
 * 
 * @param tickable
 */
void Game::registerStateTickable(Tickable* tickable) {

	if (m_stateTickables == 0) {
		throw std::exception("Game::registerStateTickable(): \
							 no tickables container found");
	}

	m_stateTickables->insert(tickable);
}


/**
 * Unegisters a tickable object from receiving ticks.
 * 
 * @param tickable
 */
void Game::unregisterStateTickable(Tickable* tickable) {

	if (m_stateTickables == 0) {
		throw std::exception("Game::registerStateTickable(): \
							 no tickables container found");
	}

	state_tickables_t::iterator tickable_it;
	tickable_it = m_stateTickables->find(tickable);
	if (tickable_it != m_stateTickables->end()) {
		m_stateTickables->erase(tickable_it);
	} else {
		throw std::exception("Game::unregisterStateTickable(): \
							 tickable not found");
	}
}
