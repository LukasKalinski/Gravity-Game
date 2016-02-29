///////////////////////////////////////////////////////////
//  SpawnPointSpriteManager.h
//  Implementation of the Class SpawnPointSpriteManager
//  Created on:      28-mar-2008 10:34:37
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_9A79CD29_CC87_40bd_ABF6_9757CED23BC6__INCLUDED_)
#define EA_9A79CD29_CC87_40bd_ABF6_9757CED23BC6__INCLUDED_

#include "WorldSpriteManager.h"
#include "SpawnPoint.h"

/**
 * Responsible for managing sprites for a spawn point.
 */
class SpawnPointSpriteManager : public WorldSpriteManager
{

public:
	SpawnPointSpriteManager(const SpawnPoint* spawnPoint);
	virtual ~SpawnPointSpriteManager();

	virtual void init();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual SpawnPointSpriteManager* clone() const;

	virtual void update();

private:

	/**
	 * The monitored spawn point.
	 */
	const SpawnPoint * m_spawnPoint;

	/**
	 * The currently used sprite.
	 */
	Sprite m_currentSprite;
};
#endif // !defined(EA_9A79CD29_CC87_40bd_ABF6_9757CED23BC6__INCLUDED_)
