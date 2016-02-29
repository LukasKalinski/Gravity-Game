///////////////////////////////////////////////////////////
//  DestroyableObject.cpp
//  Implementation of the Class DestroyableObject
//  Created on:      28-mar-2008 10:25:21
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "DestroyableObject.h"


/**
 * Constructs a destroyable world object with the specified strength.
 */
DestroyableObject::DestroyableObject(float strength):
m_strength(strength) {
}


DestroyableObject::~DestroyableObject() {
}


DestroyableObject::DestroyableObject(const DestroyableObject& dwo):
m_strength(dwo.m_strength) {
}


/**
 * Destroys the world object, i.e., causes maximal damage, resulting in the object
 * being destroyed.
 */
void DestroyableObject::destroy() {
	m_strength = 0.0;
}


/**
 * Tells whether the world object is destroyed or not.
 */
bool DestroyableObject::isDestroyed() {
	return m_strength == 0.0;
}


/**
 * Reduces the world object's strength by the specified amount.
 */
void DestroyableObject::reduceStrength(float withAmount) {
	if (withAmount < 0) {
		throw std::exception("invalid value to reduce strength with");
	}
	m_strength -= withAmount;
}