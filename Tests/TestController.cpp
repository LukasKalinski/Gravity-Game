#include <iostream>
#include <functional>

#include "OpenGLRenderer.h"

#define private public
#include "TestController.h"

using namespace std;

static void test_fn() {
	cout << "test_fn called" << endl;
}

void TestController::mem_test_fn() {
	cout << "mem_test_fn called" << endl;
}

void TestController::runtest() 
{

	// Just for SDL context and a window.
	OpenGLRenderer oglr;
	oglr.init();

	//InputManager ip;
	//Menu menu("kalle kamel");
	//NextMenuButtonControl nmbc(&menu);

	//ip.registerLocalControl(nmbc);

	KeyboardListener kl;

	bool throttleP = false;
	bool leftP = false;

	kl.enableListen(KeyboardListener::GAMEPLAY_P1_SHIP_THROTTLE, &throttleP);
	kl.enableListen(KeyboardListener::GAMEPLAY_P1_SHIP_LEFT, &leftP);

//	kl.addFunction(KeyboardListener::GAMEPLAY_P1_SHIP_THROTTLE, mem_fun(&TestController::mem_test_fn));
//	kl.addFunction(KeyboardListener::GAMEPLAY_P1_SHIP_THROTTLE, test_fn);

	//SoundManager snd;
	//snd.init();

	while(true) {
		kl.refresh();
		if(throttleP) {
			;//cout << "THROTTLAR" << endl;
		}
		if(leftP) {
			cout << "TURNING LEFT" << endl;
		}

	}

}
