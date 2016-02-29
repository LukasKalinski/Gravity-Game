///////////////////////////////////////////////////////////
//  PlayerControl.h
//  Implementation of the Class PlayerControl
//  Created on:      28-mar-2008 10:31:56
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_22180870_FB52_43c7_9162_8AD42756C0A6__INCLUDED_)
#define EA_22180870_FB52_43c7_9162_8AD42756C0A6__INCLUDED_

#include "GamePlayControl.h"
#include "Player.h"

/**
 * Abstract class for controls that affect a player.
 */
class PlayerControl : public GamePlayControl
{

public:

	/**
	 * Constructs a ship control for a player.
	 * 
	 * @param player    The ship to affect.
	 */
	PlayerControl(Player* player);

	virtual ~PlayerControl();

	/**
	 * Clones the player control, returning a pointer to the clone.
	 */
	virtual PlayerControl* clone() const = 0;

protected:

	/**
	 * The player who's ship(s) and potentially other things (like toggle map, for
	 * example) are to be controlled.
	 */
	Player *m_player;

};
#endif // !defined(EA_22180870_FB52_43c7_9162_8AD42756C0A6__INCLUDED_)
