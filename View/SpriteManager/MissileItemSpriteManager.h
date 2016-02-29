///////////////////////////////////////////////////////////
//  MissileItemSpriteManager.h
//  Implementation of the Class MissileItemSpriteManager
//  Created on:      28-Mar-2008 17:38:26
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_A13CF4B7_7F13_4fe4_AD4B_908B59D078BD__INCLUDED_)
#define EA_A13CF4B7_7F13_4fe4_AD4B_908B59D078BD__INCLUDED_

#include "WorldSpriteManager.h"
#include "MissileItem.h"

/**
 * Responsible for managing sprites for a missile item.
 */
class MissileItemSpriteManager : public WorldSpriteManager
{

public:

	MissileItemSpriteManager(const MissileItem* missileItem);
	virtual ~MissileItemSpriteManager();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual MissileItemSpriteManager* clone() const;

	virtual void init();
};
#endif // !defined(EA_A13CF4B7_7F13_4fe4_AD4B_908B59D078BD__INCLUDED_)
