///////////////////////////////////////////////////////////
//  FinishStateControl.h
//  Implementation of the Class FinishStateControl
//  Created on:      28-mar-2008 10:26:04
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_470D2AAE_E79B_4c03_B929_A2EED7F2BE27__INCLUDED_)
#define EA_470D2AAE_E79B_4c03_B929_A2EED7F2BE27__INCLUDED_

#include "GameControl.h"

class GameState;

/**
 * Responsible for finishing the contained state when activated.
 */
class FinishStateControl : public GameControl
{

public:

	FinishStateControl(GameState* state);
	virtual ~FinishStateControl();

	virtual void activate();
	virtual void deactivate();

	/**
	 * Clones the game control, returning a pointer to the clone.
	 */
	virtual FinishStateControl* clone() const;

private:

	/**
	 * The state to finish on activation.
	 */
	GameState *m_state;

};
#endif // !defined(EA_470D2AAE_E79B_4c03_B929_A2EED7F2BE27__INCLUDED_)
