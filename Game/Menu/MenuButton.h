///////////////////////////////////////////////////////////
//  MenuButton.h
//  Implementation of the Class MenuButton
//  Created on:      28-mar-2008 10:29:54
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_F83913E3_7ED9_4b63_9C7D_5EEF7D35F183__INCLUDED_)
#define EA_F83913E3_7ED9_4b63_9C7D_5EEF7D35F183__INCLUDED_

#include <queue>
#include "MenuAction.h"


/**
 * Responsible for holding one or more actions to take when pressed.
 */
class MenuButton
{

public:

	MenuButton();
	MenuButton(const std::string& name);
	virtual ~MenuButton();
	MenuButton(const MenuButton& button);

	void addAction(const MenuAction& action);
	const std::string& getName() const;
	void press() const;

private:

	typedef std::vector<MenuAction*> actions_t;

	/**
	 * The button's name.
	 */
	std::string m_name;

	/**
	 * The action(s) to take when pressed.
	 */
	actions_t m_actions;

};
#endif // !defined(EA_F83913E3_7ED9_4b63_9C7D_5EEF7D35F183__INCLUDED_)
