///////////////////////////////////////////////////////////
//  Tickable.h
//  Implementation of the Interface Tickable
//  Created on:      28-mar-2008 10:35:33
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_B186C818_0987_4ebb_B3F9_6ADA4F611251__INCLUDED_)
#define EA_B186C818_0987_4ebb_B3F9_6ADA4F611251__INCLUDED_

/**
 * When a class object need to receive a tick, it has to implement this interface.
 */
class Tickable
{

public:
	Tickable() {

	}

	virtual ~Tickable() {

	}

	Tickable(const Tickable& theTickable) {

	}

	virtual void tick() =0;

};
#endif // !defined(EA_B186C818_0987_4ebb_B3F9_6ADA4F611251__INCLUDED_)
