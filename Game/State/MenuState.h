///////////////////////////////////////////////////////////
//  MenuState.h
//  Implementation of the Class MenuState
//  Created on:      28-mar-2008 10:30:15
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#if !defined(EA_76A2C4C0_4C94_458b_89EA_2E43321FC096__INCLUDED_)
#define EA_76A2C4C0_4C94_458b_89EA_2E43321FC096__INCLUDED_

#include "Menu.h"
#include "GameState.h"

/**
 * The state to be in when navigating through menus.
 */
class MenuState : public GameState
{

public:

	MenuState(const Menu& menu);
	virtual ~MenuState();
	MenuState(const MenuState& state);

	Menu& getMenu();
	virtual void tick();

	/**
	 * Clones a menu state, returning a pointer to the clone.
	 */
	virtual MenuState* clone() const = 0;

protected:

	/**
	 * The menu of the menu state.
	 */
	Menu m_menu;

	void initMenu(Menu menu);

};
#endif // !defined(EA_76A2C4C0_4C94_458b_89EA_2E43321FC096__INCLUDED_)
