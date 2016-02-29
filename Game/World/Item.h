///////////////////////////////////////////////////////////
//  Item.h
//  Implementation of the Class Item
//  Created on:      28-mar-2008 10:28:22
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_F7F4272D_BFB2_40e6_AE78_207F6B549B6D__INCLUDED_)
#define EA_F7F4272D_BFB2_40e6_AE78_207F6B549B6D__INCLUDED_

#include "StaticObject.h"
#include "CircularShape.h"

/**
 * Contains common behavior and properties of items occuring in the game world.
 */
class Item : public StaticObject
{
public:
	Item();
	virtual ~Item();
	Item(const Item& item);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual Item* clone() const = 0;

};
#endif // !defined(EA_F7F4272D_BFB2_40e6_AE78_207F6B549B6D__INCLUDED_)
