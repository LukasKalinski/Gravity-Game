///////////////////////////////////////////////////////////
//  WorldObjectRemoveEvent.h
//  Implementation of the Class WorldObjectRemoveEvent
//  Created on:      16-Apr-2008 23:56:23
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_E2C93A74_EF5E_435e_97DA_4983EBAFEFFB__INCLUDED_)
#define EA_E2C93A74_EF5E_435e_97DA_4983EBAFEFFB__INCLUDED_

class WorldObject;

/**
 * Represents the event of the world being ordered to remove a world object and
 * provides that object. The removal order will be realized at the end of the
 * world's current tick call. This event should be listened for by all classes
 * that are keeping pointers to world objects, so that they know when to get rid
 * of them.
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:56:23
 */
class WorldObjectRemoveEvent
{

public:

	/**
	 * Constructs a removal event of the specified world object.
	 * 
	 * @param wo
	 */
	WorldObjectRemoveEvent(const WorldObject* wo);

	virtual ~WorldObjectRemoveEvent();

	/**
	 * Returns the world object that is to be removed from the world (i.e., is not
	 * removed *yet*).
	 */
	const WorldObject* getRemoved() const;

private:

	/**
	 * The world object that is ordered to be removed.
	 */
	const WorldObject *m_worldObject;

};
#endif // !defined(EA_E2C93A74_EF5E_435e_97DA_4983EBAFEFFB__INCLUDED_)
