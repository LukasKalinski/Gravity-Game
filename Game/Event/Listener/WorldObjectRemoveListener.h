///////////////////////////////////////////////////////////
//  WorldObjectRemoveListener.h
//  Implementation of the Interface WorldObjectRemoveListener
//  Created on:      16-Apr-2008 23:55:42
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_F54DD519_2A9C_4c0c_95E2_9ACBD222C196__INCLUDED_)
#define EA_F54DD519_2A9C_4c0c_95E2_9ACBD222C196__INCLUDED_

#include "WorldObjectRemoveEvent.h"

/**
 * Listens for events saying that a world object will be removed after the
 * corresponding event is sent out.
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:55:42
 */
class WorldObjectRemoveListener
{

public:

	/**
	 * Notifies about a world object soon being removed.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(const WorldObjectRemoveEvent& ev) = 0;

};
#endif // !defined(EA_F54DD519_2A9C_4c0c_95E2_9ACBD222C196__INCLUDED_)
