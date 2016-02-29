///////////////////////////////////////////////////////////
//  MenuButtonSpriteManager.cpp
//  Implementation of the Class MenuButtonSpriteManager
//  Created on:      28-mar-2008 10:30:04
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "MenuButtonSpriteManager.h"


/**
 * Constructs a menu button sprite manager, being provided its name.
 */
MenuButtonSpriteManager::MenuButtonSpriteManager(const std::string& name):
TextSpriteManager(name, TextSpriteManager::LARGE) {

	//Calls parent constructor with
	//SIZE_LARGE, for example.
}


MenuButtonSpriteManager::~MenuButtonSpriteManager() {

}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
MenuButtonSpriteManager* MenuButtonSpriteManager::clone() const {
	return new MenuButtonSpriteManager(*this);
}
