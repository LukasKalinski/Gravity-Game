///////////////////////////////////////////////////////////
//  InputManager.h
//  Implementation of the Class InputManager
//  Created on:      28-mar-2008 10:28:07
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#if !defined(EA_63BBD198_EEDA_4f56_A879_AA000EC86875__INCLUDED_)
#define EA_63BBD198_EEDA_4f56_A879_AA000EC86875__INCLUDED_

#include "InputListener.h"
#include "KeyboardListener.h"
#include "GameControlManager.h"
#include "NextMenuButtonControl.h"
#include "PrevMenuButtonControl.h"
#include "PressMenuButtonControl.h"
#include "PauseGameControl.h"
#include "FinishStateControl.h"
#include "ConfigKeyboardMapControl.h"
#include "ShipThrottleControl.h"
#include "ShipLeftControl.h"
#include "ShipRightControl.h"
#include "ShipLaserFireControl.h"
#include "ShipMissileFireControl.h"

/**
 * Responsible for detecting what game controls are requested to be activated or
 * deactivated based on current input, and calling the corresponding function on
 * the contained game control objects.
 */
class InputManager
{

public:

	enum player_t {

		/**
		 * A player type constant used when registering controls for local player 1.
		 */
		LOCAL_PRIMARY,

		/**
		 * A player type constant used when registering controls for local player 2.
		 */
		LOCAL_SECONDARY
	};

	/**
	 * Actions that a player can take.
	 */
	enum player_action_t {
		SHIP_THROTTLE,
		SHIP_LEFT,
		SHIP_RIGHT,
		SHIP_FIRE_LASER,
		SHIP_FIRE_MISSILE
	};

	
	typedef std::map<player_t,
		std::map<player_action_t, KeyboardListener::control_alias_t> > player_control_alias_map_t;

	InputManager();
	virtual ~InputManager();
	InputManager(const InputManager& im);
	
	void refresh();
	void registerLocalControl(const NextMenuButtonControl& control);
	void registerLocalControl(const PrevMenuButtonControl& control);
	void registerLocalControl(const PressMenuButtonControl& control);
	void registerLocalControl(const PauseGameControl& control);
	void registerLocalControl(const FinishStateControl& control);
	void registerLocalControl(const ConfigKeyboardMapControl& control);
	void registerLocalPlayerControl(const ShipThrottleControl& control, player_t playerType);
	void registerLocalPlayerControl(const ShipLeftControl& control, player_t playerType);
	void registerLocalPlayerControl(const ShipRightControl& control, player_t playerType);
	void registerLocalPlayerControl(const ShipLaserFireControl& control, player_t playerType);
	void registerLocalPlayerControl(const ShipMissileFireControl& control, player_t playerType);
	void reset();

private:

	typedef std::vector<GameControlManager*> control_managers_t;

	/**
	 * Maps a player type to a player action<->control alias map.
	 */
	static player_control_alias_map_t m_playerControlAliasMap;

	/**
	 * The used listeners.
	 */
	// std::vector<InputListener*> m_listeners;
	InputListener * m_listener;

	/**
	 * Holds control managers to refresh when being refreshed.
	 * We have pointers instead of simple objects in order to be
	 * sure that the bool pointer forwarded to the input listener
	 * is valid.
	 */
	 control_managers_t m_controlManagers;

	 /**
	  * Loads static members with data.
	  */
	 static void loadStaticData();

};
#endif // !defined(EA_63BBD198_EEDA_4f56_A879_AA000EC86875__INCLUDED_)
