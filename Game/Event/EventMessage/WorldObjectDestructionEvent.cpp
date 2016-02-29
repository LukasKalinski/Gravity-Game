///////////////////////////////////////////////////////////
//  WorldObjectDestructionEvent.cpp
//  Implementation of the Class WorldObjectDestructionEvent
//  Created on:      16-Apr-2008 23:56:45
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "WorldObjectDestructionEvent.h"


/**
 * Constructs a destruction event, specifying the destroyed object as well as the
 * world object that caused its destruction.
 * 
 * @param wo
 * @param cause    The world object causing the destruction.
 */
WorldObjectDestructionEvent::WorldObjectDestructionEvent(
	const DestroyableObject* wo, const WorldObject* cause):
m_destroyed(wo),
m_cause(cause)
{
}


WorldObjectDestructionEvent::~WorldObjectDestructionEvent() {

}


/**
 * Returns the object that was destroyed.
 */
const DestroyableObject* WorldObjectDestructionEvent::getDestroyed() const {
	return m_destroyed;
}


/**
 * Returns the object that caused the destruction.
 */
const WorldObject* WorldObjectDestructionEvent::getCause() const {
	return m_cause;
}