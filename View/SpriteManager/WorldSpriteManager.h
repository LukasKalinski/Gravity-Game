///////////////////////////////////////////////////////////
//  WorldSpriteManager.h
//  Implementation of the Class WorldSpriteManager
//  Created on:      01-apr-2008 16:02:19
//  Original author: Jesper
///////////////////////////////////////////////////////////

#if !defined(EA_D598D85D_1A5A_4571_9328_EF17E897DA5C__INCLUDED_)
#define EA_D598D85D_1A5A_4571_9328_EF17E897DA5C__INCLUDED_

#include "SpriteManager.h"
#include "Coord2d.h"
#include "WorldObject.h"

/**
 * Handles sprites for general world objects.
 */
class WorldSpriteManager :
	public SpriteManager,
	public WorldObjectRemoveListener
{

public:

	WorldSpriteManager(const WorldObject* wo);
	virtual ~WorldSpriteManager();
	WorldSpriteManager(const WorldSpriteManager& sm);
	virtual WorldSpriteManager* clone() const = 0;
	virtual void init();
	virtual void update();
	virtual void notifyEvent(const WorldObjectRemoveEvent& ev);

protected:

	/**
	 * The monitored world object.
	 */
	const WorldObject * m_worldObject;

};
#endif // !defined(EA_D598D85D_1A5A_4571_9328_EF17E897DA5C__INCLUDED_)
