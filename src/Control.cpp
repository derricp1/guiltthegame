#include "../headers/Control.h"
#include <iostream>
// We will have to change this include directory tree
// for whichever OS environment we are working in.
// This happens to be my Ubuntu directory tree

using namespace std;

Control::Control () {
	isrunning = true;
	screen = NULL;
}

Control::~Control() {
	if (SDL_WasInit(SDL_INIT_VIDEO)!=0)
		SDL_Quit();
}

void Control::setup() {
	isrunning = (SDL_Init(SDL_INIT_VIDEO) == 0);
	
	
}

void Control::run() {
	cout << "This is where the program would run." << endl;
}

void Control::quit() {
	if (SDL_WasInit(SDL_INIT_VIDEO)!=0)
		SDL_Quit();
}