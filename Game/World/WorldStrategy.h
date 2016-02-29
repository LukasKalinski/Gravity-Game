///////////////////////////////////////////////////////////
//  WorldStrategy.h
//  Implementation of the Interface WorldStrategy
//  Created on:      28-mar-2008 10:36:27
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_A96502E4_2F34_442f_BED8_A141F8956B8C__INCLUDED_)
#define EA_A96502E4_2F34_442f_BED8_A141F8956B8C__INCLUDED_

class World;

/**
 * Interface implemented by classes that need to manage the world by applying self-
 * defined strategies on it.
 */
class WorldStrategy
{

public:

	virtual WorldStrategy * clone() const = 0;
	virtual void applyWorldStrategy(World& world) = 0;

};
#endif // !defined(EA_A96502E4_2F34_442f_BED8_A141F8956B8C__INCLUDED_)
