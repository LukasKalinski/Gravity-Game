///////////////////////////////////////////////////////////
//  MissileItem.cpp
//  Implementation of the Class MissileItem
//  Created on:      28-mar-2008 10:30:26
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "MissileItem.h"


/**
 * Constructs a new missile item, specifying how many missiles it should contain.
 */
MissileItem::MissileItem(unsigned int numMissiles) {
}


MissileItem::~MissileItem() {
}


MissileItem::MissileItem(const MissileItem& item):
m_numMissiles(item.m_numMissiles) {
}


/**
 * Clones the world object, returning a pointer to the clone.
 */
MissileItem* MissileItem::clone() const {
	return new MissileItem(*this);
}


/**
 * Returns the number of missiles in this item.
 */
unsigned int MissileItem::getMissileCount() {
	return m_numMissiles;
}