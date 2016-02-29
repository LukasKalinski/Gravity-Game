///////////////////////////////////////////////////////////
//  MenuCanvas.h
//  Implementation of the Class MenuCanvas
//  Created on:      06-Apr-2008 18:44:15
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_E83402D9_E25D_4143_BB8E_869998FB5C8B__INCLUDED_)
#define EA_E83402D9_E25D_4143_BB8E_869998FB5C8B__INCLUDED_

#include "MenuState.h"
#include "Canvas.h"
#include "CanvasViewport.h"

/**
 * Represents the whole drawable area of a menu state, for which it holds and
 * manages related sprite managers. However, in order to get something to draw,
 * the canvas' viewport(s) should be used.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 06-Apr-2008 21:33:16
 */
class MenuCanvas : public Canvas
{

public:

	/**
	 * Constructs a menu canvas, providing a pointer to the state that it will monitor.
	 * 
	 * 
	 * @param state
	 */
	MenuCanvas(MenuState* state);

	virtual ~MenuCanvas();
	MenuCanvas(const MenuCanvas& canvas);

	/**
	 * Initializes the sprite manager.
	 */
	virtual void init();

	/**
	 * Updates the contained sprite managers.
	 */
	virtual void update();

	/**
	 * Returns the viewport of the menu canvas.
	 */
	const CanvasViewport& getViewport() const;

private:

	/**
	 * The menu state that the canvas is representing.
	 */
	MenuState *m_menuState;

	/**
	 * The viewport of the menu canvas.
	 */
	CanvasViewport m_viewport;

};
#endif // !defined(EA_E83402D9_E25D_4143_BB8E_869998FB5C8B__INCLUDED_)
