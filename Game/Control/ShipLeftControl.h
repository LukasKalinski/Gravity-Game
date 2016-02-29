///////////////////////////////////////////////////////////
//  ShipLeftControl.h
//  Implementation of the Class ShipLeftControl
//  Created on:      28-mar-2008 10:33:29
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_47F87C27_38B4_4bd6_9B95_2229E6F980D0__INCLUDED_)
#define EA_47F87C27_38B4_4bd6_9B95_2229E6F980D0__INCLUDED_

#include "PlayerControl.h"
#include "Player.h"
#include "Ship.h"

/**
 * Turn a ship left.
 */
class ShipLeftControl : public PlayerControl
{

public:

	ShipLeftControl(Player* player);
	virtual ~ShipLeftControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the ship left control, returning a pointer to the clone.
	 */
	virtual ShipLeftControl* clone() const;

};
#endif // !defined(EA_47F87C27_38B4_4bd6_9B95_2229E6F980D0__INCLUDED_)
