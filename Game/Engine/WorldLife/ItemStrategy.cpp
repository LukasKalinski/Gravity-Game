///////////////////////////////////////////////////////////
//  ItemStrategy.cpp
//  Implementation of the Class ItemStrategy
//  Created on:      28-mar-2008 10:28:41
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "ItemStrategy.h"


ItemStrategy::ItemStrategy() {

}


ItemStrategy::~ItemStrategy() {

}


ItemStrategy::ItemStrategy(const ItemStrategy& strategy) {

}


/**
 * Checks if there are items that should be inserted into the world, and does
 * insert them if found.
 */
void ItemStrategy::applyWorldStrategy(World& world) {

}


/**
 * Registers an item, specifying the time interval between its insertions into the
 * world.
 * 
 * @param item		Item template
 * @param interval    World time delta between insertions.
 */
void ItemStrategy::registerItem(const Item& item, unsigned int interval) {

}


/**
 * Clones the item strategy, returning the clone.
 */
ItemStrategy* ItemStrategy::clone() const {
	return new ItemStrategy(*this);
}