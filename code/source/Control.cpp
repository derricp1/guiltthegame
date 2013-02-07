#include "../headers/Control.h"
#include <iostream>
#include "/usr/SDL/usr/include/SDL/SDL.h"
// We will have to change this include directory tree
// for whichever OS environment we are working in.
// This happens to be my Ubuntu directory tree

using namespace std;

Control::Control () {
	isrunning = true;
}

void Control::readin() {
	cout << "We need to work in this." << endl;
}

void Control::run() {
	// In order to use SDL video and audio capabilities, we must initialize SDL
	// See documentation...returns 0 if successful, -1 otherwise
	int success = SDL_init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	isrunning = (success==0);
	if (isrunning) {
	  cout << "Initialized" << endl;
	  // Must quit when done using SDL, else resources are not deallocated
	  // MEMRAH REAKS!!
	  SDL_Quit();
	}
	else 
	  cout << "Didnt work, LURK MOAR" << endl;
	
	cout << "This is where the program would run." << endl;
}

// Okay one last note...I couldn't get this to compile on my machine
// I can't quite figure out how to configure the whole package so that it actually works
// It'll probably happen at the MC meeting 2/7/13, else the following weekend