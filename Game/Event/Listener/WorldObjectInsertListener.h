///////////////////////////////////////////////////////////
//  WorldObjectInsertListener.h
//  Implementation of the Interface WorldObjectInsertListener
//  Created on:      16-Apr-2008 23:55:27
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_70C55B27_7C09_4582_9DDA_F270E09CB371__INCLUDED_)
#define EA_70C55B27_7C09_4582_9DDA_F270E09CB371__INCLUDED_

#include "WorldObjectInsertEvent.h"

/**
 * Listens for events saying that a world object was inserted into the world.
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:55:27
 */
class WorldObjectInsertListener
{

public:

	/**
	 * Notifies about a world object being inserted into the world.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(WorldObjectInsertEvent& ev) = 0;

};
#endif // !defined(EA_70C55B27_7C09_4582_9DDA_F270E09CB371__INCLUDED_)
