#if ! defined (CONTROL_H)
#define CONTROL_H
#include <iostream>
#include <SDL/SDL.h>
using namespace std;


// DO NOT initialize more than one instance of this class
// This class generates the window of the game
// I don't know how SDL will handle more than one active window
class Control {

	private:
		bool isrunning;
		SDL_Surface *screen;
	
	public:
		Control();
		~Control();
		
		void setup();
		void run();
		void quit();
	
};

#endif