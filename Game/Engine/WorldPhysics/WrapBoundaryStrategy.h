///////////////////////////////////////////////////////////
//  WrapBoundaryStrategy.h
//  Implementation of the Class WrapBoundaryStrategy
//  Created on:      06-Apr-2008 20:16:34
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_E0FEAE14_808C_4ef8_A311_FFE661EB6E41__INCLUDED_)
#define EA_E0FEAE14_808C_4ef8_A311_FFE661EB6E41__INCLUDED_

#include "BoundaryStrategy.h"

/**
 * Represents the world boundaries, i.e., the area that world objects are allowed
 * to appear on. This strategy is to wrap the boundaries, meaning that if a
 * boundary is trespassed, the trespasser will end up on the opposite side of the
 * world.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 25-Apr-2008 20:08:28
 */
class WrapBoundaryStrategy : public BoundaryStrategy
{

public:
	
	/**
	 * Constructs a wrap boundary strategy.
	 */
	WrapBoundaryStrategy();

	virtual ~WrapBoundaryStrategy();
	WrapBoundaryStrategy(const WrapBoundaryStrategy& strategy);

	/**
	 * Clones the wrap boundary strategy, returning the clone.
	 */
	virtual WrapBoundaryStrategy* clone() const;

protected:

	/**
	 * Checks whether a world object is beyond the world boundaries and does something
	 * about it if that's the case.
	 * 
	 * @param wo
	 * @param world
	 */
	virtual void manage(WorldObject& wo, World& world) const;

};
#endif // !defined(EA_E0FEAE14_808C_4ef8_A311_FFE661EB6E41__INCLUDED_)
