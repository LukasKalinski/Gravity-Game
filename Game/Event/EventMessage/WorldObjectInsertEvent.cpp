///////////////////////////////////////////////////////////
//  WorldObjectInsertEvent.cpp
//  Implementation of the Class WorldObjectInsertEvent
//  Created on:      16-Apr-2008 23:56:04
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "WorldObjectInsertEvent.h"


/**
 * Constructs a world insertion event.
 * 
 * @param wo
 */
WorldObjectInsertEvent::WorldObjectInsertEvent(WorldObject* wo):
m_inserted(wo)
{
}


WorldObjectInsertEvent::~WorldObjectInsertEvent() {

}


/**
 * Returns the world object that was inserted into the world.
 */
const WorldObject* WorldObjectInsertEvent::getInserted() const {
	return m_inserted;
}


/**
 * Returns the world object that was inserted into the world.
 */
WorldObject* WorldObjectInsertEvent::getInserted() {
	return m_inserted;
}