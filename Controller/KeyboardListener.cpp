///////////////////////////////////////////////////////////
//  KeyboardListener.cpp
//  Implementation of the Class KeyboardListener
//  Created on:      28-mar-2008 10:28:51
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "KeyboardListener.h"
#include "ConfigRegistry.h"
#include "SDL.h"


KeyboardListener::KeyboardListener() {

}


KeyboardListener::~KeyboardListener() {

}


KeyboardListener::KeyboardListener(const KeyboardListener& kl) {
	throw std::exception("KeyboardListener.cpp: Noooo! Copy constructor called!");
}

/**
 * Calls functions in InputListener::switchOn/switchOff 
 * based on keypresses/keyreleases.
 */
void KeyboardListener::refresh() {
	SDL_Event ev;
	ConfigRegistry* cr = ConfigRegistry::instance();

	ConfigRegistry::control_aliases_t::const_iterator controlAlias_it;

	while(SDL_PollEvent(&ev)) {

		// Fetch keycode from SDL event:
		// Uint8 keyCode = ;

		// Get list of possible control aliases for the fetched key code:
		ConfigRegistry::control_aliases_t control_aliases = cr->
			getControlAliasesForKey(ev.key.keysym.scancode);

		switch (ev.type) {
		case SDL_KEYDOWN:
			if(ev.key.keysym.scancode == 1)
				exit(0);

			for (controlAlias_it = control_aliases.begin();
				controlAlias_it != control_aliases.end();
				++controlAlias_it) {
				switchOn(*controlAlias_it);

// # 17/4: Does not work since started to use enum instead of unsigned short...
//				if(m_listenFunctionMap.find(*controlAlias_it) != m_listenFunctionMap.end()) {
//					(*(m_listenFunctionMap.find(*controlAlias_it))).second();
//				}
			}
			break;
		case SDL_KEYUP:
			for(controlAlias_it = control_aliases.begin();
				controlAlias_it != control_aliases.end();
				++controlAlias_it)
				switchOff(*controlAlias_it);
			break;
		case SDL_QUIT:
			exit(0);
		}
	}
}


// # 17/4: Does not work since started to use enum instead of unsigned short...
//void KeyboardListener::addFunction(control_alias_t ca, void (*fp)(void)) {
//	m_listenFunctionMap[ca] = fp;
//}
