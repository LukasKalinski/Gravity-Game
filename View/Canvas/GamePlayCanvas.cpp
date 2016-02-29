///////////////////////////////////////////////////////////
//  GamePlayCanvas.cpp
//  Implementation of the Class GamePlayCanvas
//  Created on:      06-Apr-2008 18:44:23
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "GamePlayCanvas.h"
#include "SpriteManagerFactory.h"
#include "WorldBackgroundSpriteManager.h"
#include "WorldSpriteManager.h"
#include "WorldMapSpriteManager.h"


/**
 * Constructs a game play canvas, providing a pointer to the state that it will
 * monitor.
 * 
 * @param state
 */
GamePlayCanvas::GamePlayCanvas(PlayState* state):
Canvas(state,
	   state->getEngine().getWorld().getUpperLeft(),
	   state->getEngine().getWorld().getLowerRight()),
m_playState(state)
{
	if (!state) {
		throw std::exception("GamePlayCanvas.cpp: state must not be 0");
	}
}


GamePlayCanvas::~GamePlayCanvas() {

	// Unregister ourselves from event listening:
	m_eventManager->unregisterWorldObjectInsertListener(this);

	// # The sprite manager pointers will be removed in parent destructor.
}


GamePlayCanvas::GamePlayCanvas(const GamePlayCanvas& c):
Canvas(c),
m_playState(c.m_playState),
m_viewports(c.m_viewports)
{
	throw std::exception("GamePlayCanvas::Copy Constructor: \
						 implement copy constructor before using it!");
}


/**
 * Initializes the sprite manager.
 */
void GamePlayCanvas::init() {
	
	if (m_initialized) {
		throw std::exception("GamePlayCanvas::init(): \
							 already initialized");
	}

	// Register ourselves in the monitored state's event manager:
	m_eventManager->registerWorldObjectInsertListener(this);

	// Load sprite managers for objects already present in the world:
	loadWorldSpriteManagers(*m_playState);

	const Engine * engine = &(m_playState->getEngine());

	// Create a viewport for each available player:
	size_t playersNum = engine->getPlayers().size();

	if (playersNum == 0) {
		throw std::exception("GamePlayCanvas::init(): no players found");
	}

	for (size_t i = 0; i < playersNum; ++i) {

		// Create viewport for player:
		m_viewports.push_back(CanvasViewport(getUpperLeft(), getLowerRight()));

		// Create HUD for player:
		HUD hud(200, 400);
		WorldMapSpriteManager wmsm(engine);
		wmsm.setEventManager(m_eventManager);
		hud.addSpriteManager(wmsm);
		m_huds.push_back(hud);
	}

	m_initialized = true;
}


/**
 * Creates, setups and stores world sprite managers for each object that is
 * present in the play state engine's world. This function must only be called on
 * init, as remaining sprite manager insertions will be handled by insertion event
 * listeners.
 * 
 * @param state
 */
void GamePlayCanvas::loadWorldSpriteManagers(PlayState& state) {
	
	// Throw exception if already loaded:
	if (!m_spriteManagers.empty()) {
		throw std::exception("sprite managers already loaded");
	}

	const World * world = &(state.getEngine().getWorld());
	WorldBackgroundSpriteManager * wbsm = new WorldBackgroundSpriteManager(world);
	wbsm->setEventManager(m_eventManager);
	wbsm->init();
	m_spriteManagers.insert(wbsm);

	const WorldObjectsManager & woManager = world->getWorldObjectsManager();

	// Get world objects already present in the world:
	WorldObjectsManager::world_objects_t wos = woManager.getWorldObjects();
	WorldObjectsManager::world_objects_t::const_iterator wo_it = wos.begin();

	// Create, setup and store sprite managers for each object:
	for ( ; wo_it != wos.end(); ++wo_it) {
		WorldSpriteManager* wsm = SpriteManagerFactory::create(*wo_it);
		wsm->setEventManager(m_eventManager);
		wsm->init();
		
		// Save sprite manager:
		m_spriteManagers.insert(wsm);
	}
}


/**
 * Updates the contained sprite managers.
 */
void GamePlayCanvas::update() {

	if (!m_initialized) {
		throw std::exception("GamePlayCanvas::update(): not initialized");
	}

	// Update sprite managers:
	sprite_managers_t::iterator sm_it = m_spriteManagers.begin();
	std::queue<sprite_managers_t::iterator> removeQueue;
	for ( ; sm_it != m_spriteManagers.end(); ++sm_it) {

		// Update the sprite manager if it still valid, otherwise
		// unregister it from event listening and remove it:
		if ((*sm_it)->isValid()) {
			(*sm_it)->update();
		} else {
			delete *sm_it;
			*sm_it = 0;

			// Defer removal from m_spriteManagers, as it
			// must not be done here:
			removeQueue.push(sm_it);
		}
	}

	// Clean up all sprite managers that became 0 in the above loop
	// (this is a bug fix, as it apparently wasn't a good idea to
	//  remove the sprite manager in that loop):
	while (!removeQueue.empty()) {
		m_spriteManagers.erase(removeQueue.front());
		removeQueue.pop();
	}

	// Update viewports according to available players and their ships:
	Engine::players_t::const_iterator players_it = m_playState->
		getEngine().
		getPlayers().
		begin();

	viewports_t::iterator viewports_it = m_viewports.begin();
	for ( ; players_it != m_playState->getEngine().getPlayers().end(); ++players_it, ++viewports_it) {

		// Update viewport for player if he has a ship and the ship is
		// initialized, that is, if the ship is inserted into the world
		// (otherwise the old position is kept):
		if ((*players_it)->getCurrentShip() &&
			(*players_it)->getCurrentShip()->isInitialized()) {
			viewports_it->setCenter((*players_it)->getCurrentShip()->getPosition());
			float shipSpeed = (*players_it)->getCurrentShip()->getMovement().getLength();
			viewports_it->setDistance(shipSpeed);
		}

		// Calculate canvas height and width:
		float hSize = getLowerRight().getX() - getUpperLeft().getX();
		float vSize = getLowerRight().getY() - getUpperLeft().getY();

		// Reload the viewport's sprites:
		viewports_it->clearSprites();
		sprite_managers_t::const_iterator sm_it = m_spriteManagers.begin();
		for ( ; sm_it != m_spriteManagers.end(); ++sm_it) {
			SpriteManager * sm = *sm_it;
			SpriteManager::sprites_t::const_iterator sprite_it = sm->getSprites().begin();
			for ( ; sprite_it != sm->getSprites().end(); ++sprite_it) {
				
				Sprite sprite = *sprite_it;
				float originalX = (sm->getReferencePoint() + sprite.getPosition()).getX();
				float originalY = (sm->getReferencePoint() + sprite.getPosition()).getY();

				// X--
				// ---
				// ---
				sprite.setPosition(Coord2d(originalX - hSize, originalY + vSize));
				viewports_it->addSprite(sprite);
				
				// -X-
				// ---
				// ---
				sprite.setPosition(Coord2d(originalX, originalY - vSize));
				viewports_it->addSprite(sprite);

				// --X
				// ---
				// ---
				sprite.setPosition(Coord2d(originalX + hSize, originalY - vSize));
				viewports_it->addSprite(sprite);

				// ---
				// X--
				// ---
				sprite.setPosition(Coord2d(originalX - hSize, originalY));
				viewports_it->addSprite(sprite);

				// ---
				// -X-
				// ---
				sprite.setPosition(Coord2d(originalX, originalY));
				viewports_it->addSprite(sprite);

				// ---
				// --X
				// ---
				sprite.setPosition(Coord2d(originalX + hSize, originalY));
				viewports_it->addSprite(sprite);

				// ---
				// ---
				// X--
				sprite.setPosition(Coord2d(originalX - hSize, originalY - vSize));
				viewports_it->addSprite(sprite);

				// ---
				// ---
				// -X-
				sprite.setPosition(Coord2d(originalX, originalY + vSize));
				viewports_it->addSprite(sprite);

				// ---
				// ---
				// --X
				sprite.setPosition(Coord2d(originalX + hSize, originalY + vSize));
				viewports_it->addSprite(sprite);
			}
		}
	}

	// Update HUDs:
	huds_t::iterator hud_it = m_huds.begin();
	for ( ; hud_it != m_huds.end(); ++hud_it) {
		hud_it->reloadSprites();
	}
}


/**
 * Creates a sprite manager for the inserted world object and inserts that sprite
 * manager into the contained set of sprite managers.
 * 
 * @param ev
 */
void GamePlayCanvas::notifyEvent(WorldObjectInsertEvent& ev) {
	SpriteManager * sm = SpriteManagerFactory::create(ev.getInserted());
	sm->setEventManager(m_eventManager);
	sm->init();
	m_spriteManagers.insert(sm);
}


/**
 * Returns the contained viewports.
 */
const GamePlayCanvas::viewports_t& GamePlayCanvas::getViewports() const {
	return m_viewports;
}


/**
 * Returns the HUDs for each viewport (same order as viewports have).
 */
const GamePlayCanvas::huds_t& GamePlayCanvas::getHUDs() const {
	return m_huds;
}
