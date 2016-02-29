///////////////////////////////////////////////////////////
//  DestroyableObject.h
//  Implementation of the Class DestroyableObject
//  Created on:      28-mar-2008 10:25:17
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_6CE30512_9DCE_4384_9914_E61AECA5D786__INCLUDED_)
#define EA_6CE30512_9DCE_4384_9914_E61AECA5D786__INCLUDED_

#include <exception>

/**
 * World objects implementing this interface are considered destroyable, i.e., it
 * is possible to destroy them by causing enough damage to them. Note that
 * destruction has nothing to do with removal from the world.
 */
class DestroyableObject
{

public:
	DestroyableObject(float strength);
	virtual ~DestroyableObject();
	DestroyableObject(const DestroyableObject& theDestroyableObject);

	virtual void destroy();
	virtual bool isDestroyed();
	virtual void reduceStrength(float withAmount);

private:
	/**
	 * The remaining strength of the object.
	 */
	float m_strength;

};
#endif // !defined(EA_6CE30512_9DCE_4384_9914_E61AECA5D786__INCLUDED_)
