///////////////////////////////////////////////////////////
//  SoundManager.h
//  Implementation of the Class SoundManager
//  Created on:      28-mar-2008 10:34:19
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_6CA6FB6F_8240_4c54_A1D1_AEC8D86A8AE2__INCLUDED_)
#define EA_6CA6FB6F_8240_4c54_A1D1_AEC8D86A8AE2__INCLUDED_

#include "Tickable.h"
#include "ProjectileFireListener.h"
#include "WorldObjectDestructionListener.h"
#include "BoingListener.h"

#include "SDL.h"
#include "SDL_mixer.h"

#include <map>

#define GRAVITY_NUM_CHANNELS 15

class GameState;

/**
 * Responsible for monitoring the Game module and playing sounds according to its
 * state.
 */
class SoundManager : 
	public ProjectileFireListener, 
	public WorldObjectDestructionListener,
	public BoingListener
{

public:
	SoundManager::SoundManager(GameState* gs);
	virtual ~SoundManager();
	SoundManager(const SoundManager& sm);

	void init();

	enum {
		SA_NO_SOUND = 0,
		SA_FIRE_LASER = 1,
		SA_FIRE_MISSILE = 2,
		SA_EXPLOSION = 3,
		SA_BOING = 4
	};

	virtual void notifyEvent(const ProjectileFireEvent& ev);
	virtual void notifyEvent(const WorldObjectDestructionEvent& ev);
	virtual void notifyEvent(const BoingEvent& ev);

private:
	void playOnce(unsigned short soundAlias);
	void playRepeat(unsigned short soundAlias);

	static bool m_static_initialized;
	bool m_initialized;

	typedef std::map<unsigned short, Mix_Chunk*> audiomap_t;

	static audiomap_t m_audiomap;
	GameState* m_gameState;

};
#endif // !defined(EA_6CA6FB6F_8240_4c54_A1D1_AEC8D86A8AE2__INCLUDED_)
