///////////////////////////////////////////////////////////
//  ShipMissileFireControl.h
//  Implementation of the Class ShipMissileFireControl
//  Created on:      28-mar-2008 10:33:36
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_0E3AE843_254C_4e53_A909_B1C63743DCEF__INCLUDED_)
#define EA_0E3AE843_254C_4e53_A909_B1C63743DCEF__INCLUDED_

#include "PlayerControl.h"
#include "Player.h"
#include "Ship.h"

/**
 * Fire a ship's missile launcher.
 */
class ShipMissileFireControl : public PlayerControl
{

public:

	ShipMissileFireControl(Player* player);
	virtual ~ShipMissileFireControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the ship missile fire control, returning a pointer to the clone.
	 */
	virtual ShipMissileFireControl* clone() const;

};
#endif // !defined(EA_0E3AE843_254C_4e53_A909_B1C63743DCEF__INCLUDED_)
