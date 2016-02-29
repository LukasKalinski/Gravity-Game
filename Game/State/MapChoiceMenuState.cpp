///////////////////////////////////////////////////////////
//  MapChoiceMenuState.cpp
//  Implementation of the Class MapChoiceMenuState
//  Created on:      28-mar-2008 10:29:34
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "MapChoiceMenuState.h"
#include "WorldMapRegistry.h"
#include "Game.h"


/**
 * Constructs a map choice menu state, specifying what play state to enter when a
 * map is selected.
 */
MapChoiceMenuState::MapChoiceMenuState(const PlayState& playingState):
MenuState(Menu("Choose Map")),
m_world(0),
m_playState(playingState.clone())
{
}


MapChoiceMenuState::~MapChoiceMenuState() {

	if (m_world) {
		delete m_world;
	}

	if (m_playState) {
		delete m_playState;
	}
}


MapChoiceMenuState::MapChoiceMenuState(const MapChoiceMenuState& state):
MenuState(state),
m_world(0),
m_playState(state.m_playState->clone())
{
	if (state.m_world) {
		m_world = new World(*(state.m_world));
	}
}


/**
 * Loads menu buttons.
 */
void MapChoiceMenuState::init() {
	MenuButton button("Sample Map");
	button.addAction(EnterPlayingStateAction(*m_playState, this, "map1.map"));
	m_menu.addButton(button);
}


/**
 * Routes the enter handling depending on type obtained through RTTI.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void MapChoiceMenuState::enterFrom(const GameState* fromState) {

	if (const MainMenuState * state = dynamic_cast<const MainMenuState*>(fromState)) {
		enterFrom(state);
	} else {
		throw std::exception("MapChoiceMenuState::enterFrom(): \
							 unsupported game state to be entered from");
	}
}


/**
 * Enters the map choice menu state, specifying the instance of the main menu
 * state that it is being entered from.
 * 
 * @param fromState    Takes a pointer because we need to be able to accept 0 as
 * value.
 */
void MapChoiceMenuState::enterFrom(const MainMenuState* fromState) {
	init();
}


/**
 * Generates a world instance from the map with the specified name and stores it
 * in the state. Should be called by EnterSinglePlayerStateAction only.
 */
void MapChoiceMenuState::generateWorld(const std::string& mapName) {

	WorldMapRegistry* wmr = WorldMapRegistry::instance();

	// Delete current world instance if present:
	if (m_world) {
		delete m_world;
		m_world = 0;
	}

	m_world = new World(wmr->generateFromMap(mapName));
}


/**
 * Returns the world instance that has been setup according to the currently
 * selected map.
 */
const World& MapChoiceMenuState::getWorld() const {

	if (m_world) {
		return *m_world;
	} else {
		throw std::exception("MapChoiceMenuState.cpp: m_world cannot be 0 when \
							 requested");
	}
}


/**
 * Notifies this state about a fallback to it from a child state, providing the
 * child state instance. The child game state will be checked, and, when required,
 * proper action will be taken (for example, if the child game state was a pause
 * menu, it may have ordered a "quit", and we should realize it).
 * 
 * @param childState
 */
void MapChoiceMenuState::handleFallback(const GameState* childState){
	// FIXME
}


/**
 * Notifies the state about being "fallbacked" into, from a playing state. Takes
 * no action. (Could possibly forward fallback to the main menu state.)
 * 
 * @param childState
 */
void MapChoiceMenuState::handleFallback(const PlayState* childState){
	
	// Continue fallback to main menu:
	finish();
}


/**
 * Clones a map choice menu state, returning a pointer to the clone.
 */
MapChoiceMenuState* MapChoiceMenuState::clone() const {
	return new MapChoiceMenuState(*this);
}


/**
 * Constructs a new action for entering a single player game state on the
 * specified map.
 */
MapChoiceMenuState::EnterPlayingStateAction::EnterPlayingStateAction(
	const PlayState& playState, 
	MapChoiceMenuState* mapChoiceState,
	const std::string& mapName):
EnterStateAction(playState),
m_mapChoiceMenuState(mapChoiceState),
m_mapName(mapName)
{
}


MapChoiceMenuState::EnterPlayingStateAction::~EnterPlayingStateAction() {
}


MapChoiceMenuState::EnterPlayingStateAction::EnterPlayingStateAction(
	const EnterPlayingStateAction& action):
EnterStateAction(action),
m_mapChoiceMenuState(action.m_mapChoiceMenuState),
m_mapName(action.m_mapName)
{
}


/**
 * Causes the map choice state to generate a world from the chosen map and enters
 * the specified game playing state.
 */
void MapChoiceMenuState::EnterPlayingStateAction::trigger() {
	m_mapChoiceMenuState->generateWorld(m_mapName);
	EnterStateAction::trigger();
}


/**
 *
 */
MapChoiceMenuState::EnterPlayingStateAction *
	MapChoiceMenuState::EnterPlayingStateAction::clone() const {
	return new EnterPlayingStateAction(*this);
}