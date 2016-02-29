///////////////////////////////////////////////////////////
//  TextSpriteManager.cpp
//  Implementation of the Class TextSpriteManager
//  Created on:      28-mar-2008 10:35:30
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "TextSpriteManager.h"


TextSpriteManager::char_map_t TextSpriteManager::m_charToSpriteMap;


/**
 * Loads the static members of this class.
 */
void TextSpriteManager::loadStaticMembers() {

	// # Load map of supported characters...

	// Alphabet:
	m_charToSpriteMap['A'] = Sprite::CHAR_UC_A;
	m_charToSpriteMap['B'] = Sprite::CHAR_UC_B;
	m_charToSpriteMap['C'] = Sprite::CHAR_UC_C;
	m_charToSpriteMap['D'] = Sprite::CHAR_UC_D;
	m_charToSpriteMap['E'] = Sprite::CHAR_UC_E;
	m_charToSpriteMap['F'] = Sprite::CHAR_UC_F;
	m_charToSpriteMap['G'] = Sprite::CHAR_UC_G;
	m_charToSpriteMap['H'] = Sprite::CHAR_UC_H;
	m_charToSpriteMap['I'] = Sprite::CHAR_UC_I;
	m_charToSpriteMap['J'] = Sprite::CHAR_UC_J;
	m_charToSpriteMap['K'] = Sprite::CHAR_UC_K;
	m_charToSpriteMap['L'] = Sprite::CHAR_UC_L;
	m_charToSpriteMap['M'] = Sprite::CHAR_UC_M;
	m_charToSpriteMap['N'] = Sprite::CHAR_UC_N;
	m_charToSpriteMap['O'] = Sprite::CHAR_UC_O;
	m_charToSpriteMap['P'] = Sprite::CHAR_UC_P;
	m_charToSpriteMap['Q'] = Sprite::CHAR_UC_Q;
	m_charToSpriteMap['R'] = Sprite::CHAR_UC_R;
	m_charToSpriteMap['S'] = Sprite::CHAR_UC_S;
	m_charToSpriteMap['T'] = Sprite::CHAR_UC_T;
	m_charToSpriteMap['U'] = Sprite::CHAR_UC_U;
	m_charToSpriteMap['V'] = Sprite::CHAR_UC_V;
	m_charToSpriteMap['W'] = Sprite::CHAR_UC_W;
	m_charToSpriteMap['X'] = Sprite::CHAR_UC_X;
	m_charToSpriteMap['Y'] = Sprite::CHAR_UC_Y;
	m_charToSpriteMap['Z'] = Sprite::CHAR_UC_Z;

	// Numbers:
	m_charToSpriteMap['0'] = Sprite::CHAR_0;
	m_charToSpriteMap['1'] = Sprite::CHAR_1;
	m_charToSpriteMap['2'] = Sprite::CHAR_2;
	m_charToSpriteMap['3'] = Sprite::CHAR_3;
	m_charToSpriteMap['4'] = Sprite::CHAR_4;
	m_charToSpriteMap['5'] = Sprite::CHAR_5;
	m_charToSpriteMap['6'] = Sprite::CHAR_6;
	m_charToSpriteMap['7'] = Sprite::CHAR_7;
	m_charToSpriteMap['8'] = Sprite::CHAR_8;
	m_charToSpriteMap['9'] = Sprite::CHAR_9;

	// Other characters:
	m_charToSpriteMap[':'] = Sprite::CHAR_COLON;
	m_charToSpriteMap[','] = Sprite::CHAR_COMMA;
	m_charToSpriteMap['!'] = Sprite::CHAR_EXCLAMATION;
	m_charToSpriteMap['.'] = Sprite::CHAR_PERIOD;
	m_charToSpriteMap['?'] = Sprite::CHAR_QUESTION;
	m_charToSpriteMap[' '] = Sprite::CHAR_SPACE;
}


/**
 * Constructs a text sprite specifying the text to represent as well as the size
 * it should have.
 * 
 * @param text
 * @param size
 */
TextSpriteManager::TextSpriteManager(const std::string& text,
									 TextSpriteManager::text_size_t size):
SpriteManager(Coord2d(0,0)),
m_size(size) {

	//Translates string into line-by-line
	//sprite vectors. See m_textLines. Uses
	//m_charToSpriteMap for mapping.

	// FIXME: loop through name and create a sprite for each char.
	// FIXME: throw exceptions for characters not found in char map.
}


TextSpriteManager::~TextSpriteManager() {
	 // FIXME: delete pointed sprites from "text container"?
}

/**
 * 
 */
TextSpriteManager::TextSpriteManager(const TextSpriteManager& sm):
SpriteManager(sm) {
	// FIXME: copy pointed sprites from "text container"?
}


/**
 * Returns the desired size of the text. See SIZE_* constants.
 */
TextSpriteManager::text_size_t TextSpriteManager::getSize() const  {
	return m_size;
}


/**
 * Clones the sprite manager, returning a pointer to the clone.
 */
TextSpriteManager* TextSpriteManager::clone() const {
	return new TextSpriteManager(*this);
}
