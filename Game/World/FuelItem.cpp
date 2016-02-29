///////////////////////////////////////////////////////////
//  FuelItem.cpp
//  Implementation of the Class FuelItem
//  Created on:      28-mar-2008 10:26:15
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "FuelItem.h"


/**
 * Constructs a new fuel item, specifying the fuel amount it should contain.
 */
FuelItem::FuelItem(unsigned int amount) {
}


FuelItem::~FuelItem() {
}


FuelItem::FuelItem(const FuelItem& item):
m_fuelAmount(item.m_fuelAmount) {
}


/**
 * Clones the world object, returning a pointer to the clone.
 */
FuelItem* FuelItem::clone() const {
	return new FuelItem(*this);
}


/**
 * Returns the amount of fuel in this item.
 */
unsigned int FuelItem::getFuelAmount() {
	return m_fuelAmount;
}