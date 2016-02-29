///////////////////////////////////////////////////////////
//  MenuButtonSpriteManager.h
//  Implementation of the Class MenuButtonSpriteManager
//  Created on:      28-mar-2008 10:30:01
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_6BC743F4_5F22_4673_B56A_42F06D673519__INCLUDED_)
#define EA_6BC743F4_5F22_4673_B56A_42F06D673519__INCLUDED_

#include "TextSpriteManager.h"

class MenuButtonSpriteManager : public TextSpriteManager
{

public:
	MenuButtonSpriteManager(const std::string& name);
	virtual ~MenuButtonSpriteManager();

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual MenuButtonSpriteManager* clone() const;

};
#endif // !defined(EA_6BC743F4_5F22_4673_B56A_42F06D673519__INCLUDED_)
