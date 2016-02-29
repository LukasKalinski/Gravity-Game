///////////////////////////////////////////////////////////
//  Ship.h
//  Implementation of the Class Ship
//  Created on:      28-mar-2008 10:33:10
//  Original author: sfish
///////////////////////////////////////////////////////////

#if !defined(EA_E95FDF38_3C73_4fb8_AA00_783DB8775233__INCLUDED_)
#define EA_E95FDF38_3C73_4fb8_AA00_783DB8775233__INCLUDED_

#include <algorithm>
#include <exception>

#include "MovableObject.h"
#include "DestroyableObject.h"
#include "CircularShape.h"
#include "LaserProjectile.h"
#include "MissileProjectile.h"
#include "ProjectileLauncher.h"


/**
 * Representation of the ship that a game player will control.
 */
class Ship : public MovableObject, public DestroyableObject
{

public:

	enum color_t {
		RED = 1,
		BLUE = 2
	};

	/**
	 * Constructs a ship.
	 */
	Ship(color_t color);

	virtual ~Ship();
	Ship(const Ship& ship);

	unsigned int getFuelLevel();
	unsigned int getLasersCount();
	unsigned int getMissilesCount();
	bool hasLimitedFuel();
	bool hasLimitedLasers();
	bool hasLimitedMissiles();

	void setLimitFuel(bool doLimit);
	void setLimitLasers(bool doLimit);
	void setLimitMissiles(bool doLimit);
	color_t getColor() const;
	virtual void tick();
	void toggleLaserGun(bool doFire);
	void toggleMissileLauncher(bool doFire);
	void toggleThrottle(bool doThrottle);
	void toggleTurnLeft(bool doTurn);
	void toggleTurnRight(bool doTurn);

	bool isThrottling() const;

	/**
	 * Initializes the ship. Requires a ProjectileLauncher to be present.
	 */
	virtual void init();

	/**
	 * Tells whether the laser gun is charged or not.
	 */
	bool laserGunCharged();

	/**
	 * Tells whether the missile launcher is charged or not.
	 */
	bool missileLauncherCharged();

	/**
	 * Clones the world object, returning a pointer to the clone.
	 */
	virtual Ship* clone() const;

	/**
	 * Sets the projectile launcher that the ship should use in order to fire
	 * projectiles.
	 * 
	 * @param launcher
	 */
	void setProjectileLauncher(ProjectileLauncher* launcher);

private:

	/**
	 * Initial strength of a ship.
	 */
	static const float INIT_STRENGTH;

	/**
	 * The maximum movement speed of a ship, i.e., maximum magnitude of the movement
	 * vector.
	 */
	static const float MAX_SPEED;

	/**
	 * The ship's color.
	 */
	color_t m_color;

	/**
	 * The ship's current fuel amount percentage. This is irrelevant if the fuel is
	 * unlimited.
	 */
	unsigned int m_fuelAmount;

	/**
	 * Tells whether the ship is throttling or not.
	 */
	bool m_isThrottling;

	/**
	 * Tells whether the ship is turning left or not.
	 */
	bool m_isTurningLeft;

	/**
	 * Tells whether the ship is turning right or not.
	 */
	bool m_isTurningRight;

	/**
	 * Defines the laser gun charge level. When 1.0, the laser gun is considered
	 * charged. Further, the values must not go below 0 or over 1.0.
	 */
	float m_laserGunChargeLevel;

	/**
	 * Tells whether the ship's laser gun is on or off.
	 */
	bool m_laserGunOn;

	/**
	 * The ship's current number of lasers. This is irrelevant if the lasers are
	 * unlimited.
	 */
	unsigned int m_lasersCount;

	/**
	 * Tells whether the ship's fuel is limited (true) or unlimited (false).
	 */
	bool m_limitFuel;

	/**
	 * Tells whether the ship's lasers are limited (true) or unlimited (false).
	 */
	bool m_limitLasers;

	/**
	 * Tells whether the ship's missiles are limited (true) or unlimited (false).
	 */
	bool m_limitMissiles;

	/**
	 * Defines the missile launcher charge level. When 1.0, the missile launcher is
	 * considered charged. Further, the values must not go below 0 or over 1.0.
	 */
	float m_missileLauncherChargeLevel;

	/**
	 * Tells whether the ship's missile launcher is on or off.
	 */
	bool m_missileLauncherOn;

	/**
	 * The ship's current number of missiles. This is irrelevant if the missiles are
	 * unlimited.
	 */
	unsigned int m_missilesCount;

	/**
	 * Tells whether the ship is initialized in a world environment or not.
	 */
	// bool m_initialized;

	/**
	 * The projectile launcher that the ship will use for firing projectiles.
	 */
	ProjectileLauncher *m_projectileLauncher;

	/**
	 * The vector used for accelerating the ship.
	 */
	Vector2d m_acceleration;

	/**
	 * Charges the laser gun according to the specified progress. When the charge
	 * level reaches 1.0, the laser gun is considered charged.
	 * 
	 * @param chargeStep
	 */
	void chargeLaserGun(float chargeStep);

	/**
	 * Charges the missile launcher according to the specified progress. When the
	 * charge level reaches 1.0, the missile launcher is considered charged.
	 * 
	 * @param chargeStep
	 */
	void chargeMissileLauncher(float chargeStep);

	void fireLaser();
	void fireMissile();

	/**
	 * Throttle the ship.
	 */
	void throttle();

	/**
	 * Rotate the ship in the specified direction
	 * (1 = clockwise, -1 = counter-clockwise).
	 */
	void rotate(short direction);

};
#endif // !defined(EA_E95FDF38_3C73_4fb8_AA00_783DB8775233__INCLUDED_)
