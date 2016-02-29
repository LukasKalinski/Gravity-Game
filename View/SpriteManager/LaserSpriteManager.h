///////////////////////////////////////////////////////////
//  LaserSpriteManager.h
//  Implementation of the Class LaserSpriteManager
//  Created on:      28-mar-2008 10:29:02
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_A4E951D4_23DB_425f_9642_6CD5C6AF11CA__INCLUDED_)
#define EA_A4E951D4_23DB_425f_9642_6CD5C6AF11CA__INCLUDED_

#include "WorldSpriteManager.h"
#include "LaserProjectile.h"

/**
 * Responsible for managing sprites for a laser.
 */
class LaserSpriteManager : public WorldSpriteManager
{

public:

	LaserSpriteManager(const LaserProjectile* laser);
	virtual ~LaserSpriteManager();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual LaserSpriteManager* clone() const;

	virtual void init();

private:

	/**
	 * The monitored laser.
	 */
	const LaserProjectile * m_laser;
};
#endif // !defined(EA_A4E951D4_23DB_425f_9642_6CD5C6AF11CA__INCLUDED_)
