#include <iostream>
#include "SDL.h"
#include "SDL_main.h"
#include "Debug.h"
#include "Game.h"

#include "TestController.h"

using namespace std;

static bool jesper = false;

int main(int argc, char* argv[])
{

	try {
		if (SDL_Init( SDL_INIT_VIDEO  ) < 0) {
			throw std::exception("Video or audio initialization failed");
		}
		atexit(SDL_Quit);

		if(jesper) {
			TestController tc;
			tc.runtest();
		}
		// std::cout << "hejsan" << std::endl;

		
		/*if ( SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
		}
		atexit(SDL_Quit);*/

		// Create, initialize and start game:
		Game* game = Game::instance();
		Debug::instance()->printString("Calling Game::init ");
		game->init();
		Debug::instance()->printString("Game init just done");
		Debug::instance()->printString("Running game...");
		game->run();

		// std::cout << "hejsan2" << std::endl;
	} catch (exception& e) {
		cout << "EXCEPTION! " << e.what() << endl;
		Debug::instance()->printString(e.what());
		system("pause");
	}

	return 0;
}
