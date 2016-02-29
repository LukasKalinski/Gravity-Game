///////////////////////////////////////////////////////////
//  OpenGLRenderer.cpp
//  Implementation of the Class OpenGLRenderer
//  Created on:      28-mar-2008 10:31:03
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <exception>
#include <iostream>

#include "OpenGLRenderer.h"
#include "SDL_image.h"

using namespace std;

OpenGLRenderer::OpenGLRenderer():
Renderer()
{
	m_filepaths[Sprite::SHIP_BLUE] = "gfx\\ship_blue.png";
	m_filepaths[Sprite::SHIP_BLUE_THROTTLE_F1] = "gfx\\ship_blue_throttle_f1.png";
	m_filepaths[Sprite::SHIP_RED] = "gfx\\ship_red.png";
	m_filepaths[Sprite::SHIP_RED_THROTTLE_F1] = "gfx\\ship_red_throttle_f1.png";
	m_filepaths[Sprite::SHIP_DESTROY_F1] = "gfx\\ship_destroy_1.png";
	m_filepaths[Sprite::SHIP_DESTROY_F2] = "gfx\\ship_destroy_2.png";
	m_filepaths[Sprite::SHIP_DESTROY_F3] = "gfx\\ship_destroy_3.png";
	m_filepaths[Sprite::SHIP_DESTROY_F4] = "gfx\\ship_destroy_4.png";
	m_filepaths[Sprite::SPAWN_POINT_FREE] = "gfx\\spawn_point_free.png";
	m_filepaths[Sprite::SPAWN_POINT_OCCUPIED] = "gfx\\spawn_point_occupied.png";
	m_filepaths[Sprite::PLANET_MARS] = "gfx\\planet_mars.png";
	m_filepaths[Sprite::PLANET_EARTH] = "gfx\\planet_earth.png";
	m_filepaths[Sprite::PLANET_PLUTO] = "gfx\\planet_pluto.png";
	m_filepaths[Sprite::MISSILE] = "gfx\\missile.png";
	m_filepaths[Sprite::BACKGROUND_1] = "gfx\\background.png";
	m_filepaths[Sprite::ASTEROID] = "gfx\\asteroid.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F1] = "gfx\\asteroid_insert_1.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F2] = "gfx\\asteroid_insert_2.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F3] = "gfx\\asteroid_insert_3.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F4] = "gfx\\asteroid_insert_4.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F5] = "gfx\\asteroid_insert_5.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F6] = "gfx\\asteroid_insert_6.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F7] = "gfx\\asteroid_insert_7.png";
	m_filepaths[Sprite::ASTEROID_INSERT_F8] = "gfx\\asteroid_insert_8.png";
	m_filepaths[Sprite::ASTEROID_DESTROY_F1] = "gfx\\asteroid_destroy_1.png";
	m_filepaths[Sprite::ASTEROID_DESTROY_F2] = "gfx\\asteroid_destroy_2.png";
	m_filepaths[Sprite::ASTEROID_DESTROY_F3] = "gfx\\asteroid_destroy_3.png";
	m_filepaths[Sprite::ASTEROID_DESTROY_F4] = "gfx\\asteroid_destroy_4.png";
	m_filepaths[Sprite::HUD_WORLD_MAP_BG] = "gfx\\worldmap.png";
	m_filepaths[Sprite::HUD_WORLD_MAP_PLANET] = "gfx\\worldmap_planet.png";
	m_filepaths[Sprite::HUD_WORLD_MAP_SHIP_1] = "gfx\\worldmap_ship_blue.png";
	m_filepaths[Sprite::HUD_WORLD_MAP_SHIP_2] = "gfx\\worldmap_ship_red.png";
	m_filepaths[Sprite::LASER] = "gfx\\laser.png";

	const SDL_VideoInfo *videoInfo;
	
	videoInfo = SDL_GetVideoInfo( );

	m_screenPxWidth = videoInfo->current_w;
	m_screenPxHeight = videoInfo->current_h;

}


OpenGLRenderer::~OpenGLRenderer() {
}


OpenGLRenderer::OpenGLRenderer(const OpenGLRenderer& renderer):
Renderer(renderer),
m_screenPxWidth(renderer.m_screenPxWidth),
m_screenPxHeight(renderer.m_screenPxHeight)
{
}


/**
* Initialises SDL, sets videmodes etc.
*/
void OpenGLRenderer::initSDL()
{
	int videoFlags;
	const SDL_VideoInfo *videoInfo;
	
	videoInfo = SDL_GetVideoInfo( );

	if (!videoInfo) {
		throw std::exception("Video query failed");
	}

	videoFlags  = SDL_OPENGL;
	videoFlags |= SDL_GL_DOUBLEBUFFER; 
	videoFlags |= SDL_HWPALETTE;  
	videoFlags |= SDL_RESIZABLE; 
	
	if(FULLSCREEN)
		videoFlags |= SDL_FULLSCREEN;

	if (videoInfo->hw_available)
		videoFlags |= SDL_HWSURFACE;
	else
		videoFlags |= SDL_SWSURFACE;

	if (videoInfo->blit_hw)
		videoFlags |= SDL_HWACCEL;

	// Sets up OpenGL double buffering 
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_screen = SDL_SetVideoMode(m_screenPxWidth, m_screenPxHeight, SCREEN_BPP, videoFlags);

	if(!m_screen) {
		throw std::exception("Video mode set failed");
	}

	if(FULLSCREEN)
		SDL_ShowCursor(SDL_DISABLE);
}

/**
* Initialise OpenGL specific settings.
*/
void OpenGLRenderer::initGL() {
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);	
	glDepthFunc(GL_LEQUAL);	
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_TEXTURE_2D);
	glEnable (GL_BLEND); 
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

/**
* Handle window resize.
*/
void OpenGLRenderer::resizeWindow(unsigned short width, unsigned short height)
{
	GLfloat ratio;

	if (height == 0) {
		height = 1;
	}

	ratio = (GLfloat) width / (GLfloat) height;

	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 45.0f, ratio, 1.0f, 1200.0f );
	

	// No need for perspective projection so let's use ortographic
	// projection instead.
	// FIXME: How about zooming in/out according to ship movement speed?
	//glOrtho(0.0f, m_screenPxWidth, m_screenPxHeight, 0.0f, -1.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGLRenderer::initTextures() {

	filepaths_t::iterator filepath_it = m_filepaths.begin();
	for ( ; filepath_it != m_filepaths.end(); ++filepath_it) {
		m_textures[filepath_it->first] = loadTexture(filepath_it->second);
	}

	//textures[Sprite::SHIP] = loadTexture(m_filepaths[Sprite::SHIP]);
	//textures[Sprite::SPAWN_POINT] = loadTexture(m_filepaths[Sprite::SPAWN_POINT]);
	//textures[Sprite::PLANET_1] = loadTexture(m_filepaths[Sprite::PLANET_1]);
}


GLuint OpenGLRenderer::loadTexture(const std::string& file ){
	SDL_Surface* texture = IMG_Load(file.c_str());
	GLuint texint;
	if(!texture) throw std::exception("OpenGLRenderer.cpp: failed to load texture.");

	glPixelStorei(GL_UNPACK_ALIGNMENT,4);
	glGenTextures(1, &texint);
	glBindTexture(GL_TEXTURE_2D, texint);
	SDL_PixelFormat *format = texture->format;

	//is there an alpha channel?
	if (format->Amask){
		gluBuild2DMipmaps(GL_TEXTURE_2D, 4,
			texture->w, texture->h, GL_RGBA, GL_UNSIGNED_BYTE, texture->pixels);
	}
	else{	
		
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
			texture->w, texture->h, GL_RGB, GL_UNSIGNED_BYTE, texture->pixels);

//		glTexImage2D( GL_TEXTURE_2D, 0,3, texture->w, texture->h,0,
//			GL_RGB, GL_UNSIGNED_BYTE, texture->pixels);
//		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
//		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	}
	SDL_FreeSurface(texture);
	return texint;
}

GLuint OpenGLRenderer::LoadFont(const std::string& file){
	SDL_Surface* texture = IMG_Load(file.c_str());
	// Define number of sprites in the image file in the x and y direction.
	const int sprites_x = 10, sprites_y = 1;
	GLuint texint[sprites_x*sprites_y];

	if(!texture) throw std::exception("OpenGLRenderer.cpp: failed to load texture.");
	glGenTextures( sprites_x*sprites_y, &texint[0]);
	glPixelStorei( GL_UNPACK_ROW_LENGTH, texture->w);

	// Calculate width and height of each sprite in the image.
	int texture_w, texture_h;
	texture_w = texture->w/sprites_x;
	texture_h = texture->h/sprites_y;

	SDL_PixelFormat *format = texture->format;
	int offset=0,i=0;
	for( int y = 0; y< sprites_y; y++)
		for( int x = 0; x < sprites_x; x++){
			//offset = 16*16*(format->BytesPerPixel)*32*y+(format->BytesPerPixel*16)*x;
			offset = texture_w*texture_w*(format->BytesPerPixel)*texture_h*y+(format->BytesPerPixel*texture_w)*x;
			glBindTexture(GL_TEXTURE_2D, texint[i]);
			i++;
/*
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexImage2D( GL_TEXTURE_2D, 0, format->BytesPerPixel,
				64,64, 0, GL_RGB,
				GL_UNSIGNED_BYTE, (char*)texture->pixels+offset );*/
			if (format->Amask){
				gluBuild2DMipmaps(GL_TEXTURE_2D, 4,
					texture_w, texture_h, GL_RGBA, GL_UNSIGNED_BYTE, (char*)texture->pixels+offset);
			}
			else{
				gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
					texture_w, texture_h, GL_RGB, GL_UNSIGNED_BYTE, (char*)texture->pixels+offset);
			}
			if( Sprite::CHAR_0+i > Sprite::CHAR_UC_Z ) 
				throw std::exception("OpenGLRenderer::LoadFont: More sprites in image than there are characters!");
		
			m_textures[Sprite::sprite_image_t(Sprite::CHAR_0 + i)] = texint[i];
		}
		/*
	while(1){	

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef( 0.0f, 0.0f, -700.0f);

		glBindTexture(GL_TEXTURE_2D, texint[2]);
		glBegin( GL_QUADS);
			glTexCoord2f(1.0f, 0.0f);
			glVertex2f(10.0f, 10.0f);
			glTexCoord2f(1.0f, 1.0f);
			glVertex2f(10.0f, 60.0);
			glTexCoord2f(0.0f, 1.0f);
 			glVertex2f(80.0f, 60.0f);
			glTexCoord2f(0.0f, 0.0f);
			glVertex2f(80.0f, 10.0f);
		glEnd();
 
		SDL_GL_SwapBuffers( );
	}*/
	return texint[0];
}


/**
 * Initializes OpenGL etc.
 */
void OpenGLRenderer::init() {
	initSDL();
	initGL();
	initTextures();
	resizeWindow(m_screenPxWidth, m_screenPxHeight);
	LoadFont("gfx\\asd3.png");
}


/**
 * Renders current game state.
 */
void OpenGLRenderer::render() {
	
	// Make sure there is a canvas present:
	if (!getCurrentCanvas()) {
		throw std::exception("OpenGLRenderer::render(): canvas not present");
	}

	// Check if current canvas is valid, and if
	// not, go start using the previous one instead:
	if (!getCurrentCanvas()->isValid()) {
		discardCurrentCanvas();
	}

	// Update current canvas:
	getCurrentCanvas()->update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	// Draw sprites for the viewports of the current canvas:

	render(*getCurrentCanvas());
	
	SDL_GL_SwapBuffers();
	// cout << "OpenGLRenderer() tick!" << endl;
}


/**
 * Catches the unknown game state case.
 * 
 * @param state
 */
void OpenGLRenderer::notifyGameStateEnter(GameState* state) {
	if(MenuState* tmpstate = dynamic_cast<MenuState*>(state)) {
		notifyGameStateEnter(tmpstate);
	} else if(SinglePlayerPlayState* tmpstate = dynamic_cast<SinglePlayerPlayState*>(state)) {
		notifyGameStateEnter(tmpstate);
	} else if(TwoPlayersPlayState* tmpstate = dynamic_cast<TwoPlayersPlayState*>(state)) {
		notifyGameStateEnter(tmpstate);
	} else {
		throw std::exception("unknown game state");
	}
}


/**
 * Creates a Screen instance and makes it monitor the entered menu game state.
 * 
 * @param state
 */
void OpenGLRenderer::notifyGameStateEnter(MenuState* state) {

	Canvas * canvas = new MenuCanvas(state);
	canvas->init();
	useCanvas(canvas);
}


/**
 * Creates a Screen instance and makes it monitor the entered single player game
 * state.
 * 
 * @param state
 */
void OpenGLRenderer::notifyGameStateEnter(SinglePlayerPlayState* state) {
	
	if (state == 0) {
		throw std::exception("OpenGLRenderer::notifyGameStateEnter(): \
							 state must not be 0");
	}

	Canvas * canvas = new GamePlayCanvas(state);
	canvas->init();
	useCanvas(canvas);
}


/**
 * Creates a Screen instance and makes it monitor the entered two-players game
 * state.
 * 
 * @param state
 */
void OpenGLRenderer::notifyGameStateEnter(TwoPlayersPlayState* state) {
		
	if (state == 0) {
		throw std::exception("OpenGLRenderer::notifyGameStateEnter(): \
							 state must not be 0");
	}

	Canvas * canvas = new GamePlayCanvas(state);
	canvas->init();
	useCanvas(canvas);
}


/**
 * Catches the unknown canvas case. Throws an exception if called.
 * 
 * @param canvas
 */
void OpenGLRenderer::render(const Canvas& canvas) {
	if (const MenuCanvas* tmpcanvas = dynamic_cast<const MenuCanvas*>(&canvas)) {
		render(*tmpcanvas);
	} else if (const GamePlayCanvas* tmpcanvas = dynamic_cast<const GamePlayCanvas*>(&canvas)) {
		render(*tmpcanvas);
	} else {
		throw std::exception("OpenGLRenderer::render(): unsupported canvas type");
	}
}


/**
 * Renders graphics for a menu state by accessing the corresponding canvas' sprite
 * managers and their sprites.
 * 
 * @param canvas
 */
void OpenGLRenderer::render(const MenuCanvas& canvas) {

	// # Fetch the viewport from the canvas and
	// # fetch sprites from the
	// # viewports and render them.

	render(canvas.getViewport().getSprites());
}


/**
 * Renders graphics for a play state by accessing the corresponding canvas'
 * viewport(s) and their sprite managers' sprites.
 * 
 * @param canvas
 */
void OpenGLRenderer::render(const GamePlayCanvas& canvas) {

	// Fetch the viewport from the canvas,
	// fetch sprite managers from the
	// viewports, and finally fetch and render
	// sprites from the fetched sprite
	// managers.

	if (canvas.getViewports().size() == 1) {
		// Single player - one screen frame to render.

		// Make reference to the only viewport:
		const CanvasViewport & cv = canvas.getViewports()[0];

		glRotatef(-90,0.0f,0.0f,1.0f);
		glTranslatef(-cv.getCenter().getX() ,-cv.getCenter().getY(),
			-700.0f-50*cv.getDistance());

		render(cv.getSprites());
	
	
	} else if (canvas.getViewports().size() >= 2) {
		// Two players - two screen frames to render.

		// Make reference to the two viewports that are to be rendered:
		const CanvasViewport & cv1 = canvas.getViewports()[1];
		const CanvasViewport & cv2 = canvas.getViewports()[0];
		const HUD & hud1 = canvas.getHUDs()[1];
		const HUD & hud2 = canvas.getHUDs()[0];

		// White line dividing the screen.
		glViewport(0,0,m_screenPxWidth, m_screenPxHeight);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0f,m_screenPxWidth, m_screenPxHeight,0);

		glDisable(GL_TEXTURE_2D);
		glColor3f(1.0f,1.0f,1.0f);
		glBegin(GL_QUADS);
		glVertex2f((float)m_screenPxWidth/2-1,0.0f);
		glVertex2f((float)m_screenPxWidth/2,0.0f);
		glVertex2f((float)m_screenPxWidth/2,m_screenPxHeight );
		glVertex2f((float)m_screenPxWidth/2-1,m_screenPxHeight );
		glEnd();	
		glEnable(GL_TEXTURE_2D);

		// Viewport for player one.
		GLfloat ratio = (GLfloat) m_screenPxWidth/2 / (GLfloat) m_screenPxHeight;

		glViewport(0,0, (GLsizei) m_screenPxWidth/2, 
			(GLsizei) m_screenPxHeight);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective( 45.0f, ratio, 1.0f, 1200.0f );

		glPushMatrix();
			glTranslatef(-cv1.getCenter().getX(), -cv1.getCenter().getY(),
				-700.0f-50*cv1.getDistance());
			render(cv1.getSprites());
		glPopMatrix();

		//cout << cv1.getCenter().getX() << " " << cv1.getCenter().getY()<<endl;
		glTranslatef(-140 ,-240, -700.0f);
		render(hud1.getSprites());

		// Viewport for player two.
		ratio = (GLfloat) m_screenPxWidth/2 / (GLfloat) m_screenPxHeight;

		glViewport((GLsizei)m_screenPxWidth/2, 0, (GLsizei) m_screenPxWidth/2, 
			(GLsizei) m_screenPxHeight);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective( 45.0f, ratio, 1.0f, 1200.0f );
		glPushMatrix();
		glTranslatef(-cv2.getCenter().getX() ,-cv2.getCenter().getY(),
			-700.0f-50*cv2.getDistance());
		render(cv2.getSprites());
		glPopMatrix();
		glTranslatef(-140 ,-240, -700.0f);
		render(hud2.getSprites());

	} else {
		throw std::exception("OpenGLRenderer::render(): no viewports found");
	}
}


/**
 * Draws the provided set of sprites.
 * 
 * @param sprites
 */
void OpenGLRenderer::render(const std::multiset<Sprite>& sprites) {

	std::multiset<Sprite>::const_iterator sprite_it = sprites.begin();
	for ( ; sprite_it != sprites.end(); ++sprite_it) {

		if (m_textures.find(sprite_it->getImage()) == m_textures.end()) {
			throw std::exception("OpenGLRenderer::render(): texture not found");
		}

		glPushMatrix();

		// Move to sprite's position:
		glTranslatef(
			sprite_it->getPosition().getX(),
			sprite_it->getPosition().getY(),
			0.0f);
	
		// Rotate sprite so that it "points" according to the unit circles 0 angle:
		glRotatef(180.0f, 0.0f, 0.0f, 1.0f);

		glRotatef(sprite_it->getRotationDeg(), 0.0f, 0.0f, 1.0f);

		glBindTexture(GL_TEXTURE_2D, m_textures[sprite_it->getImage()]);
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 0.0f);
			glVertex2f(-sprite_it->getWidth()/2, -sprite_it->getHeight()/2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex2f(-sprite_it->getWidth()/2, sprite_it->getHeight()/2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex2f(sprite_it->getWidth()/2, sprite_it->getHeight()/2);
			glTexCoord2f(0.0f, 0.0f);
			glVertex2f(sprite_it->getWidth()/2,-sprite_it->getHeight()/2);
		glEnd();

		glPopMatrix();
	}
}

