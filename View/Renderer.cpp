
#include "Renderer.h"

/**
 * 
 * @param screenPxWidth
 * @param screenPxHeight    screenPxHeight
 */
Renderer::Renderer():
m_currentCanvas(0)
{
}


Renderer::~Renderer() {
	if(m_currentCanvas) {
		delete m_currentCanvas;
	}

	// Delete all canvas pointers on stack:
	while (!m_canvasStack.empty()) {
		delete m_canvasStack.top();
		m_canvasStack.pop();
	}
}


Renderer::Renderer(const Renderer& r)
{
}


/**
 * Forwards notification to current canvas.
 * 
 * @param state    state
 */
void Renderer::notifyGameStateLeave(const GameState* state) {
	
	// Notify current screen about a game state being left:
	m_currentCanvas->notifyGameStateLeave(state);
}


/**
 * Pushes current canvas on stack, and starts to use the provided canvas as the
 * current one.
 * 
 * @param canvas
 */
void Renderer::useCanvas(Canvas* canvas) {
	if(m_currentCanvas) {
		m_canvasStack.push(m_currentCanvas);
	}
	m_currentCanvas = canvas;
}


/**
 * Discards the current canvas, going back to the previous one (if any).
 */
void Renderer::discardCurrentCanvas() {
	
	if (m_canvasStack.size() > 0) {

		delete m_currentCanvas;

		// Point current canvas to the previous one:
		m_currentCanvas = m_canvasStack.top();
		
		m_canvasStack.pop();

	} else {

		// No sprite managers left to use; clear pointer:
		if(m_currentCanvas) {
			delete m_currentCanvas;
		}
		m_currentCanvas = 0;
	}
}

/**
 * Returns the current canvas or 0 if none is present.
 */
Canvas* Renderer::getCurrentCanvas() {
	return m_currentCanvas;
}
