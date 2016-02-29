///////////////////////////////////////////////////////////
//  ConfigKeyboardMapControl.h
//  Implementation of the Class ConfigKeyboardMapControl
//  Created on:      28-mar-2008 10:24:29
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_C7C7A57C_115C_482f_8B6D_565F9F219B20__INCLUDED_)
#define EA_C7C7A57C_115C_482f_8B6D_565F9F219B20__INCLUDED_

#include "GameControl.h"

/**
 * Responsible for reconfiguring the mapping between a keyboard key and a game
 * control.
 */
class ConfigKeyboardMapControl : public GameControl
{

public:
	
	/**
	 * Constructs a keyboard map reconfig control, specifying the alias for the
	 * control that is to be reconfigured.
	 * 
	 * @param controlAlias    Must be one of the CTRL_* constants in this class.
	 */
	ConfigKeyboardMapControl(unsigned int controlAlias);

	virtual ~ConfigKeyboardMapControl();

	/**
	 * Player one ship laser fire.
	 */
	static const unsigned int CTRL_P1_SHIP_FIRE_LASER;

	/**
	 * Player one ship missile fire.
	 */
	static const unsigned int CTRL_P1_SHIP_FIRE_MISSILE;

	/**
	 * Player one ship left.
	 */
	static const unsigned int CTRL_P1_SHIP_LEFT;

	/**
	 * Player one ship right.
	 */
	static const unsigned int CTRL_P1_SHIP_RIGHT;

	/**
	 * Player one ship throttle.
	 */
	static const unsigned int CTRL_P1_SHIP_THROTTLE;

	/**
	 * Player two ship laser fire.
	 */
	static const unsigned int CTRL_P2_SHIP_FIRE_LASER;

	/**
	 * Player two ship missile fire.
	 */
	static const unsigned int CTRL_P2_SHIP_FIRE_MISSILE;

	/**
	 * Player two ship left.
	 */
	static const unsigned int CTRL_P2_SHIP_LEFT;
	/**
	 * Player two ship right.
	 */
	static const unsigned int CTRL_P2_SHIP_RIGHT;
	/**
	 * Player two ship throttle.
	 */
	static const unsigned int CTRL_P2_SHIP_THROTTLE;

	virtual void activate();
	virtual void deactivate();
	bool isDone();
	void setNewKey(unsigned int key);

	/**
	 * Clones the config keyboard map control, returning a pointer to the clone.
	 */
	virtual ConfigKeyboardMapControl* clone() const;

private:

	/**
	 * The alias of the control to reconfigure.
	 */
	unsigned int m_controlAlias;

	/**
	 * Tells whether the reconfiguration has been done or not.
	 */
	bool m_done;

	/**
	 * The new key to set for the control (will be set by keyboard listener).
	 */
	unsigned int m_newKey;

};
#endif // !defined(EA_C7C7A57C_115C_482f_8B6D_565F9F219B20__INCLUDED_)
