///////////////////////////////////////////////////////////
//  StaticObject.h
//  Implementation of the Class StaticObject
//  Created on:      28-mar-2008 10:35:19
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_D268FC8E_F9F3_42ec_A9BD_BE67D003C0D7__INCLUDED_)
#define EA_D268FC8E_F9F3_42ec_A9BD_BE67D003C0D7__INCLUDED_

#include "WorldObject.h"

/**
 * Contains common behavior and properties of static game world objects.
 */
class StaticObject : public WorldObject
{

public:
	StaticObject(float mass, const Shape& shape);
	virtual ~StaticObject();
	StaticObject(const StaticObject& so);

	/**
	 * Clones the static world object, returning a pointer to the clone.
	 */
	virtual StaticObject* clone() const = 0;

};
#endif // !defined(EA_D268FC8E_F9F3_42ec_A9BD_BE67D003C0D7__INCLUDED_)
