///////////////////////////////////////////////////////////
//  ShipLaserFireControl.h
//  Implementation of the Class ShipLaserFireControl
//  Created on:      28-mar-2008 10:33:22
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_72DE9ABA_7242_43b5_A423_B5AEA9147785__INCLUDED_)
#define EA_72DE9ABA_7242_43b5_A423_B5AEA9147785__INCLUDED_

#include "PlayerControl.h"
#include "Player.h"
#include "Ship.h"

/**
 * Fire a ship's laser gun.
 */
class ShipLaserFireControl : public PlayerControl
{

public:

	ShipLaserFireControl(Player* player);
	virtual ~ShipLaserFireControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the ship laser fire control, returning a pointer to the clone.
	 */
	virtual ShipLaserFireControl* clone() const;

};
#endif // !defined(EA_72DE9ABA_7242_43b5_A423_B5AEA9147785__INCLUDED_)
