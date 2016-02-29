///////////////////////////////////////////////////////////
//  MainMenuState.cpp
//  Implementation of the Class MainMenuState
//  Created on:      28-mar-2008 10:29:21
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <map>
#include <string>

#include "MainMenuState.h"
#include "MenuButton.h"
#include "MapChoiceMenuState.h"
#include "SinglePlayerPlayState.h"
#include "TwoPlayersPlayState.h"
#include "HighScoreMenuState.h"
#include "HelpMenuState.h"
#include "EnterStateAction.h"
#include "LeaveStateAction.h"


MainMenuState::MainMenuState():
MenuState(Menu("Main Menu"))
{
}


MainMenuState::~MainMenuState() {

}


MainMenuState::MainMenuState(const MainMenuState& state):
MenuState(state)
{
}


/**
 * Enters the main menu state, only accepting fromState == 0. If fromState isn't
 * zero, then an exception will be thrown.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void MainMenuState::enterFrom(const GameState* fromState) {
	if (fromState) {
		throw std::exception("MainMenuState.cpp: cannot enter main menu from some other game state");
	}
	
	init();
}


void MainMenuState::init() {

	if (m_initialized) {
		throw std::exception("MainMenuState.cpp: cannot initalize more than once");
	}

	// ## Initialize menu and its buttons:

	std::map<std::string, MenuButton> buttons;

	// # Create a "go to single player map choice menu" button:
	buttons["SINGLE_PLAYER"] = MenuButton("Single Player");

	// Create the map choice state, specifying the play state to be entered
	// when a map is chosen:
	MapChoiceMenuState singlePlayerMapChoiceState = MapChoiceMenuState( SinglePlayerPlayState() );

	// Make the button enter the above map choice state when pressed:
	buttons["SINGLE_PLAYER"].addAction( EnterStateAction( singlePlayerMapChoiceState ) );


	// # Create a "go to two players map choice menu" button:
	buttons["TWO_PLAYERS"] = MenuButton("Two Players");

	// Create the map choice state, specifying the play state to be entered
	// when a map is chosen:
	MapChoiceMenuState twoPlayersMapChoiceState = MapChoiceMenuState( TwoPlayersPlayState() );

	// Make the button enter the above map choice state when pressed:
	buttons["TWO_PLAYERS"].addAction( EnterStateAction( twoPlayersMapChoiceState ) );

	
	// # Create an "enter highscores" button:
	buttons["HIGHSCORE"] = MenuButton("Highscore");

	// Make the button enter the highscore menu state when pressed:
	buttons["HIGHSCORE"].addAction( EnterStateAction( HighScoreMenuState() ) );


	// # Create an "enter help menu" button:
	buttons["HELP"] = MenuButton("Help");

	// Make the button enter the help menu state when pressed:
	buttons["HELP"].addAction( EnterStateAction( HelpMenuState() ) );


	// # Create a "quit game" button:
	buttons["QUIT"] = MenuButton("Quit Game");

	// Make the button quit the game when pressed:
	buttons["QUIT"].addAction( LeaveStateAction() );


	// Insert all buttons into the menu:
	std::map<std::string, MenuButton>::iterator buttons_it = buttons.begin();
	for ( ; buttons_it != buttons.end(); ++buttons_it) {
		m_menu.addButton(buttons_it->second);
	}


	m_initialized = true;
}


/**
 * Clones a main menu state, returning a pointer to the clone.
 */
MainMenuState* MainMenuState::clone() const {
	return new MainMenuState(*this);
}