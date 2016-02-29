///////////////////////////////////////////////////////////
//  ShipThrottleControl.h
//  Implementation of the Class ShipThrottleControl
//  Created on:      28-mar-2008 10:34:05
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_CEA6C68E_B5E0_4c63_BBD3_D568793333A4__INCLUDED_)
#define EA_CEA6C68E_B5E0_4c63_BBD3_D568793333A4__INCLUDED_

#include "PlayerControl.h"
#include "Player.h"
#include "Ship.h"

/**
 * Throttle a ship.
 */
class ShipThrottleControl : public PlayerControl
{

public:

	ShipThrottleControl(Player* player);
	virtual ~ShipThrottleControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the ship throttle control, returning a pointer to the clone.
	 */
	virtual ShipThrottleControl* clone() const;

};
#endif // !defined(EA_CEA6C68E_B5E0_4c63_BBD3_D568793333A4__INCLUDED_)
