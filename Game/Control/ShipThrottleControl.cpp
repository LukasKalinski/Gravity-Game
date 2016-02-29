///////////////////////////////////////////////////////////
//  ShipThrottleControl.cpp
//  Implementation of the Class ShipThrottleControl
//  Created on:      28-mar-2008 10:34:08
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ShipThrottleControl.h"


ShipThrottleControl::ShipThrottleControl(Player* player):
PlayerControl(player) {
}


ShipThrottleControl::~ShipThrottleControl() {
}


/**
 * Toggles the player's ship throttling on.
 */
void ShipThrottleControl::activate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleThrottle(true);
		}
	}
	m_isActivated = true;
}


/**
 * Toggles the player's ship throttling off.
 */
void ShipThrottleControl::deactivate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleThrottle(false);
		}
	}
	m_isActivated = false;
}


/**
 * Clones the ship throttle control, returning a pointer to the clone.
 */
ShipThrottleControl* ShipThrottleControl::clone() const {
	return new ShipThrottleControl(*this);
}