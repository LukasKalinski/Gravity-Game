///////////////////////////////////////////////////////////
//  Renderer.h
//  Implementation of the Class Renderer
//  Created on:      02-Apr-2008 04:07:28
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_ED5411DB_E28F_451b_9F21_0C51BA97F4F4__INCLUDED_)
#define EA_ED5411DB_E28F_451b_9F21_0C51BA97F4F4__INCLUDED_

#include <stack>

#include "Canvas.h"


/**
 * Abstract graphics renderer class.
 * @author Lukas Kalinski
 * @version 1.0
 * @updated 21-Apr-2008 12:17:07
 */
class Renderer
{

public:

	/**
	 * 
	 * @param screenPxWidth
	 * @param screenPxHeight
	 */
	Renderer();
	
	virtual ~Renderer();
	Renderer(const Renderer& r);

	/**
	 * Initializes the renderer.
	 */
	virtual void init() = 0;

	/**
	 * Renders graphics for current game state.
	 */
	virtual void render() = 0;

	/**
	 * Creates a Screen instance and makes it monitor the entered game state.
	 * 
	 * @param state
	 */
	virtual void notifyGameStateEnter(GameState* state) = 0;

	/**
	 * Forwards notification to current canvas.
	 * 
	 * @param state
	 */
	virtual void notifyGameStateLeave(const GameState* state);

protected:



	/**
	 * Returns the current canvas or 0 if none is present.
	 */
	Canvas* getCurrentCanvas();

	/**
	 * Pushes current canvas on stack, and starts to use the provided canvas as the
	 * current one.
	 * 
	 * @param canvas
	 */
	void useCanvas(Canvas* canvas);

	/**
	 * Discards the current canvas, going back to the previous one (if any).
	 */
	void discardCurrentCanvas();

private:

	/**
	 * Contains the current canvas to render.
	 */
	Canvas *m_currentCanvas;

	/**
	 * Freezed canvases, which we will fall back to when the current canvas turns
	 * invalid.
	 */
	std::stack<Canvas*> m_canvasStack;

};
#endif // !defined(EA_ED5411DB_E28F_451b_9F21_0C51BA97F4F4__INCLUDED_)