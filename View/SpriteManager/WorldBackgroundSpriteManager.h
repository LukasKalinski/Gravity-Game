///////////////////////////////////////////////////////////
//  WorldBackgroundSpriteManager.h
//  Implementation of the Class WorldBackgroundSpriteManager
//  Created on:      30-Apr-2008 17:20:04
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_D525993C_8C7D_496e_8882_DD5EA069F581__INCLUDED_)
#define EA_D525993C_8C7D_496e_8882_DD5EA069F581__INCLUDED_

#include "SpriteManager.h"

class World;

/**
 * @author Lukas Kalinski
 * @version 1.0
 * @created 30-Apr-2008 17:20:04
 */
class WorldBackgroundSpriteManager : public SpriteManager
{

public:

	/**
	 * Constructs a sprite manager for the world background, having the world
	 * specified.
	 * 
	 * @param world
	 */
	WorldBackgroundSpriteManager(const World* world);

	virtual ~WorldBackgroundSpriteManager();

	/**
	 * Initializes the sprite manager.
	 */
	virtual void init();

	/**
	 * Clones the world background sprite manager, returning a pointer to the clone.
	 */
	virtual WorldBackgroundSpriteManager * clone() const;

private:

	/**
	 * The world that we're representing.
	 */
	const World *m_world;

};
#endif // !defined(EA_D525993C_8C7D_496e_8882_DD5EA069F581__INCLUDED_)
