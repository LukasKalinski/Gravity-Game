///////////////////////////////////////////////////////////
//  MissileSpriteManager.h
//  Implementation of the Class MissileSpriteManager
//  Created on:      28-mar-2008 10:30:36
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_6E0CCE09_BC0C_454b_B9FA_95EFA3B320D9__INCLUDED_)
#define EA_6E0CCE09_BC0C_454b_B9FA_95EFA3B320D9__INCLUDED_

#include "WorldSpriteManager.h"
#include "MissileProjectile.h"

class Missile;

/**
 * Responsible for managing sprites for a missile.
 */
class MissileSpriteManager : public WorldSpriteManager
{

public:

	/**
	 * 
	 * @param missile
	 */
	MissileSpriteManager(const Missile* missile);

	MissileSpriteManager(const MissileProjectile* missile);
	virtual ~MissileSpriteManager();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual MissileSpriteManager* clone() const;

	virtual void init();
};
#endif // !defined(EA_6E0CCE09_BC0C_454b_B9FA_95EFA3B320D9__INCLUDED_)
