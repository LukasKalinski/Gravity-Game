///////////////////////////////////////////////////////////
//  GameControlManager.h
//  Implementation of the Class GameControlManager
//  Created on:      28-mar-2008 10:26:41
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_F5F92225_69E9_451a_BA62_C721F80BDD89__INCLUDED_)
#define EA_F5F92225_69E9_451a_BA62_C721F80BDD89__INCLUDED_

#include "GameControl.h"

/**
 * Responsible for managing a control's activation/deactivation according to
 * changes registered by the input listener(s).
 */
class GameControlManager
{

public:

	GameControlManager(const GameControl& control);
	virtual ~GameControlManager();
	GameControlManager(const GameControlManager& cm);

	bool* getSwitchPointer();
	void refresh();
	void reset();

private:

	/**
	 * Tells the status of the most recently registered input for this control, which
	 * means that the control may still be activated when this is false.
	 */
	bool m_controlSwitch;

	GameControl *m_control;

};
#endif // !defined(EA_F5F92225_69E9_451a_BA62_C721F80BDD89__INCLUDED_)
