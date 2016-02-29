///////////////////////////////////////////////////////////
//  GamePlayCanvas.h
//  Implementation of the Class GamePlayCanvas
//  Created on:      06-Apr-2008 18:44:22
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_4CFA2128_3DD4_4162_B469_B7B0E7D9F629__INCLUDED_)
#define EA_4CFA2128_3DD4_4162_B469_B7B0E7D9F629__INCLUDED_

#include "Canvas.h"
#include "CanvasViewport.h"
#include "GameEventManager.h"
#include "PlayState.h"
#include "HUD.h"

/**
 * Represents the whole drawable area of a game-play state, for which it holds and
 * manages related sprite managers. However, in order to get something to draw,
 * the canvas' viewport(s) should be used.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 04-May-2008 21:59:43
 */
class GamePlayCanvas :
	public Canvas,
	public WorldObjectInsertListener
{

public:

	typedef std::vector<CanvasViewport> viewports_t;
	typedef std::vector<HUD> huds_t;
	
	/**
	 * Constructs a game play canvas, providing a pointer to the state that it will
	 * monitor.
	 * 
	 * @param state
	 */
	GamePlayCanvas(PlayState* state);

	virtual ~GamePlayCanvas();
	GamePlayCanvas(const GamePlayCanvas& canvas);

	/**
	 * Initializes the sprite manager.
	 */
	virtual void init();

	/**
	 * Updates the contained sprite managers.
	 */
	virtual void update();

	/**
	 * Creates a sprite manager for the inserted world object and inserts that sprite
	 * manager into the contained set of sprite managers.
	 * 
	 * @param ev
	 */
	virtual void notifyEvent(WorldObjectInsertEvent& ev);

	/**
	 * Returns the contained viewports.
	 */
	const viewports_t& getViewports() const;

	/**
	 * Returns the HUDs for each viewport (same order as viewports have).
	 */
	const huds_t& getHUDs() const;

private:

	/**
	 * The game-play state that the canvas is representing.
	 */
	PlayState *m_playState;

	/**
	 * Contains the viewports that are managed by the canvas.
	 */
	viewports_t m_viewports;

	/**
	 * Contains one hud for each viewport, having the same order in the collection as
	 * the viewpors in m_viewports do.
	 */
	huds_t m_huds;

	/**
	 * Creates, setups and stores world sprite managers for each object that is
	 * present in the play state engine's world. This function must only be called on
	 * init, as remaining sprite manager insertions will be handled by insertion event
	 * listeners.
	 * 
	 * @param state
	 */
	void loadWorldSpriteManagers(PlayState& state);

};
#endif // !defined(EA_4CFA2128_3DD4_4162_B469_B7B0E7D9F629__INCLUDED_)
