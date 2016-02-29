///////////////////////////////////////////////////////////
//  GameControl.h
//  Implementation of the Class GameControl
//  Created on:      28-mar-2008 10:26:34
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_CB2A5390_763A_49ec_B602_59DADC227618__INCLUDED_)
#define EA_CB2A5390_763A_49ec_B602_59DADC227618__INCLUDED_

/**
 * Abstract game control class, whose leaf nodes represent a specific game control,
 * used to manipulate the game state. Examples of possible controls are: "pause
 * game", "steer ship left", etc.
 */
class GameControl
{

public:

	GameControl();
	virtual ~GameControl();

	/**
	 * Activates the control.
	 */
	virtual void activate() = 0;

	/**
	 * Deactivates the control.
	 */
	virtual void deactivate() = 0;

	bool isActivated();

	/**
	 * Clones the game control, returning a pointer to the clone.
	 */
	virtual GameControl* clone() const = 0;

protected:

	/**
	 * Tells whether the control is activated or not.
	 */
	bool m_isActivated;

};
#endif // !defined(EA_CB2A5390_763A_49ec_B602_59DADC227618__INCLUDED_)
