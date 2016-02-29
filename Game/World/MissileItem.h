///////////////////////////////////////////////////////////
//  MissileItem.h
//  Implementation of the Class MissileItem
//  Created on:      28-mar-2008 10:30:22
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_4C81A58B_99B1_42b6_B781_7152FBEFC52C__INCLUDED_)
#define EA_4C81A58B_99B1_42b6_B781_7152FBEFC52C__INCLUDED_

#include "Item.h"

/**
 * Representation of an item that contains ship missiles.
 */
class MissileItem : public Item
{

public:
	MissileItem(unsigned int numMissiles);
	virtual ~MissileItem();
	MissileItem(const MissileItem& item);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual MissileItem* clone() const;

	unsigned int getMissileCount();

private:
	/**
	 * Numer of missiles in this weapon item.
	 */
	unsigned int m_numMissiles;

};
#endif // !defined(EA_4C81A58B_99B1_42b6_B781_7152FBEFC52C__INCLUDED_)
