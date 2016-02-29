///////////////////////////////////////////////////////////
//  WorldObjectDestructionEvent.h
//  Implementation of the Class WorldObjectDestructionEvent
//  Created on:      16-Apr-2008 23:56:44
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_9ECE5451_FE18_4bea_B98B_E9455EE9C8A5__INCLUDED_)
#define EA_9ECE5451_FE18_4bea_B98B_E9455EE9C8A5__INCLUDED_

class WorldObject;
class DestroyableObject;

/**
 * Represents a destruction event and provides the destroyable object that was
 * destroyed as well as the world object that caused its destruction (by, for
 * example, colliding with it). A destruction event must not be treated as a
 * RemovalOrderEvent, and vice versa, as a destruction doesn't necessarily mean
 * that the object will be removed before next tick.
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:56:44
 */
class WorldObjectDestructionEvent
{

public:

	/**
	 * Constructs a destruction event, specifying the destroyed object as well as the
	 * world object that caused its destruction.
	 * 
	 * @param wo
	 * @param cause    The world object causing the destruction.
	 */
	WorldObjectDestructionEvent(const DestroyableObject* wo, const WorldObject* cause);
	
	virtual ~WorldObjectDestructionEvent();

	/**
	 * Returns the object that was destroyed.
	 */
	const DestroyableObject* getDestroyed() const;

	/**
	 * Returns the object that caused the destruction.
	 */
	const WorldObject* getCause() const;

private:

	/**
	 * The destroyable world object that was destroyed.
	 */
	const DestroyableObject *m_destroyed;

	/**
	 * The world object causing the destruction.
	 */
	const WorldObject *m_cause;

};
#endif // !defined(EA_9ECE5451_FE18_4bea_B98B_E9455EE9C8A5__INCLUDED_)
