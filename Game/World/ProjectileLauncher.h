///////////////////////////////////////////////////////////
//  ProjectileLauncher.h
//  Implementation of the Interface ProjectileLauncher
//  Created on:      01-Apr-2008 00:37:20
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_ED8BB83E_C621_4db0_AB33_525CE44C539E__INCLUDED_)
#define EA_ED8BB83E_C621_4db0_AB33_525CE44C539E__INCLUDED_

class Ship;
class Projectile;

/**
 * @author Lukas Kalinski
 * @version 1.0
 * @created 01-Apr-2008 00:37:20
 */
class ProjectileLauncher
{

public:
	/**
	 * Launches a projectile, i.e., inserts it into the world and cascades a
	 * ProjectileFireEvent.
	 * 
	 * @param firingShip
	 * @param projectile
	 */
	virtual void launch(const Ship* firingShip, const Projectile& projectile) = 0;

};
#endif // !defined(EA_ED8BB83E_C621_4db0_AB33_525CE44C539E__INCLUDED_)
