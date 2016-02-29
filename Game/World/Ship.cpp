///////////////////////////////////////////////////////////
//  Ship.cpp
//  Implementation of the Class Ship
//  Created on:      28-mar-2008 10:33:18
//  Original author: sfish
///////////////////////////////////////////////////////////

#include "Ship.h"

//#define __DEBUG_SHIP
#ifdef __DEBUG_SHIP
#include <iostream>
using namespace std;
#endif

/**
 * Initial strength of a ship.
 */
const float Ship::INIT_STRENGTH = 5.0f;

/**
 * The maximum movement speed of a ship, i.e., maximum magnitude of the movement
 * vector. The unit is: "Length units per tick".
 */
const float Ship::MAX_SPEED = 8.0f;


Ship::Ship(Ship::color_t color):
MovableObject(50.0, CircularShape(28.0f)),
DestroyableObject(INIT_STRENGTH),
m_acceleration(0.08f, 0),
m_color(color),
m_projectileLauncher(0),
m_limitFuel(false),
m_limitLasers(false),
m_limitMissiles(false),
m_isThrottling(false),
m_isTurningLeft(false),
m_isTurningRight(false),
m_laserGunOn(false),
m_missileLauncherOn(false),
m_missileLauncherChargeLevel(0),
m_laserGunChargeLevel(0)
{
	// FIXME: Make sure that everything is setup properly.
}


Ship::~Ship() {
}


Ship::Ship(const Ship& ship):
MovableObject(ship),
DestroyableObject(ship),
m_acceleration(ship.m_acceleration),
m_color(ship.m_color),
m_projectileLauncher(ship.m_projectileLauncher),
m_limitFuel(ship.m_limitFuel),
m_limitLasers(ship.m_limitLasers),
m_limitMissiles(ship.m_limitMissiles),
m_isThrottling(false),
m_isTurningLeft(false),
m_isTurningRight(false),
m_laserGunOn(false),
m_missileLauncherOn(false),
m_missileLauncherChargeLevel(0),
m_laserGunChargeLevel(0)
{

	// FIXME: make sure everything is copied
}


/**
 * Clones the world object, returning a pointer to the clone.
 */
Ship* Ship::clone() const {
	return new Ship(*this);
}


/**
 * Initializes the ship. Requires a ProjectileLauncher to be present.
 */
void Ship::init() {
	
	if (!m_projectileLauncher) {
		throw std::exception("Ship::init(): projectile launcher not set");
	}

	MovableObject::init();
}


/**
 * Charges the laser gun according to the specified progress. When the charge
 * level reaches 1.0, the laser gun is considered charged.
 * 
 * @param chargeStep
 */
void Ship::chargeLaserGun(float chargeStep) {
	m_laserGunChargeLevel += chargeStep;
	m_laserGunChargeLevel = std::min(m_laserGunChargeLevel, 1.0f);
}


/**
 * Charges the missile launcher according to the specified progress. When the
 * charge level reaches 1.0, the missile launcher is considered charged.
 * 
 * @param chargeStep
 */
void Ship::chargeMissileLauncher(float chargeStep) {
	m_missileLauncherChargeLevel += chargeStep;
	m_missileLauncherChargeLevel = std::min(m_missileLauncherChargeLevel, 1.0f);
}


/**
 * Fires a missile if finished charging.
 */
void Ship::fireLaser() {

	if (!m_initialized) {
		throw std::exception("Ship::fireLaser(): ship not initialized");
	}

	// Create projectile and fire it:
	LaserProjectile laser(m_movement, getShape().getOrientation());
	m_projectileLauncher->launch(this, laser);

	// Reset laser gun charge level:
	m_laserGunChargeLevel = 0;
}


/**
 * Fires a missile if finished charging.
 */
void Ship::fireMissile() {

	if (!m_initialized) {
		throw std::exception("Ship::fireMissile(): ship not initialized");
	}

#ifdef __DEBUG_SHIP
	std::cout << "DEBUG SHIP: Ship is firing missile" << std::endl;
#endif

	// Create projectile and fire it:
	MissileProjectile missile(m_movement, getShape().getOrientation());
	m_projectileLauncher->launch(this, missile);

	// Reset laser gun charge level:
	m_missileLauncherChargeLevel = 0;
}


/**
 * Returns the ship's fuel level.
 */
unsigned int Ship::getFuelLevel() {
	return m_fuelAmount;
}


/**
 * Returns the ship's amount of lasers.
 */
unsigned int Ship::getLasersCount() {
	return m_lasersCount;
}


/**
 * Returns the ship's amount of missiles.
 */
unsigned int Ship::getMissilesCount() {
	return m_missilesCount;
}


/**
 * Tells whether the ship's fuel supply is limited.
 */
bool Ship::hasLimitedFuel() {
	return m_limitFuel;
}


/**
 * Tells whether the ship's laser supply is limited.
 */
bool Ship::hasLimitedLasers() {
	return m_limitLasers;
}


/**
 * Tells whether the ship's missile supply is limited.
 */
bool Ship::hasLimitedMissiles() {
	return m_limitMissiles;
}


/**
 * Sets the ship's fuel limit on/off.
 */
void Ship::setLimitFuel(bool doLimit) {
	m_limitFuel = doLimit;
}


/**
 * Sets the ship's laser limit on/off.
 */
void Ship::setLimitLasers(bool doLimit) {
	m_limitLasers = doLimit;
}


/**
 * Sets the ship's missile limit on/off.
 */
void Ship::setLimitMissiles(bool doLimit) {
	m_limitMissiles = doLimit;
}


/**
 * Returns the ship's color.
 */
Ship::color_t Ship::getColor() const {
	return m_color;
}


/**
 *  Throttle the ship.
 */
void Ship::throttle() {
	//m_position = Coord2d(m_position.getX()+1, m_position.getY()+1);
	//float throttlefactor = 1.0;

	m_movement = m_movement + m_acceleration;

	// Limit movement speed/magnitude:
	if (m_movement.getLength() > MAX_SPEED) {
		m_movement = Vector2d(MAX_SPEED, m_movement.getAngle());
	}
	
#ifdef __DEBUG_SHIP
	cout << "Ship:throttle() called" << endl;
#endif
	//Coord2d acc(Vector2d(1.0, getShape().getOrientation())*throttlefactor);
	//Coord2d mov(m_movement);

	//m_movement = Vector2d(acc+mov);
}


/**
 * Rotate the ship in the specified direction
 * (1 = clockwise, -1 = counter-clockwise).
 */
void Ship::rotate(short direction) {

	float rotateWith = direction * 0.09f;
	m_shape->setOrientation(m_shape->getOrientation() + rotateWith);
	m_acceleration = Vector2d(
		m_acceleration.getLength(),
		m_acceleration.getAngle() + rotateWith);

#ifdef __DEBUG_SHIP
	std::cout << "DEBUG SHIP: Ship is rotating " << (direction > 0 ? "right" : "left") << std::endl;
#endif
}


/**
 * Updates the position of the ship as well as charges its weapons (so that there
 * is a fire delay).
 */
void Ship::tick() {
	
	if (!m_initialized) {
		throw std::exception("Ship::tick(): ship not initialized");
	}

	// Update movement:
	if (m_isThrottling) {
		throttle();
	}

	// Update orientation:
	if (m_isTurningLeft) {
		rotate(1);
	} else if (m_isTurningRight) {
		rotate(-1);
	}

	// Charge weapons and try to fire them if they are turned on:
	chargeLaserGun(1.0f);
	chargeMissileLauncher(0.1f);
	if (m_laserGunOn && laserGunCharged()) {
		fireLaser();
	} else if (m_missileLauncherOn && missileLauncherCharged()) {
		fireMissile();
	}

	// Update position according to current movement:
	m_position = m_position + m_movement;


	// m_position = m_position + Coord2d(10.0, 10.0);
//	std::cout << "Ship::tick() position: " << m_position.getX() << " " << m_position.getY() << std::endl;
//	std::cout << "Ship::tick() position: " << m_position.getX() << " " << m_position.getY() << std::endl;
}


/**
 * Toggles the ship's laser gun on/off. If on, then a laser is fired as soon as
 * the laser gun has finished charging. If no lasers are left, the none will be
 * fired.
 */
void Ship::toggleLaserGun(bool doFire) {

	if (!m_initialized) {
		throw std::exception("Ship::toggleLaserGun(): ship not initialized");
	}

	m_laserGunOn = doFire;
}


/**
 * Toggles the ship's missile launcher on/off. If on, then a missile is fired as
 * soon as the missile launcher has finished charging. If no missiles are left,
 * the none will be fired.
 */
void Ship::toggleMissileLauncher(bool doFire) {

	if (!m_initialized) {
		throw std::exception("Ship::toggleMissileLauncher(): ship not initialized");
	}

	m_missileLauncherOn = doFire;
}


/**
 * Toggles ship's throttle on or off.
 */
void Ship::toggleThrottle(bool doThrottle) {

	if (!m_initialized) {
		throw std::exception("Ship::toggleThrottle(): ship not initialized");
	}

	m_isThrottling = doThrottle;

#ifdef __DEBUG_SHIP
	std::cout << "DEBUG SHIP: throttle turned " << (doThrottle ? "on" : "off") << std::endl;
#endif
}


/**
 * Toggles ship's left turning on or off.
 */
void Ship::toggleTurnLeft(bool doTurn) {

	if (!m_initialized) {
		throw std::exception("Ship::toggleTurnLeft(): ship not initialized");
	}

	m_isTurningLeft = doTurn;

	if (m_isTurningLeft) {
		m_isTurningRight = false;
	}
}


/**
 * Toggles ship's right turning on or off.
 */
void Ship::toggleTurnRight(bool doTurn) {

	if (!m_initialized) {
		throw std::exception("Ship::toggleTurnRight(): ship not initialized");
	}

	m_isTurningRight = doTurn;

	if (m_isTurningRight) {
		m_isTurningLeft = false;
	}
}


/**
 * Tells whether the laser gun is charged or not.
 */
bool Ship::laserGunCharged() {
	return m_laserGunChargeLevel == 1.0;
}


/**
 * Tells whether the missile launcher is charged or not.
 */
bool Ship::missileLauncherCharged() {
	return m_missileLauncherChargeLevel == 1.0;
}


/**
 * Sets the projectile launcher that the ship should use in order to fire
 * projectiles.
 * 
 * @param launcher
 */
void Ship::setProjectileLauncher(ProjectileLauncher* launcher) {
	m_projectileLauncher = launcher;
}


/**
 * Tells whether the ship is throttling or not.
 */
bool Ship::isThrottling() const {
	return m_isThrottling;
}