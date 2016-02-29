///////////////////////////////////////////////////////////
//  MenuControl.h
//  Implementation of the Class MenuControl
//  Created on:      28-mar-2008 10:30:08
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_BAF71374_D985_4d2c_8089_A9BE9854E0E5__INCLUDED_)
#define EA_BAF71374_D985_4d2c_8089_A9BE9854E0E5__INCLUDED_

#include "GameControl.h"
#include "Menu.h"

/**
 * Controls used in a menu.
 */
class MenuControl : public GameControl
{

public:
	MenuControl(Menu* menu);
	virtual ~MenuControl();

	virtual void deactivate();

	/**
	 * Clones the menu control, returning a pointer to the clone.
	 */
	virtual MenuControl* clone() const = 0;

protected:

	/**
	 * The menu to control.
	 */
	Menu *m_menu;

};
#endif // !defined(EA_BAF71374_D985_4d2c_8089_A9BE9854E0E5__INCLUDED_)
