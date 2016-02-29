///////////////////////////////////////////////////////////
//  GravityStrategy.h
//  Implementation of the Class GravityStrategy
//  Created on:      28-mar-2008 10:27:29
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_BA2D437B_BAE3_441f_AA60_7CD7AEE92D26__INCLUDED_)
#define EA_BA2D437B_BAE3_441f_AA60_7CD7AEE92D26__INCLUDED_

#include "WorldStrategy.h"
#include "World.h"
#include "MovableObject.h"
#include "Planet.h"

/**
 * Responsible for calculating and applying gravity affections for each gravity-
 * affectable game world object.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 17-Apr-2008 03:06:23
 */
class GravityStrategy : public WorldStrategy
{

public:
	GravityStrategy();
	virtual ~GravityStrategy();
	//GravityStrategy(const GravityStrategy& strategy);

	virtual void applyWorldStrategy(World& world);

	/**
	 * Clones the gravity strategy, returning the clone.
	 */
	virtual GravityStrategy* clone() const;

private:

	void affect(const WorldObject& wo1, const WorldObject& wo2);
	void affect(MovableObject& mwo, const Planet& swo);

};
#endif // !defined(EA_BA2D437B_BAE3_441f_AA60_7CD7AEE92D26__INCLUDED_)
