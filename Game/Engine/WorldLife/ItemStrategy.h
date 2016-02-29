///////////////////////////////////////////////////////////
//  ItemStrategy.h
//  Implementation of the Class ItemStrategy
//  Created on:      28-mar-2008 10:28:36
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_4B6A8959_D396_4b2b_AA85_8B543C13D6BB__INCLUDED_)
#define EA_4B6A8959_D396_4b2b_AA85_8B543C13D6BB__INCLUDED_

#include "WorldStrategy.h"
#include "World.h"

/**
 * Responsible for providing the world with items, based on time-based constraints.
 */
class ItemStrategy : public WorldStrategy
{

public:
	ItemStrategy();
	virtual ~ItemStrategy();
	ItemStrategy(const ItemStrategy& strategy);

	virtual void applyWorldStrategy(World& world);

	/**
	 * Registers an item, specifying the time interval between its insertions into the
	 * world.
	 * 
	 * @param item		Item template
	 * @param interval    World time delta between insertions.
	 */
	void registerItem(const Item& item, unsigned int interval);

	/**
	 * Clones the item strategy, returning the clone.
	 */
	virtual ItemStrategy* clone() const;

private:

	// FIXME: add vars...

};
#endif // !defined(EA_4B6A8959_D396_4b2b_AA85_8B543C13D6BB__INCLUDED_)
