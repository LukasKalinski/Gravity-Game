///////////////////////////////////////////////////////////
//  BoundaryStrategy.h
//  Implementation of the Class BoundaryStrategy
//  Created on:      28-mar-2008 10:23:55
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_BFD91A0E_36A0_499b_976F_908CF0CE7A3D__INCLUDED_)
#define EA_BFD91A0E_36A0_499b_976F_908CF0CE7A3D__INCLUDED_

#include "WorldStrategy.h"
#include "World.h"
#include "WorldObject.h"
#include "Coord2d.h"

/**
 * Responsible for making sure that each and every world object is within the
 * world boundaries, and if it's not, then some action defined by the child
 * strategies will do something about it.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 25-Apr-2008 20:06:22
 */
class BoundaryStrategy : public WorldStrategy
{

public:

	/**
	 * Constructs a world boundary strategy.
	 */
	BoundaryStrategy();

	virtual ~BoundaryStrategy();
	BoundaryStrategy(const BoundaryStrategy& strategy);

	/**
	 * Loops throuh all world objects and takes care of those that are found
	 * outside the boundaries defined in world.
	 */
	virtual void applyWorldStrategy(World& world);

	/**
	 * Clones the boundary strategy, returning the clone.
	 */
	virtual BoundaryStrategy* clone() const = 0;

protected:

	/**
	 * Checks whether a world object is beyond the world boundaries and does something
	 * about it if that's the case.
	 * 
	 * @param wo
	 * @param world
	 */
	virtual void manage(WorldObject& wo, World& world) const = 0;

};
#endif // !defined(EA_BFD91A0E_36A0_499b_976F_908CF0CE7A3D__INCLUDED_)
