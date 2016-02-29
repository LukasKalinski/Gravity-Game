///////////////////////////////////////////////////////////
//  NextMenuButtonControl.h
//  Implementation of the Class NextMenuButtonControl
//  Created on:      28-mar-2008 10:30:51
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_CC87EB1D_8475_4c75_B3E4_5695C13288C8__INCLUDED_)
#define EA_CC87EB1D_8475_4c75_B3E4_5695C13288C8__INCLUDED_

#include "MenuControl.h"

/**
 * Responsible for setting a menu's button forward iteration on when activated,
 * and off when deactivated.
 */
class NextMenuButtonControl : public MenuControl
{

public:
	NextMenuButtonControl(Menu* menu);
	virtual ~NextMenuButtonControl();

	virtual void activate();
	virtual void deactivate();
	/**
	 * Clones the next menu button control, returning a pointer to the clone.
	 */
	virtual NextMenuButtonControl* clone() const;

};
#endif // !defined(EA_CC87EB1D_8475_4c75_B3E4_5695C13288C8__INCLUDED_)
