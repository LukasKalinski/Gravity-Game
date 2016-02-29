///////////////////////////////////////////////////////////
//  PlanetSpriteManager.h
//  Implementation of the Class PlanetSpriteManager
//  Created on:      28-mar-2008 10:31:37
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_25B831F4_A812_4a17_914D_8C62139E7333__INCLUDED_)
#define EA_25B831F4_A812_4a17_914D_8C62139E7333__INCLUDED_

#include "WorldSpriteManager.h"
#include "Planet.h"

/**
 * Responsible for managing sprites for a planet.
 */
class PlanetSpriteManager : public WorldSpriteManager
{

public:

	PlanetSpriteManager(const Planet* planet);
	virtual ~PlanetSpriteManager();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual PlanetSpriteManager* clone() const;

	virtual void init();

private:

	/**
	 * The type of the planet that we are monitoring.
	 */
	Planet::planet_t m_planetType;
};
#endif // !defined(EA_25B831F4_A812_4a17_914D_8C62139E7333__INCLUDED_)
