///////////////////////////////////////////////////////////
//  CollisionHelper.h
//  Implementation of the Interface CollisionHelper
//  Created on:      07-May-2008 21:50:59
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_47BB6CF1_49DF_483a_8477_B2BE1DE19723__INCLUDED_)
#define EA_47BB6CF1_49DF_483a_8477_B2BE1DE19723__INCLUDED_

#include <vector>

class WorldObject;

/**
 * Provides functionality to determine whether a world object collides with one or
 * more world objects or not.
 * @author Lukas Kalinski
 * @version 1.0
 * @created 07-May-2008 21:50:59
 */
class CollisionHelper
{

public:

	/**
	 * Gathers all world objects that the supplied world object collides with, and
	 * inserts them into the supplied container.
	 * 
	 * @param wo
	 * @param obstacles
	 */
	virtual void probeCollisions(const WorldObject* wo, std::vector<WorldObject*>& obstacles) = 0;

};
#endif // !defined(EA_47BB6CF1_49DF_483a_8477_B2BE1DE19723__INCLUDED_)
