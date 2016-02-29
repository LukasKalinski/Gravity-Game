///////////////////////////////////////////////////////////
//  FuelItem.h
//  Implementation of the Class FuelItem
//  Created on:      28-mar-2008 10:26:11
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_6ABF614F_9EDE_44ca_8E1D_7918158B28AE__INCLUDED_)
#define EA_6ABF614F_9EDE_44ca_8E1D_7918158B28AE__INCLUDED_

#include "Item.h"

/**
 * Representation of an item that contains a fuel powerup.
 */
class FuelItem : public Item
{

public:
	FuelItem(unsigned int amount);
	virtual ~FuelItem();
	FuelItem(const FuelItem& theFuelItem);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual FuelItem* clone() const;

	unsigned int getFuelAmount();

private:
	/**
	 * The fuel amount that the fuel item contains.
	 */
	unsigned int m_fuelAmount;

};
#endif // !defined(EA_6ABF614F_9EDE_44ca_8E1D_7918158B28AE__INCLUDED_)
