///////////////////////////////////////////////////////////
//  MovableObject.h
//  Implementation of the Class MovableObject
//  Created on:      28-mar-2008 10:30:44
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_37814BBE_9FBC_448d_9C37_F9249BCC6D68__INCLUDED_)
#define EA_37814BBE_9FBC_448d_9C37_F9249BCC6D68__INCLUDED_

#include "Vector2d.h"
#include "WorldObject.h"

/**
 * Contains common behavior and properties of movable game world objects.
 */
class MovableObject : public WorldObject
{

public:

	/**
	 * Constructs a movable object.
	 * 
	 * @param mass
	 * @param shape
	 */
	MovableObject(float mass, const Shape& shape);
	virtual ~MovableObject();
	MovableObject(const MovableObject& mwo);

	/**
	 * Clones the movable world object, returning a pointer to the clone.
	 */
	virtual MovableObject* clone() const = 0;

	const Vector2d& getMovement() const;
	virtual void setMovement(const Vector2d& movement);
	virtual void tick();

protected:
	/**
	 * The movement of the movable object, represented by a vector.
	 */
	Vector2d m_movement;

};
#endif // !defined(EA_37814BBE_9FBC_448d_9C37_F9249BCC6D68__INCLUDED_)
