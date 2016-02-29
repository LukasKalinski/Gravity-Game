///////////////////////////////////////////////////////////
//  PauseGameControl.h
//  Implementation of the Class PauseGameControl
//  Created on:      28-mar-2008 10:31:07
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_91BEC8C7_375A_4a44_87F3_D0B381923E31__INCLUDED_)
#define EA_91BEC8C7_375A_4a44_87F3_D0B381923E31__INCLUDED_

#include "GamePlayControl.h"

/**
 * Pause a game session.
 */
class PauseGameControl : public GamePlayControl
{

public:

	PauseGameControl();
	virtual ~PauseGameControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the pause game control, returning a pointer to the clone.
	 */
	virtual PauseGameControl* clone() const;

};
#endif // !defined(EA_91BEC8C7_375A_4a44_87F3_D0B381923E31__INCLUDED_)
