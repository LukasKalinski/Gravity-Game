///////////////////////////////////////////////////////////
//  WrapBoundaryStrategy.cpp
//  Implementation of the Class WrapBoundaryStrategy
//  Created on:      06-Apr-2008 20:16:35
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

//#define __DEBUG_WRAP_BOUNDARY_STRATEGY
#ifdef __DEBUG_WRAP_BOUNDARY_STRATEGY
#include <iostream>
using namespace std;
#endif

#include "WrapBoundaryStrategy.h"


/**
 * Constructs a wrap boundary strategy.
 */
WrapBoundaryStrategy::WrapBoundaryStrategy() {
}


WrapBoundaryStrategy::~WrapBoundaryStrategy() {
}


WrapBoundaryStrategy::WrapBoundaryStrategy(const WrapBoundaryStrategy& strategy):
BoundaryStrategy(strategy)
{
}


/**
 * Clones the wrap boundary strategy, returning the clone.
 */
WrapBoundaryStrategy* WrapBoundaryStrategy::clone() const {
	return new WrapBoundaryStrategy(*this);
}


/**
 * Checks whether a world object is beyond the world boundaries and does something
 * about it if that's the case.
 * 
 * @param wo
 * @param world
 */
void WrapBoundaryStrategy::manage(WorldObject& wo, World& world) const {

	float wo_x = wo.getPosition().getX();
	float wo_y = wo.getPosition().getY();

	float leftBoundary	= world.getUpperLeft().getX();
	float upperBoundary	= world.getUpperLeft().getY();
	float rightBoundary	= world.getLowerRight().getX();
	float lowerBoundary	= world.getLowerRight().getY();

	// If world object is found outside the horizontal boundaries, then
	// move it to the opposite side:
	if (wo_x < leftBoundary) {

#ifdef __DEBUG_WRAP_BOUNDARY_STRATEGY
		cout << "DEBUG BOUNDARIES: world object outside left boundary" << endl;
#endif

		Coord2d target((rightBoundary-leftBoundary), 0);
		wo.setPosition(wo.getPosition() + target);
	} else if (wo_x > rightBoundary) {

#ifdef __DEBUG_WRAP_BOUNDARY_STRATEGY
		cout << "DEBUG BOUNDARIES: world object outside right boundary" << endl;
#endif

		Coord2d target(-1 * (rightBoundary-leftBoundary), 0);
		wo.setPosition(wo.getPosition() + target);
	}

	// If world object is found outside the vertical boundaries, then
	// move it to the opposite side:
	if (wo_y > lowerBoundary) {

#ifdef __DEBUG_WRAP_BOUNDARY_STRATEGY
		cout << "DEBUG BOUNDARIES: world object outside lower boundary" << endl;
#endif

		Coord2d target(0, -1 * (lowerBoundary-upperBoundary));
		wo.setPosition(wo.getPosition() + target);
	} else if (wo_y < upperBoundary) {

#ifdef __DEBUG_WRAP_BOUNDARY_STRATEGY
		cout << "DEBUG BOUNDARIES: world object outside upper boundary" << endl;
#endif

		Coord2d target(0, (lowerBoundary-upperBoundary));
		wo.setPosition(wo.getPosition() + target);
	}
}