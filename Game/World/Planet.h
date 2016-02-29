///////////////////////////////////////////////////////////
//  Planet.h
//  Implementation of the Class Planet
//  Created on:      28-mar-2008 10:31:29
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_1A69EB4D_37B8_4bed_A64B_76CD1DC1E42E__INCLUDED_)
#define EA_1A69EB4D_37B8_4bed_A64B_76CD1DC1E42E__INCLUDED_

#include "StaticObject.h"
#include "CircularShape.h"

/**
 * Representation of a planet.
 */
class Planet : public StaticObject
{

public:
	
	enum planet_t { MARS=1, EARTH=2, PLUTO=3 };

	/**
	 * Constructs a new planet specifying its mass and radius.
	 * 
	 * @param mass
	 * @param radius
	 * @param type    See TYPE_* constants.
	 */
	Planet(float mass, float radius, planet_t type);
	virtual ~Planet();
	Planet(const Planet& planet);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual Planet* clone() const;

	planet_t getType() const;

private:

	/**
	 * The planet's type.
	 */
	planet_t m_type;

};
#endif // !defined(EA_1A69EB4D_37B8_4bed_A64B_76CD1DC1E42E__INCLUDED_)
