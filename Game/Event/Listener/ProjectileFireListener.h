///////////////////////////////////////////////////////////
//  ProjectileFireListener.h
//  Implementation of the Interface ProjectileFireListener
//  Created on:      16-Apr-2008 23:55:34
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_36587DF0_5713_4d5e_8032_CAD78C850542__INCLUDED_)
#define EA_36587DF0_5713_4d5e_8032_CAD78C850542__INCLUDED_

#include "ProjectileFireEvent.h"

/**
 * Listens for projectiles being fired in the world (during a game play state).
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:55:34
 */
class ProjectileFireListener
{

public:

	/**
	 * Notifies about a projectile being fired in the world.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(const ProjectileFireEvent& ev) = 0;

};
#endif // !defined(EA_36587DF0_5713_4d5e_8032_CAD78C850542__INCLUDED_)
