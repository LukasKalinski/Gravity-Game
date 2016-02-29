///////////////////////////////////////////////////////////
//  MenuCanvas.cpp
//  Implementation of the Class MenuCanvas
//  Created on:      06-Apr-2008 18:44:16
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "MenuCanvas.h"
#include "SpriteManagerFactory.h"


/**
 * Constructs a menu canvas, providing a pointer to the state that it will monitor.
 * 
 * 
 * @param state
 */
MenuCanvas::MenuCanvas(MenuState* state):
Canvas(state, Coord2d(0,0), Coord2d(500,500)),
m_menuState(state),
m_viewport(Coord2d(0,0), Coord2d(500,500))
{
	if (!state) {
		throw std::exception("MenuCanvas.cpp: state must not be 0");
	}
}


MenuCanvas::~MenuCanvas() {
	// # The sprite manager pointers will be removed in parent destructor.
}


MenuCanvas::MenuCanvas(const MenuCanvas& canvas):
Canvas(canvas),
m_menuState(canvas.m_menuState),
m_viewport(canvas.m_viewport)
{
	throw std::exception("MenuCanvas.cpp: implement copy constructor before using it!");
}


/**
 * Initializes the sprite manager.
 */
void MenuCanvas::init() {
	
	// Create and setup sprite managers for the menu buttons:
	Menu::buttons_t::const_iterator btn_it = m_menuState->getMenu().getButtons().begin();
	for ( ; btn_it != m_menuState->getMenu().getButtons().end(); ++btn_it) {
		MenuButtonSpriteManager * sm = SpriteManagerFactory::create(&(*btn_it));
		sm->setEventManager(m_menuState->getEventManager());
		sm->init();
		m_spriteManagers.insert(sm);
	}

	// Setup viewport: FIXME
	//m_viewport.
	m_initialized = true;
}


/**
 * Updates the contained sprite managers.
 */
void MenuCanvas::update() {
	
	if (!m_initialized) {
		throw std::exception("MenuCanvas::update(): not initialized");
	}

	// Tick contained sprite managers and erase the invalid ones:
	sprite_managers_t::iterator sm_it = m_spriteManagers.begin();
	std::queue<sprite_managers_t::iterator> removeQueue;
	for ( ; sm_it != m_spriteManagers.end(); ++sm_it) {

		// Update the sprite manager if it still is valid, otherwise
		// remove it:
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
}


/**
 * Returns the viewport of the menu canvas.
 */
const CanvasViewport& MenuCanvas::getViewport() const {
	return m_viewport;
}
