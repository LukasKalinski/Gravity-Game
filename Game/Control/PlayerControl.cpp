///////////////////////////////////////////////////////////
//  PlayerControl.cpp
//  Implementation of the Class PlayerControl
//  Created on:      28-mar-2008 10:32:00
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "PlayerControl.h"

/**
 * Constructs a ship control for a player.
 * 
 * @param player    The ship to affect.
 */
PlayerControl::PlayerControl(Player* player):
m_player(player)
{
	if (!player) {
		throw std::exception("PlayerControl.cpp: *player must not be 0");
	}
}


PlayerControl::~PlayerControl() {
}