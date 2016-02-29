///////////////////////////////////////////////////////////
//  StaticObject.cpp
//  Implementation of the Class StaticObject
//  Created on:      28-mar-2008 10:35:22
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "StaticObject.h"


StaticObject::StaticObject(float mass, const Shape& shape):
WorldObject(mass, shape) {
}


StaticObject::~StaticObject() {

}


StaticObject::StaticObject(const StaticObject& so):
WorldObject(so) {
}