///////////////////////////////////////////////////////////
//  ShipLeftControl.cpp
//  Implementation of the Class ShipLeftControl
//  Created on:      28-mar-2008 10:33:33
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ShipLeftControl.h"


ShipLeftControl::ShipLeftControl(Player* player):
PlayerControl(player)
{
}


ShipLeftControl::~ShipLeftControl() {
}


/**
 * Turns the player's ship left turning operation on.
 */
void ShipLeftControl::activate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleTurnLeft(true);
		}
	}
	m_isActivated = true;
}


/**
 * Turns the player's ship left turning operation off.
 */
void ShipLeftControl::deactivate() {
	if (m_player) {
		Ship * ship = m_player->getCurrentShip();
		if (ship && ship->isInitialized()) {
			m_player->getCurrentShip()->toggleTurnLeft(false);
		}
	}
	m_isActivated = false;
}


/**
 * Clones the ship left control, returning a pointer to the clone.
 */
ShipLeftControl* ShipLeftControl::clone() const {
	return new ShipLeftControl(*this);
}