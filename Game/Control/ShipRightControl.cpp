///////////////////////////////////////////////////////////
//  ShipRightControl.cpp
//  Implementation of the Class ShipRightControl
//  Created on:      28-mar-2008 10:33:46
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ShipRightControl.h"


ShipRightControl::ShipRightControl(Player* player):
PlayerControl(player)
{
}


ShipRightControl::~ShipRightControl() {
}


/**
 * Turns the player's ship right turning operation on.
 */
void ShipRightControl::activate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleTurnRight(true);
		}
	}
	m_isActivated = true;
}


/**
 * Turns the player's ship right turning operation off.
 */
void ShipRightControl::deactivate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleTurnRight(false);
		}
	}
	m_isActivated = false;
}


/**
 * Clones the ship right control, returning a pointer to the clone.
 */
ShipRightControl* ShipRightControl::clone() const {
	return new ShipRightControl(*this);
}