///////////////////////////////////////////////////////////
//  Menu.h
//  Implementation of the Class Menu
//  Created on:      28-mar-2008 10:29:40
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_E884208D_E73A_4c8d_8D8C_7AF503FBCEE9__INCLUDED_)
#define EA_E884208D_E73A_4c8d_8D8C_7AF503FBCEE9__INCLUDED_

#include "MenuButton.h"
#include "Tickable.h"

/**
 * Responsible for holding a set of buttons and providing functionality to "press"
 * them as well as navigate in the button list.
 */
class Menu : public Tickable
{

public:
	
	typedef std::vector<MenuButton> buttons_t;

	Menu(std::string title);
	virtual ~Menu();
	Menu(const Menu& theMenu);

	void addButton(const MenuButton& button);
	const MenuButton* getSelectedButton() const;
	void pressSelectedButton();
	virtual void tick();
	void switchBackwardButtonIteration(bool switchTo);
	void switchForwardButtonIteration(bool switchTo);

	/**
	 * Returns the buttons constituting the menu.
	 */
	const buttons_t& getButtons() const;

private:
	
	/**
	 * @author Lukas Kalinski
	 * @version 1.0
	 * @updated 06-Apr-2008 22:17:28
	 */
	enum button_iteration_t
	{
		NONE,
		FORWARD,
		BACKWARD
	};

	/**
	 * The number of ticks to wait on each button during an ongoing iteration.
	 */
	static const unsigned short ITERATION_DELAY = 10;

	/**
	 * The number of ticks to wait before continuing the iteration after the first
	 * selection. Example: If we're on button "FOO" and then start an iteration, where
	 * the next button is "BAR", then this delay defines the number of ticks that we
	 * should stay on button "BAR" before entering a faster iteration over the rest of
	 * the buttons.
	 */
	static const unsigned short ITERATION_INIT_DELAY = 15;

	/**
	 * The button iteration mode.
	 */
	button_iteration_t m_buttonIteration;

	/**
	 * Number of ticks left before continuing an ongoing iteration.
	 */
	unsigned int m_iterationCountdown;

	/**
	 * Contains all buttons in the menu.
	 */
	buttons_t m_buttons;

	/**
	 * The currently selected button.
	 */
	buttons_t::iterator m_selectedButton;

	/**
	 * Menu title.
	 */
	std::string m_title;

	void selectNextButton();
	void selectPrevButton();

};
#endif // !defined(EA_E884208D_E73A_4c8d_8D8C_7AF503FBCEE9__INCLUDED_)
