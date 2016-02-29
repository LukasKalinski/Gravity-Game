///////////////////////////////////////////////////////////
//  AsteroidSpriteManager.h
//  Implementation of the Class AsteroidSpriteManager
//  Created on:      28-mar-2008 10:23:38
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_0F47550E_C39E_4228_98F4_EB65655D3E13__INCLUDED_)
#define EA_0F47550E_C39E_4228_98F4_EB65655D3E13__INCLUDED_

#include "WorldSpriteManager.h"
#include "Asteroid.h"
#include "AnimationSprite.h"


/**
 * Responsible for managing sprites for an asteroid.
 */
class AsteroidSpriteManager :
	public WorldSpriteManager,
	public WorldObjectDestructionListener
{

public:

	AsteroidSpriteManager(const Asteroid* asteroid);
	virtual ~AsteroidSpriteManager();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual AsteroidSpriteManager* clone() const;

	virtual void init();
	virtual void update();
	virtual void notifyEvent(const WorldObjectDestructionEvent& ev);

private:

	/**
	 * When animated, this pointer is pointing somewhere.
	 */
	AnimationSprite * m_animationSprite;

};
#endif // !defined(EA_0F47550E_C39E_4228_98F4_EB65655D3E13__INCLUDED_)
