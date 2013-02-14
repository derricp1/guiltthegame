#if ! defined (CONTROL_H)
#define CONTROL_H
#include <iostream>
#include "SDL/SDL.h"
using namespace std;

const int DEFWINSIZE=700, RGBMAX=255;
const string gameTitle = "GUILT The Game";

// DO NOT initialize more than one instance of this class
// This class generates the window of the game
// I don't know how SDL will handle more than one active window
class Control {

	private:
		bool running;
		int winWidth, winHeight;
		SDL_Color *background;
		SDL_Surface *screen;
	
	public:
		Control(int=DEFWINSIZE, int=DEFWINSIZE);
		~Control();
		
		bool isRunning();
		void setup(SDL_Color* =NULL);
		void run();
		void quit();
	
};

#endif