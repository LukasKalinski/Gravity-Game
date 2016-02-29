///////////////////////////////////////////////////////////
//  ProjectileFireEvent.h
//  Implementation of the Class ProjectileFireEvent
//  Created on:      16-Apr-2008 23:56:58
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_EB6EB1CA_4A37_4fdf_B45B_684D30877CA5__INCLUDED_)
#define EA_EB6EB1CA_4A37_4fdf_B45B_684D30877CA5__INCLUDED_

class Ship;
class Projectile;

/**
 * Represents the event of firing a projectile and provides the projectile that
 * was fired as well as the ship that fired it.
 * @author Lukas Kalinski
 * @version 1.0
 * @created 16-Apr-2008 23:56:58
 */
class ProjectileFireEvent
{

public:

	/**
	 * Constructs a projectile fire event, specifying the projectile as well as the
	 * ship that fired it.
	 * 
	 * @param ship
	 * @param projectile
	 */
	ProjectileFireEvent(const Ship* ship, const Projectile* projectile);

	virtual ~ProjectileFireEvent();

	/**
	 * Returns a pointer to the projectile that was fired.
	 */
	const Projectile* getProjectile() const;

	/**
	 * Returns a pointer to the ship that fired the projectile.
	 */
	const Ship* getShip() const;

private:

	/**
	 * The projectile that was fired.
	 */
	const Projectile *m_projectile;

	/**
	 * The ship that fired the projectile.
	 */
	const Ship *m_ship;

};
#endif // !defined(EA_EB6EB1CA_4A37_4fdf_B45B_684D30877CA5__INCLUDED_)
