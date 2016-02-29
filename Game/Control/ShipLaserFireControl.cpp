///////////////////////////////////////////////////////////
//  ShipLaserFireControl.cpp
//  Implementation of the Class ShipLaserFireControl
//  Created on:      28-mar-2008 10:33:25
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ShipLaserFireControl.h"


ShipLaserFireControl::ShipLaserFireControl(Player* player):
PlayerControl(player) {
}


ShipLaserFireControl::~ShipLaserFireControl() {
}


/**
 * Toggles the laser gun on the player's ship on.
 */
void ShipLaserFireControl::activate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleLaserGun(true);
		}
	}
	m_isActivated = true;
}


/**
 * Toggles the laser gun on the player's ship off.
 */
void ShipLaserFireControl::deactivate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleLaserGun(false);
		}
	}
	m_isActivated = false;
}


/**
 * Clones the ship laser fire control, returning a pointer to the clone.
 */
ShipLaserFireControl* ShipLaserFireControl::clone() const {
	return new ShipLaserFireControl(*this);
}