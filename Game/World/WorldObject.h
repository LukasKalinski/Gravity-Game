///////////////////////////////////////////////////////////
//  WorldObject.h
//  Implementation of the Class WorldObject
//  Created on:      28-mar-2008 10:36:17
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_1EEA95B7_587E_4fcd_BC27_EC5F3DE2EDB7__INCLUDED_)
#define EA_1EEA95B7_587E_4fcd_BC27_EC5F3DE2EDB7__INCLUDED_

#include "Shape.h"
#include "Vector2d.h"
#include "Tickable.h"
#include "CollisionHelper.h"

/**
 * Contains common behavior and properties of game world objects.
 */
class WorldObject : public Tickable
{

public:

	WorldObject(float mass, const Shape& shape);
	virtual ~WorldObject();
	WorldObject(const WorldObject& wo);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual WorldObject* clone() const = 0;
	
	float getMass() const;
	const Vector2d& getPosition() const;

	/**
	 * Returns the shape of the object, i.e., a representation of its spacial form and
	 * size, for example a circular shape with a radius.
	 */
	const Shape& getShape() const;

	virtual void setPosition(const Vector2d& v);
	virtual void tick();

	/**
	 * Initializes the world object, making it aware that it now is present in a world
	 * environment.
	 */
	virtual void init();

	/**
	 * Tells whether the world object is initialized or not, i.e., whether it is
	 * placed in a world (=has a valid position).
	 */
	bool isInitialized() const;

	/**
	 * Handles collision with a generic world object.
	 * 
	 * @param with
	 */
	virtual void handleCollision(WorldObject* with);

	/**
	 * Sets the collision helper that the world object should use in order to detect
	 * collisions.
	 * 
	 * @param cp
	 */
	void setCollisionHelper(CollisionHelper* cp);

protected:

	/**
	 * The mass of the world object. This may be used for gravity calculations. In
	 * order to have an object that is not affected by gravities, it's mass should be
	 * zero.
	 */
	float m_mass;

	/**
	 * The coordinate of the object in the world.
	 */
	Vector2d m_position;

	/**
	 * The shape of the world object.
	 */
	Shape *m_shape;

	/**
	 * Tells whether the world object is initialized or not. Initialized means that it
	 * is completely setup and exists in a world.
	 */
	bool m_initialized;

	/**
	 * The collision helper to use in order to tell whether the world object is
	 * colliding with other world objects or not.
	 */
	CollisionHelper *m_collisionHelper;

};
#endif // !defined(EA_1EEA95B7_587E_4fcd_BC27_EC5F3DE2EDB7__INCLUDED_)
