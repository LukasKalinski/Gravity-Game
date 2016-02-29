///////////////////////////////////////////////////////////
//  SpawnPoint.h
//  Implementation of the Class SpawnPoint
//  Created on:      28-mar-2008 10:34:29
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_110DC285_AAC8_4117_9A43_712F4E2DCE51__INCLUDED_)
#define EA_110DC285_AAC8_4117_9A43_712F4E2DCE51__INCLUDED_

#include "StaticObject.h"
#include "CircularShape.h"

/**
 * Defines a point in which a world object may appear, telling whether the area is
 * free of obstacles or not.
 */
class SpawnPoint : public StaticObject
{

public:

	SpawnPoint();
	virtual ~SpawnPoint();
	SpawnPoint(const SpawnPoint& sp);

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual SpawnPoint* clone() const;

	bool isFree() const;
	void toggleAvailability(bool setFree);

	virtual void tick();

private:

	/**
	 * Whether the spawn point is free or not.
	 */
	bool m_isFree;

};
#endif // !defined(EA_110DC285_AAC8_4117_9A43_712F4E2DCE51__INCLUDED_)
