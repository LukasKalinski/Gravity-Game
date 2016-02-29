///////////////////////////////////////////////////////////
//  PressMenuButtonControl.h
//  Implementation of the Class PressMenuButtonControl
//  Created on:      28-mar-2008 10:32:11
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_5DE952E6_29C0_4a74_A24D_BE433FF68D59__INCLUDED_)
#define EA_5DE952E6_29C0_4a74_A24D_BE433FF68D59__INCLUDED_

#include "MenuControl.h"

/**
 * Responsible for pressing the menu's currently selected button.
 */
class PressMenuButtonControl : public MenuControl
{

public:

	PressMenuButtonControl(Menu* menu);
	virtual ~PressMenuButtonControl();

	virtual void activate();

	/**
	 * Clones the press menu button control, returning a pointer to the clone.
	 */
	virtual PressMenuButtonControl* clone() const;

};
#endif // !defined(EA_5DE952E6_29C0_4a74_A24D_BE433FF68D59__INCLUDED_)
