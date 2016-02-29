///////////////////////////////////////////////////////////
//  GameControl.cpp
//  Implementation of the Class GameControl
//  Created on:      28-mar-2008 10:26:38
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "GameControl.h"


GameControl::GameControl():
m_isActivated(false)
{

}


GameControl::~GameControl() {

}


/**
 * Tells whether the control is activated or not.
 */
bool GameControl::isActivated() {
	return m_isActivated;
}