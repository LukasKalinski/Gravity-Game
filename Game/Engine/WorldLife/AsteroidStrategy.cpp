///////////////////////////////////////////////////////////
//  AsteroidStrategy.cpp
//  Implementation of the Class AsteroidStrategy
//  Created on:      28-mar-2008 10:23:51
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <time.h>
#include "AsteroidStrategy.h"


/**
 * Constructs an asteroid insertion world strategy, specifying the world time
 * delta to wait between asteroid insertions.
 * 
 * @param timeDelta    The world time delta between asteroid insertions.
 */
AsteroidStrategy::AsteroidStrategy(unsigned int timeDelta):
m_timeInterval(timeDelta),
m_countdown(timeDelta)
{
	srand(static_cast<unsigned int> (time(NULL)));
}


AsteroidStrategy::~AsteroidStrategy() {
}


AsteroidStrategy::AsteroidStrategy(const AsteroidStrategy& strategy):
m_timeInterval(strategy.m_timeInterval),
m_countdown(strategy.m_countdown)
{
}


/**
 * Throws in a pre-defined amount (see constructor) of asteroids into the world on
 * each call. If the defined amount is less than 1, it will mean that an asteroid
 * will not be thrown in on each call, but more rarely.
 */
void AsteroidStrategy::applyWorldStrategy(World& world) {
	if (m_countdown == 0) {
		// Magnitude
		float r1 = 6.0f * (rand() / (float) RAND_MAX);
		// Angle
		float r2 = 3.14f * (rand() / (float) RAND_MAX);
		// Rotation speed
		float r3 = 0.05f * (rand() / (float) RAND_MAX) - 0.025f;

		Asteroid a(r3, 50);

		a.setMovement(Vector2d(r1, r2));

		world.getWorldObjectsManager().queueInsert(a);
		m_countdown = m_timeInterval;
	} else {
		--m_countdown;
	}
}


/**
 * Clones the asteroid strategy, returning the clone.
 */
AsteroidStrategy* AsteroidStrategy::clone() const {
	return new AsteroidStrategy(*this);
}