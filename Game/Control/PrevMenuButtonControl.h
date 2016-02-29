///////////////////////////////////////////////////////////
//  PrevMenuButtonControl.h
//  Implementation of the Class PrevMenuButtonControl
//  Created on:      28-mar-2008 10:32:17
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_C5CB5CE3_D0D0_4c4a_83BA_6AE7ADF251B6__INCLUDED_)
#define EA_C5CB5CE3_D0D0_4c4a_83BA_6AE7ADF251B6__INCLUDED_

#include "MenuControl.h"

/**
 * Responsible for setting a menu's button backward iteration on when activated,
 * and off when deactivated.
 */
class PrevMenuButtonControl : public MenuControl
{

public:

	PrevMenuButtonControl(Menu* menu);
	virtual ~PrevMenuButtonControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the prev menu button control, returning a pointer to the clone.
	 */
	virtual PrevMenuButtonControl* clone() const;

};
#endif // !defined(EA_C5CB5CE3_D0D0_4c4a_83BA_6AE7ADF251B6__INCLUDED_)
