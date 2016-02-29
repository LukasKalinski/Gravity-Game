///////////////////////////////////////////////////////////
//  AnimationSprite.cpp
//  Implementation of the Class AnimationSprite
//  Created on:      28-mar-2008 10:23:27
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "AnimationSprite.h"
#include "Game.h"

AnimationSprite::anim_map_t AnimationSprite::m_framesMap;

/**
 * Loads the animation frames map.
 */
void AnimationSprite::loadStaticMembers() {
	if (m_framesMap.empty()) {

		// Set asteroid insertion animation frames:
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F1);
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F2);
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F3);
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F4);
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F5);
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F6);
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F7);
		m_framesMap[ASTEROID_INSERT].push_back(Sprite::ASTEROID_INSERT_F8);

		// Set asteroid destruction animation frames:
		m_framesMap[ASTEROID_DESTROY].push_back(Sprite::ASTEROID_DESTROY_F1);
		m_framesMap[ASTEROID_DESTROY].push_back(Sprite::ASTEROID_DESTROY_F2);
		m_framesMap[ASTEROID_DESTROY].push_back(Sprite::ASTEROID_DESTROY_F3);

		// Set ship destruction animation frames:
		m_framesMap[SHIP_DESTROY].push_back(Sprite::SHIP_DESTROY_F1);
		m_framesMap[SHIP_DESTROY].push_back(Sprite::SHIP_DESTROY_F2);
		m_framesMap[SHIP_DESTROY].push_back(Sprite::SHIP_DESTROY_F3);
		m_framesMap[SHIP_DESTROY].push_back(Sprite::SHIP_DESTROY_F4);

		// Set ship throttle animation frames:
		m_framesMap[SHIP_BLUE_THROTTLE].push_back(Sprite::SHIP_BLUE_THROTTLE_F1);
		m_framesMap[SHIP_BLUE_THROTTLE].push_back(Sprite::SHIP_BLUE_THROTTLE_F2);
		m_framesMap[SHIP_BLUE_THROTTLE].push_back(Sprite::SHIP_BLUE_THROTTLE_F3);
		m_framesMap[SHIP_RED_THROTTLE].push_back(Sprite::SHIP_RED_THROTTLE_F1);
		m_framesMap[SHIP_RED_THROTTLE].push_back(Sprite::SHIP_RED_THROTTLE_F2);
		m_framesMap[SHIP_RED_THROTTLE].push_back(Sprite::SHIP_RED_THROTTLE_F3);
	}
}


/**
 * Constructs a always-repeating animation sprite, specifying its shape, the
 * animation it should represent and the desired time interval (ticks) between two
 * frames.
 * 
 * @param shape
 * @param animation				The animation to represent.
 * @param frameInterval   Ticks between two frames.
 */
AnimationSprite::AnimationSprite(const Shape& shape,
								 AnimationSprite::sprite_anim_t animation,
								 unsigned short frameInterval):
Sprite(shape),
m_animation(animation),
m_animsLeft(1),
m_animsTotal(0),
m_frames(0),
m_playing(false),
m_tickCountdown(frameInterval),
m_tickInterval(frameInterval)
{
	loadStaticMembers();

	// Set our set of animation frames:
	m_frames = &m_framesMap[animation];

	// Point current frame to the first one in the animation cycle:
	m_currentFrame = m_frames->begin();

	// Set sprite image to be the first animation frame:
	m_image = *m_currentFrame;
}


/**
 * Constructs a always-repeating animation sprite, specifying its width and height,
 * the animation it should represent and the desired time interval (ticks) between
 * two frames.
 * 
 * @param width
 * @param height
 * @param animation			The animation to represent.
 * @param frameInterval    Ticks between two frames.
 */
AnimationSprite::AnimationSprite(float width,
								 float height,
								 AnimationSprite::sprite_anim_t animation,
								 unsigned short frameInterval):
Sprite(width, height),
m_animation(animation),
m_animsLeft(1),
m_animsTotal(0),
m_frames(0),
m_playing(false),
m_tickCountdown(frameInterval),
m_tickInterval(frameInterval)
{
	loadStaticMembers();

	// Set our set of animation frames:
	m_frames = &m_framesMap[animation];

	// Point current frame to the first one in the animation cycle:
	m_currentFrame = m_frames->begin();

	// Set sprite image to be the first animation frame:
	m_image = *m_currentFrame;
}


/**
 * Constructs an animation sprite, specifying its shape, the animation it should
 * represent, the desired time interval (ticks) between two frames, and the number
 * of times it should be repeated (0 means played once).
 * 
 * @param shape
 * @param animation					The animation to represent.
 * @param frameInterval			Ticks between two frames.
 * @param repeat						Number of times to repeat the animation.
 */
AnimationSprite::AnimationSprite(const Shape& shape,
								 AnimationSprite::sprite_anim_t animation,
								 unsigned short frameInterval,
								 unsigned short repeat):
Sprite(shape),
m_animation(animation),
m_animsLeft(1 + repeat),
m_animsTotal(1 + repeat),
m_frames(0),
m_playing(false),
m_tickCountdown(frameInterval),
m_tickInterval(frameInterval)
{
	loadStaticMembers();

	// Set our set of animation frames:
	m_frames = &m_framesMap[animation];

	if (m_frames->size() == 0) {
		throw std::exception("AnimationSprite::Constructor: \
							 frames vector has size 0");
	}

	// Point current frame to the first one in the animation cycle:
	m_currentFrame = m_frames->begin();

	// Set sprite image to be the first animation frame:
	m_image = *m_currentFrame;
}


/**
 * Constructs an animation sprite, specifying its width and height, the animation
 * it should represent, the desired time interval (ticks) between two frames, and
 * the number of times it should be repeated (0 means played once).
 * 
 * @param width
 * @param height
 * @param animation    The animation to represent.
 * @param frameInterval    Ticks between two frames.
 * @param repeat    Number of times to repeat the animation.
 */
AnimationSprite::AnimationSprite(float width,
								 float height,
								 AnimationSprite::sprite_anim_t animation,
								 unsigned short frameInterval,
								 unsigned short repeat):
Sprite(width, height),
m_animation(animation),
m_animsLeft(1 + repeat),
m_animsTotal(1 + repeat),
m_frames(0),
m_playing(false),
m_tickCountdown(frameInterval),
m_tickInterval(frameInterval)
{
	loadStaticMembers();

	// Set our set of animation frames:
	m_frames = &m_framesMap[animation];

	// Point current frame to the first one in the animation cycle:
	m_currentFrame = m_frames->begin();

	// Set sprite image to be the first animation frame:
	m_image = *m_currentFrame;
}

/**
 * Copies an animation sprite without copying its state, i.e.,
 * what frame it is at and how many animation repeats are left,
 * for example.
 */
AnimationSprite::AnimationSprite(const AnimationSprite& sprite):
Sprite(sprite),
m_animation(sprite.m_animation),
m_animsLeft(sprite.m_animsLeft),
m_animsTotal(sprite.m_animsTotal),
m_currentFrame(sprite.m_currentFrame),
m_frames(sprite.m_frames),
m_playing(sprite.m_playing),
m_tickCountdown(sprite.m_tickCountdown),
m_tickInterval(sprite.m_tickInterval)
{
	// We have to register this sprite to receive ticks, as that cannot
	// be copied from the source sprite:
	if (sprite.m_playing) {
		Game::instance()->registerStateTickable(this);
	}
}


AnimationSprite::~AnimationSprite() {

	if (m_playing) {
		Game::instance()->unregisterStateTickable(this);
	}
}


/**
 * Tells whether the animation has finished playing as well as repeating or not.
 * If the animation is set to always repeat, then this function will always return
 * false.
 */
bool AnimationSprite::isFinished() const  {

	// If there are no animation repeats left, and current animation
	// frame is the last one in the frames vector, and it has been
	// viewed for a time interval defined by m_tickInterval, the
	// animation is finished:
	return (m_animsLeft == 0 &&
			m_currentFrame + 1 == m_frames->end() &&
			m_tickCountdown == 0);
}


/**
 * Counts down to next frame change.
 */
void AnimationSprite::tick() {

	// Do nothing if we're finished:
	if (isFinished()) {
		return;
	}

	// Decrements m_tickCountdown and if it
	// reaches 0, advances to next image frame,
	// changing m_image, or, if repeat is
	// requested and the last element was
	// reached, falls back to the first frame.

	--m_tickCountdown;
	
	if (m_tickCountdown == 0) {
		
		// If we're just starting an animation:
		if (m_currentFrame == m_frames->begin()) {
			
			// If m_animsTotal is 0, it means that the animation should
			// repeat forever, therefore we can only reduce m_animsLeft
			// if m_animsTotal != 0.
			if (m_animsTotal != 0) {
				--m_animsLeft;
			}
		}
		
		// If we haven't reached the end of an animation
		// cycle, advance to the next frame:
		if (m_currentFrame + 1 != m_frames->end()) {
			++m_currentFrame;
			m_image = *m_currentFrame;

		} else {
			// Previous animation cycle ended; check whether
			// there are repeats/cycles left:
			if (m_animsLeft > 0) {
				// Set current frame to the first one in the animation:
				m_currentFrame = m_frames->begin();

				// If m_animsTotal is 0, it means that the animation should
				// repeat forever, therefore we can only reduce m_animsLeft
				// if m_animsTotal != 0.
				if (m_animsTotal != 0) {
					--m_animsLeft;
				}
			} else {
				// Animation is considered finished, return before m_tickCountdown
				// is reset:
				return;
			}
		}

		// Reset tick countdown:
		m_tickCountdown = m_tickInterval;
	}
}


/**
 * Clones the sprite, returning a pointer to the cloned one.
 */
AnimationSprite* AnimationSprite::clone() const {
	return new AnimationSprite(*this);
}


/**
 * Starts playing the animation.
 */
void AnimationSprite::play() {
	Game::instance()->registerStateTickable(this);
	m_playing = true;
}


/**
 * Returns the animation that the animation sprite represents.
 */
AnimationSprite::sprite_anim_t AnimationSprite::getAnimation() const {
	return m_animation;
}