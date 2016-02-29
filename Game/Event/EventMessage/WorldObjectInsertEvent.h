///////////////////////////////////////////////////////////
//  WorldObjectInsertEvent.h
//  Implementation of the Class WorldObjectInsertEvent
//  Created on:      16-Apr-2008 23:56:03
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_F5D0091E_A5D1_4c98_A538_C8D4E03BE69A__INCLUDED_)
#define EA_F5D0091E_A5D1_4c98_A538_C8D4E03BE69A__INCLUDED_

class WorldObject;

/**
 * Represents the event of a world object being inserted into the game world (i.e.,
 * not queued for insertion!).
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:56:03
 */
class WorldObjectInsertEvent
{

public:

	/**
	 * Constructs a world insertion event.
	 * 
	 * @param wo
	 */
	WorldObjectInsertEvent(WorldObject* wo);

	virtual ~WorldObjectInsertEvent();

	/**
	 * Returns the world object that was inserted into the world.
	 */
	const WorldObject* getInserted() const;

	/**
	 * Returns the world object that was inserted into the world.
	 */
	WorldObject* getInserted();

private:

	/**
	 * The inserted world object.
	 */
	WorldObject *m_inserted;

};
#endif // !defined(EA_F5D0091E_A5D1_4c98_A538_C8D4E03BE69A__INCLUDED_)
