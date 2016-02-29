///////////////////////////////////////////////////////////
//  WorldObjectRemoveEvent.cpp
//  Implementation of the Class WorldObjectRemoveEvent
//  Created on:      16-Apr-2008 23:56:24
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "WorldObjectRemoveEvent.h"


/**
 * Constructs a removal event of the specified world object.
 * 
 * @param wo
 */
WorldObjectRemoveEvent::WorldObjectRemoveEvent(const WorldObject* wo):
m_worldObject(wo)
{
}


WorldObjectRemoveEvent::~WorldObjectRemoveEvent() {

}


/**
 * Returns the world object that is to be removed from the world (i.e., is not
 * removed *yet*).
 */
const WorldObject* WorldObjectRemoveEvent::getRemoved() const {
	return m_worldObject;
}