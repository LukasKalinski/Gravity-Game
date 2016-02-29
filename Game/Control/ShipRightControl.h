///////////////////////////////////////////////////////////
//  ShipRightControl.h
//  Implementation of the Class ShipRightControl
//  Created on:      28-mar-2008 10:33:43
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_B1066BF3_0E61_47e6_84F2_696542E4F248__INCLUDED_)
#define EA_B1066BF3_0E61_47e6_84F2_696542E4F248__INCLUDED_

#include "PlayerControl.h"
#include "Player.h"
#include "Ship.h"

/**
 * Turn a ship right.
 */
class ShipRightControl : public PlayerControl
{

public:
	ShipRightControl(Player* player);
	virtual ~ShipRightControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the ship right control, returning a pointer to the clone.
	 */
	virtual ShipRightControl* clone() const;

};
#endif // !defined(EA_B1066BF3_0E61_47e6_84F2_696542E4F248__INCLUDED_)
