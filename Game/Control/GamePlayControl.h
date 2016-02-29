///////////////////////////////////////////////////////////
//  GamePlayControl.h
//  Implementation of the Class GamePlayControl
//  Created on:      28-mar-2008 10:27:05
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_F9CF2473_2965_4cef_B819_EB8B7FD00B68__INCLUDED_)
#define EA_F9CF2473_2965_4cef_B819_EB8B7FD00B68__INCLUDED_

#include "GameControl.h"

/**
 * Abstract class for controls that manipulate the game play state (e.g., ship
 * steering).
 */
class GamePlayControl : public GameControl
{

public:

	GamePlayControl();
	virtual ~GamePlayControl();

	/**
	 * Clones the game play control, returning a pointer to the clone.
	 */
	virtual GamePlayControl* clone() const = 0;

};
#endif // !defined(EA_F9CF2473_2965_4cef_B819_EB8B7FD00B68__INCLUDED_)
