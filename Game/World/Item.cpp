///////////////////////////////////////////////////////////
//  Item.cpp
//  Implementation of the Class Item
//  Created on:      28-mar-2008 10:28:25
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "Item.h"


/**
 * Constructs an item with a pre-defined mass (i.e. 0, as it shouldn't be affected
 * by gravities) and shape (all items have the same size).
 */
Item::Item(): StaticObject(0.0, CircularShape(10.0f)) {
}


Item::~Item() {
}


Item::Item(const Item& item): StaticObject(item) {
}
