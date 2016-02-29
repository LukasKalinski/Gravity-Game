///////////////////////////////////////////////////////////
//  SoundManager.cpp
//  Implementation of the Class SoundManager
//  Created on:      28-mar-2008 10:34:25
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "SoundManager.h"
#include "GameState.h"
#include "PlayState.h"
#include "Engine.h"


#include <iostream>
#include <exception>

bool SoundManager::m_static_initialized = false;
SoundManager::audiomap_t SoundManager::m_audiomap;



SoundManager::SoundManager(GameState* gs):
m_gameState(gs), m_initialized(false)
{
	if(!m_static_initialized) {

		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 128);

		Mix_Chunk* chunk;

		Mix_AllocateChannels(GRAVITY_NUM_CHANNELS);

		chunk = Mix_LoadWAV("sound/laser.wav");
		m_audiomap[SA_FIRE_LASER] = chunk;

		if(!chunk)
			std::cout << "Problem loading laser.wav: " << Mix_GetError() << std::endl;

		chunk = Mix_LoadWAV("sound/missile.wav");
		m_audiomap[SA_FIRE_MISSILE] = chunk;

		if(!chunk)
			std::cout << "Problem loading missile.wav: " << Mix_GetError() << std::endl;

		chunk = Mix_LoadWAV("sound/explosion.wav");
		m_audiomap[SA_EXPLOSION] = chunk;

		if(!chunk)
			std::cout << "Problem loading explosion.wav: " << Mix_GetError() << std::endl;

		chunk = Mix_LoadWAV("sound/boing.wav");
		m_audiomap[SA_BOING] = chunk;

		if(!chunk)
			std::cout << "Problem loading boing.wav: " << Mix_GetError() << std::endl;

		// atexit(Mix_CloseAudio);
		m_static_initialized = true;
	}
}


SoundManager::~SoundManager() {
	if(m_initialized && m_gameState) {
		if(PlayState* ps = dynamic_cast<PlayState*>(m_gameState)) {
			ps->getEventManager()->unregisterProjectileFireListener(this);
			ps->getEventManager()->unregisterWorldObjectDestructionListener(this);
			ps->getEventManager()->unregisterBoingListener(this);
		}
	}

}


SoundManager::SoundManager(const SoundManager& sm)
{
	throw std::exception("SoundManager::SoundManager(const SoundManager& sm) called.");
}


void SoundManager::init() {

	if(!m_gameState) {
		throw std::exception("SoundManager::init(): No gamestate!!!!111!! ");
	}

	if(m_initialized) {
		throw std::exception("SoundManager::init(): allready initialized.");
	}

	if(PlayState* ps = dynamic_cast<PlayState*>(m_gameState)) {
		ps->getEventManager()->registerProjectileFireListener(this);
		ps->getEventManager()->registerWorldObjectDestructionListener(this);
		ps->getEventManager()->registerBoingListener(this);
	}

	m_initialized = true;

}


/**
 * Plays a sound once.
 */
void SoundManager::playOnce(unsigned short soundAlias) {
	// Find a channel.
	int channel=-1;
	for(int i=0; i <GRAVITY_NUM_CHANNELS; ++i) {
		if(!Mix_Playing(i)) {
			channel = i;
			break;
		}
	}
	// See if we got a channel...
	if(channel != -1) {
		audiomap_t::iterator it=m_audiomap.find(soundAlias); 
		if(it!=m_audiomap.end()) {
			Mix_PlayChannel(channel, (*it).second, 0);
		}
	} else {
		// std::cout << "SoundManager::playOnce() no channels left!!!" << std::endl;
	}
}


/**
 * Plays a sound by repeating it.
 */
void SoundManager::playRepeat(unsigned short soundAlias) {

}

void SoundManager::notifyEvent(const ProjectileFireEvent& ev) {
	// float distance = (ev.getProjectile()->getPosition() - ev.getShip()->getPosition()).length();
	if(const LaserProjectile* lp = dynamic_cast<const LaserProjectile*> (ev.getProjectile())) {
		playOnce(SA_FIRE_LASER);
	} else if(const MissileProjectile* mp = dynamic_cast<const MissileProjectile*> (ev.getProjectile())) {
		playOnce(SA_FIRE_MISSILE);
	}
}

void SoundManager::notifyEvent(const WorldObjectDestructionEvent& ev) {
	if(dynamic_cast<const Ship*>(ev.getDestroyed())) {
		playOnce(SA_EXPLOSION);
		return;
	}


	Coord2d boom_pos = ev.getCause()->getPosition();


	if(PlayState* ps = dynamic_cast<PlayState*> (m_gameState)) {
		Engine::players_t playas = ps->getEngine().getPlayers(); 

		if((playas.size() >= 1 &&
			playas[0]->getCurrentShip() &&
			((playas[0]->getCurrentShip()->getPosition() - boom_pos).getLength() < 500.0f)) ||
			(playas.size() >= 2 && playas[1]->getCurrentShip() &&
			((playas[1]->getCurrentShip()->getPosition() - boom_pos).getLength() < 500.0f))) {
				playOnce(SA_EXPLOSION);
		}
	}
}


/**
 * Catch event for ships bumping into ships.
 */
void SoundManager::notifyEvent(const BoingEvent& ev) {
	playOnce(SA_BOING);
}