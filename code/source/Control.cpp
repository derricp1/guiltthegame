#include "../headers/Control.h"
#include <iostream>
#include "SDL/SDL.h"
// We will have to change this include directory tree
// for whichever OS environment we are working in.
// This happens to be my Ubuntu directory tree

using namespace std;

Control::Control () {
	isrunning = true;
}

void Control::readin() {
	std::cout << "We need to work in this." << std::endl;
}

void Control::run() {
	// In order to use SDL video and audio capabilities, we must initialize SDL
	// See documentation...returns 0 if successful, -1 otherwise
	int success = SDL_Init(SDL_INIT_VIDEO);
	isrunning = (success==0);
	if (isrunning) {
	  std::cout << "Initialized" << std::endl;
	  // Must quit when done using SDL, else resources are not deallocated
	  // MEMRAH REAKS!!
	  SDL_Quit();
	}
	else 
	  std::cout << "Didnt work, LURK MOAR" << std::endl;
	
	std::cout << "This is where the program would run." << std::endl;
}

// Okay one last note...I couldn't get this to compile on my machine
// I can't quite figure out how to configure the whole package so that it actually works
// It'll probably happen at the MC meeting 2/7/13, else the following weekend
//
// PPS......
// I'm having a lot of trouble getting the thing to work properly...
// The compiler recognizes the constant SDL_INIT_VIDEO, but not the functions defined in SDL.h (?)
