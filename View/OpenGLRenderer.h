///////////////////////////////////////////////////////////
//  OpenGLRenderer.h
//  Implementation of the Class OpenGLRenderer
//  Created on:      28-mar-2008 10:30:58
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_724C1AA5_2FA0_41ff_B385_65DB3D314434__INCLUDED_)
#define EA_724C1AA5_2FA0_41ff_B385_65DB3D314434__INCLUDED_

#include "SDL.h"
#include "SDL_main.h"
#include "SDL_opengl.h"

#include "Renderer.h"

#include "PlayState.h"
#include "SinglePlayerPlayState.h"
#include "TwoPlayersPlayState.h"
#include "MenuState.h"

#include "Canvas.h"
#include "MenuCanvas.h"
#include "GamePlayCanvas.h"

/**
 * Responsible for rendering graphics by using OpenGL.
 */
class OpenGLRenderer : public Renderer
{

public:

	OpenGLRenderer();
	virtual ~OpenGLRenderer();
	OpenGLRenderer(const OpenGLRenderer& renderer);

	/**
	 * Initializes OpenGL etc.
	 */
	virtual void init();

	/**
	 * Renders graphics for current game state by accessing the corresponding game
	 * state sprite manager's sprites.
	 */
	virtual void render();

	/**
	 * Catches the unknown game state case.
	 * 
	 * @param state
	 */
	virtual void notifyGameStateEnter(GameState* state);

	/**
	 * Creates a Screen instance and makes it monitor the entered menu game state.
	 * 
	 * @param state
	 */
	virtual void notifyGameStateEnter(MenuState* state);

	/**
	 * Creates a Screen instance and makes it monitor the entered single player game
	 * state.
	 * 
	 * @param state
	 */
	virtual void notifyGameStateEnter(SinglePlayerPlayState* state);

	/**
	 * Creates a Screen instance and makes it monitor the entered two-players game
	 * state.
	 * 
	 * @param state
	 */
	virtual void notifyGameStateEnter(TwoPlayersPlayState* state);

private:

	
	GLuint LoadFont(const std::string&);

	GLuint loadTexture(const std::string&);

	/**
	 * Initialises SDL, sets videmodes etc.
	 */
	void initSDL();

	/**
	 * Initialise OpenGL specific settings.
	 */
	void initGL();

	/**
	* Initialise textures
	*/
	void initTextures();

	/**
	 * Handle window resize.
	 */
	void resizeWindow(unsigned short width, unsigned short height);

	/**
	 * Catches the unknown canvas case. Throws an exception if called.
	 * 
	 * @param canvas
	 */
	virtual void render(const Canvas& canvas);

	/**
	 * Renders graphics for a menu state by accessing the corresponding canvas' sprite
	 * managers and their sprites.
	 * 
	 * @param canvas
	 */
	virtual void render(const MenuCanvas& canvas);

	/**
	 * Renders graphics for a play state by accessing the corresponding canvas'
	 * viewport(s) and their sprite managers' sprites.
	 * 
	 * @param canvas
	 */
	virtual void render(const GamePlayCanvas& canvas);


	/**
	 * Draws the provided set of sprites.
	 * 
	 * @param sprites
	 */
	virtual void render(const CanvasViewport::sprites_t& sprites);

	typedef std::map<Sprite::sprite_image_t, std::string> filepaths_t;

	std::map<Sprite::sprite_image_t, GLuint> m_textures;
	filepaths_t m_filepaths;

	SDL_Surface *m_screen;
	SDL_Event m_event;

	/**
	 * Screen resolution on the horizontal axis.
	 */
	unsigned short m_screenPxWidth;

	/**
	 * Screen resolution on the vertical axis.
	 */
	unsigned short m_screenPxHeight;

	static const int FULLSCREEN=1, SCREEN_BPP=32;
};
#endif // !defined(EA_724C1AA5_2FA0_41ff_B385_65DB3D314434__INCLUDED_)
