///////////////////////////////////////////////////////////
//  MenuAction.h
//  Implementation of the Interface MenuAction
//  Created on:      28-mar-2008 10:29:51
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_754F15E6_C937_40bb_9130_C89F11632276__INCLUDED_)
#define EA_754F15E6_C937_40bb_9130_C89F11632276__INCLUDED_

/**
 * Defines the interface of an action that can be executed by a menu button.
 */
class MenuAction
{

public:

	/**
	 * Triggers the action.
	 */
	virtual void trigger() = 0;

	/**
	 * Clones a menu action, returning a pointer to the created clone.
	 */
	virtual MenuAction* clone() const = 0;

};
#endif // !defined(EA_754F15E6_C937_40bb_9130_C89F11632276__INCLUDED_)
