///////////////////////////////////////////////////////////
//  AnimationSprite.h
//  Implementation of the Class AnimationSprite
//  Created on:      28-mar-2008 10:23:20
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_3C78F1FA_E06C_40fb_939E_4632BA10FB19__INCLUDED_)
#define EA_3C78F1FA_E06C_40fb_939E_4632BA10FB19__INCLUDED_

#include <map>
#include <vector>

#include "Sprite.h"
#include "Tickable.h"

class AnimationSprite : public Sprite, public Tickable
{

public:

	enum sprite_anim_t {
		ASTEROID_INSERT,
		ASTEROID_DESTROY,
		SHIP_DESTROY,
		SHIP_BLUE_THROTTLE,
		SHIP_RED_THROTTLE
	};

	typedef std::vector<sprite_image_t> anim_frames_t;

	/**
	 * Constructs a always-repeating animation sprite, specifying its shape, the
	 * animation it should represent and the desired time interval (ticks) between two
	 * frames.
	 * 
	 * @param shape
	 * @param animation				The animation to represent.
	 * @param frameInterval   Ticks between two frames.
	 */
	AnimationSprite(const Shape& shape,
		AnimationSprite::sprite_anim_t animation,
		unsigned short frameInterval);

	/**
	 * Constructs a always-repeating animation sprite, specifying its width and height,
	 * the animation it should represent and the desired time interval (ticks) between
	 * two frames.
	 * 
	 * @param width
	 * @param height
	 * @param animation				The animation to represent.
	 * @param frameInterval   Ticks between two frames.
	 */
	AnimationSprite(float width,
		float height,
		AnimationSprite::sprite_anim_t animation,
		unsigned short frameInterval);

	/**
	 * Constructs an animation sprite, specifying its shape, the animation it should
	 * represent, the desired time interval (ticks) between two frames, and the number
	 * of times it should be repeated (0 means played once).
	 * 
	 * @param shape
	 * @param animation				The animation to represent.
	 * @param frameInterval   Ticks between two frames.
	 * @param repeat					Number of times to repeat the animation.
	 */
	AnimationSprite(const Shape& shape,
		AnimationSprite::sprite_anim_t animation,
		unsigned short frameInterval,
		unsigned short repeat);

	/**
	 * Constructs an animation sprite, specifying its width and height, the animation
	 * it should represent, the desired time interval (ticks) between two frames, and
	 * the number of times it should be repeated (0 means played once).
	 * 
	 * @param width
	 * @param height
	 * @param animation				The animation to represent.
	 * @param frameInterval   Ticks between two frames.
	 * @param repeat					Number of times to repeat the animation.
	 */
	AnimationSprite(float width,
		float height,
		AnimationSprite::sprite_anim_t animation,
		unsigned short frameInterval,
		unsigned short repeat);

	virtual ~AnimationSprite();
	AnimationSprite(const AnimationSprite& sprite);

	sprite_anim_t getAnimation() const;
	bool isFinished() const;
	virtual void tick();

	/**
	 * Clones the sprite, returning a pointer to the cloned one.
	 */
	virtual AnimationSprite* clone() const;

	/**
	 * Starts playing the animation.
	 */
	void play();

private:

	typedef std::map<sprite_anim_t, anim_frames_t> anim_map_t;

	/**
	 * Maps animation aliases to a vector of image aliases (see ANIM_* and IMG_*
	 * enum elements).
	 */
	static anim_map_t m_framesMap;

	/**
	 * The animation that the instance represents.
	 */
	sprite_anim_t m_animation;

	/**
	 * The remaining number of times that the animation can be played.
	 */
	unsigned short m_animsLeft;

	/**
	 * The total number of times that the animation is requested to be played. If 0,
	 * the animation will continue forever (i.e., until its host removes it).
	 */
	unsigned short m_animsTotal;

	/**
	 * Pointer to a vector of image frames. The vector is one of those residing in the
	 * m_animFramesMap.
	 */
	anim_frames_t* m_frames;

	/**
	 * Ticks left to next frame swap.
	 */
	unsigned short m_tickCountdown;

	/**
	 * The number of ticks to wait between two image frames.
	 */
	unsigned short m_tickInterval;

	/**
	 * The current animation frame.
	 */
	anim_frames_t::const_iterator m_currentFrame;

	/**
	 * Tells whether the animation is playing or not.
	 */
	bool m_playing;

	/**
	 * Loads the animation frames map.
	 */
	static void loadStaticMembers();

};
#endif // !defined(EA_3C78F1FA_E06C_40fb_939E_4632BA10FB19__INCLUDED_)
