///////////////////////////////////////////////////////////
//  WorldObjectDestructionListener.h
//  Implementation of the Interface WorldObjectDestructionListener
//  Created on:      16-Apr-2008 23:55:14
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_558EED3B_F340_47cf_866F_72EEF14536AB__INCLUDED_)
#define EA_558EED3B_F340_47cf_866F_72EEF14536AB__INCLUDED_

#include "WorldObjectDestructionEvent.h"

/**
 * Listens for event saying that a world object was destroyed.
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:55:14
 */
class WorldObjectDestructionListener
{

public:

	/**
	 * Notifies the listener about a world object being destroyed.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(const WorldObjectDestructionEvent& ev) = 0;

};
#endif // !defined(EA_558EED3B_F340_47cf_866F_72EEF14536AB__INCLUDED_)
