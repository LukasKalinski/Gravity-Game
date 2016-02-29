///////////////////////////////////////////////////////////
//  KeyboardListener.h
//  Implementation of the Class KeyboardListener
//  Created on:      28-mar-2008 10:28:45
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_4296CE58_3B7E_4695_AAF2_CFE300A1940F__INCLUDED_)
#define EA_4296CE58_3B7E_4695_AAF2_CFE300A1940F__INCLUDED_

#include "InputListener.h"

/**
 * Responsible for monitoring a defined set of keyboard keys and call
 * InputListener::switchOn/switchOff functions when a key's status changes
 * (pressed/unpressed).
 */
class KeyboardListener : public InputListener
{

public:
	
	/**
	 * Aliases for game controls that can be listened for.
	 */
	enum control_alias_t {

		/**
		 * Control Alias: Finish the current game state.
		 */
		FINISH_GAME_STATE = 15,

		/**
		 * Control Alias: Fire laser guns from the ship of the first keyboard-controlled
		 * player.
		 */
		GAMEPLAY_P1_SHIP_FIRE_LASER = 8,

		/**
		 * Control Alias: Fire missiles from the ship of the first keyboard-controlled
		 * player.
		 */
		GAMEPLAY_P1_SHIP_FIRE_MISSILE = 9,

		/**
		 * Control Alias: Left-turn the ship of the first keyboard-controlled player.
		 */
		GAMEPLAY_P1_SHIP_LEFT = 6,

		/**
		 * Control Alias: Right-turn the ship of the first keyboard-controlled player.
		 */
		GAMEPLAY_P1_SHIP_RIGHT = 7,

		/**
		 * Control Alias: Throttle the ship of the first keyboard-controlled player.
		 */
		GAMEPLAY_P1_SHIP_THROTTLE = 5,

		/**
		 * Control Alias: Fire laser guns from the ship of the second keyboard-controlled
		 * player.
		 */
		GAMEPLAY_P2_SHIP_FIRE_LASER = 13,

		/**
		 * Control Alias: Fire missiles from the ship of the second keyboard-controlled
		 * player.
		 */
		GAMEPLAY_P2_SHIP_FIRE_MISSILE = 14,

		/**
		 * Control Alias: Left-turn the ship of the second keyboard-controlled player.
		 */
		GAMEPLAY_P2_SHIP_LEFT = 11,

		/**
		 * Control Alias: Right-turn the ship of the second keyboard-controlled player.
		 */
		GAMEPLAY_P2_SHIP_RIGHT = 12,

		/**
		 * Control Alias: Throttle the ship of the second keyboard-controlled player.
		 */
		GAMEPLAY_P2_SHIP_THROTTLE = 10,

		/**
		 * Control Alias: Pause a game play session (state).
		 */
		GAMEPLAY_PAUSE = 4,

		/**
		 * Control Alias: Navigate to the next button in a menu.
		 */
		MENU_BTN_NEXT = 1,

		/**
		 * Control Alias: Press the currently selected button in a menu.
		 */
		MENU_BTN_PRESS = 3,

		/**
		 * Control Alias: Navigate to the previous button in a menu.
		 */
		MENU_BTN_PREV = 2
	};

	KeyboardListener();
	virtual ~KeyboardListener();
	KeyboardListener(const KeyboardListener& kl);

	/**
	 *
	 */
	virtual void refresh();

	using InputListener::enableListen;

	// Maps from Control Alias to function.
	//typedef void (*Function_Ptr)(void);
	//void addFunction(unsigned short, void (*)(void));

private:

	/**
	 * Maps the codes of the listened keyboard keys to control aliases.
	 */
	//std::map<unsigned short, control_alias_t> m_listenedKeysMap;

//	std::map<control_alias_t, Function_Ptr> m_listenFunctionMap;

};
#endif // !defined(EA_4296CE58_3B7E_4695_AAF2_CFE300A1940F__INCLUDED_)
