///////////////////////////////////////////////////////////
//  LeaveStateAction.h
//  Implementation of the Class LeaveStateAction
//  Created on:      28-mar-2008 10:29:09
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_E3F5F278_A0AF_4e7b_B7E2_526E6772F7AC__INCLUDED_)
#define EA_E3F5F278_A0AF_4e7b_B7E2_526E6772F7AC__INCLUDED_

#include "MenuAction.h"

/**
 * Responsible for leaving the current state to the previous one, or if none is
 * available, to quit the game.
 */
class LeaveStateAction : public MenuAction
{

public:
	LeaveStateAction();
	virtual ~LeaveStateAction();
	LeaveStateAction(const LeaveStateAction& action);

	virtual void trigger();

	/**
	 * Clones a leave state action, returning a pointer to the created clone.
	 */
	virtual LeaveStateAction* clone() const;

};
#endif // !defined(EA_E3F5F278_A0AF_4e7b_B7E2_526E6772F7AC__INCLUDED_)
