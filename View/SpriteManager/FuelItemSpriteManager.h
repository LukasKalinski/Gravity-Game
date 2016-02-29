///////////////////////////////////////////////////////////
//  FuelItemSpriteManager.h
//  Implementation of the Class FuelItemSpriteManager
//  Created on:      28-mar-2008 10:26:18
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_C003C5AB_D824_4a95_9719_290CA464B9F9__INCLUDED_)
#define EA_C003C5AB_D824_4a95_9719_290CA464B9F9__INCLUDED_

#include "WorldSpriteManager.h"
#include "FuelItem.h"

/**
 * Responsible for managing sprites for a fuel item.
 */
class FuelItemSpriteManager : public WorldSpriteManager
{

public:

	FuelItemSpriteManager(const FuelItem* fuelItem);
	virtual ~FuelItemSpriteManager();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual FuelItemSpriteManager* clone() const;

	virtual void init();
};
#endif // !defined(EA_C003C5AB_D824_4a95_9719_290CA464B9F9__INCLUDED_)
