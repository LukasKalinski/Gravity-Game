///////////////////////////////////////////////////////////
//  AsteroidStrategy.h
//  Implementation of the Class AsteroidStrategy
//  Created on:      28-mar-2008 10:23:46
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_7655731F_FE2A_441a_B28C_0C916B0AAF71__INCLUDED_)
#define EA_7655731F_FE2A_441a_B28C_0C916B0AAF71__INCLUDED_

#include "WorldStrategy.h"
#include "World.h"

/**
 * Responsible for providing the world with asteroids, based on time-based
 * constraints.
 */
class AsteroidStrategy : public WorldStrategy
{

public:

	/**
	 * Constructs an asteroid insertion world strategy, specifying the world time
	 * delta to wait between asteroid insertions.
	 * 
	 * @param timeDelta    The world time delta between asteroid insertions.
	 */
	AsteroidStrategy(unsigned int timeDelta);

	virtual ~AsteroidStrategy();
	AsteroidStrategy(const AsteroidStrategy& strategy);

	virtual void applyWorldStrategy(World& world);

	/**
	 * Clones the asteroid strategy, returning the clone.
	 */
	virtual AsteroidStrategy* clone() const;

private:

	/**
	 * Ticks between asteroid insertions.
	 */
	unsigned int m_timeInterval;

	/**
	 * Ticks left until next asteroid insertion.
	 */
	unsigned int m_countdown;

};
#endif // !defined(EA_7655731F_FE2A_441a_B28C_0C916B0AAF71__INCLUDED_)
