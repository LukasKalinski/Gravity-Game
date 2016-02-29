///////////////////////////////////////////////////////////
//  EnterStateAction.h
//  Implementation of the Class EnterStateAction
//  Created on:      28-mar-2008 10:25:43
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_1B34B186_F99E_468b_8F26_BE0A81C940BD__INCLUDED_)
#define EA_1B34B186_F99E_468b_8F26_BE0A81C940BD__INCLUDED_

#include "MenuAction.h"
#include "GameState.h"

/**
 * Responsible for entering a new state from the current one.
 */
class EnterStateAction : public MenuAction
{

public:
	EnterStateAction(const GameState& state);
	virtual ~EnterStateAction();
	EnterStateAction(const EnterStateAction& action);

	virtual void trigger();

	/**
	 * Clones an enter state action, returning a pointer to the created clone.
	 */
	virtual EnterStateAction* clone() const;

private:

	/**
	 * The game state to enter on trigger.
	 */
	const GameState *m_state;

};
#endif // !defined(EA_1B34B186_F99E_468b_8F26_BE0A81C940BD__INCLUDED_)
