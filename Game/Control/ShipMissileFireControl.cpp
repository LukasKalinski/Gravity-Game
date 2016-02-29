///////////////////////////////////////////////////////////
//  ShipMissileFireControl.cpp
//  Implementation of the Class ShipMissileFireControl
//  Created on:      28-mar-2008 10:33:40
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ShipMissileFireControl.h"


ShipMissileFireControl::ShipMissileFireControl(Player* player):
PlayerControl(player)
{
}


ShipMissileFireControl::~ShipMissileFireControl() {
}


/**
 * Toggles the missile launcher on the player's ship on.
 */
void ShipMissileFireControl::activate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleMissileLauncher(true);
		}
	}
	m_isActivated = true;
}


/**
 * Toggles the missile launcher on the player's ship off.
 */
void ShipMissileFireControl::deactivate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleMissileLauncher(false);
		}
	}
	m_isActivated = false;
}


/**
 * Clones the ship missile fire control, returning a pointer to the clone.
 */
ShipMissileFireControl* ShipMissileFireControl::clone() const {
	return new ShipMissileFireControl(*this);
}