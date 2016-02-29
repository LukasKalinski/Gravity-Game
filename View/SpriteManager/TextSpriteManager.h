///////////////////////////////////////////////////////////
//  TextSpriteManager.h
//  Implementation of the Class TextSpriteManager
//  Created on:      28-mar-2008 10:35:26
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_C27B3F46_F558_49eb_A0D7_30819E37005E__INCLUDED_)
#define EA_C27B3F46_F558_49eb_A0D7_30819E37005E__INCLUDED_

#include <vector>

#include "SpriteManager.h"

/**
 * Abstract sprite manager that will manage texts.
 */
class TextSpriteManager : public SpriteManager
{

public:
	
	typedef std::map<char, Sprite::sprite_image_t> char_map_t;

	// Text size definitions:
	enum text_size_t {
		LARGE,
		SMALL
	};

	/**
	 * Constructs a text sprite specifying the text to represent as well as the size
	 * it should have.
	 * 
	 * @param text
	 * @param size
	 */
	TextSpriteManager(const std::string& text, text_size_t size);

	virtual ~TextSpriteManager();
	TextSpriteManager(const TextSpriteManager& sm);

	text_size_t getSize() const;

	/**
	 * Clones the sprite manager, returning a pointer to the clone.
	 */
	virtual TextSpriteManager* clone() const;

private:

	typedef std::vector<Sprite*> text_line_t;
	typedef std::vector<text_line_t> text_lines_t;

	/**
	 * Maps single characters to the CHAR_* enum elements in Sprite.
	 */
	static char_map_t m_charToSpriteMap;

	/**
	 * Loads the static members of this class.
	 */
	void loadStaticMembers();

	/**
	 * The size that the contained text should have.
	 */
	text_size_t m_size;

	/**
	 * Vector of text lines, each of which is a vector consisting of sprite pointers.
	 */
	text_lines_t m_textLines;

};
#endif // !defined(EA_C27B3F46_F558_49eb_A0D7_30819E37005E__INCLUDED_)
