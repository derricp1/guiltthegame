#include "../headers/Control.h"

Control::Control (int width, int height) {
	running = true;
	winWidth = width;
	winHeight = height;
	screen = NULL;
}


Control::~Control() {
	if (background!=NULL)
		delete background;
	if (SDL_WasInit(SDL_INIT_VIDEO)!=0)
		SDL_Quit();
}


bool Control::isRunning() {
	return running;
}


void Control::setup(SDL_Color* bkgrnd) {
	int success;
	success = SDL_Init(SDL_INIT_VIDEO);
	running = (success==0);
	
	if (!running)
		cout << "ERROR: Initialization failed!" << endl;
	else {
		success = SDL_VideoModeOK(winWidth, winHeight, 8, 
								SDL_SWSURFACE|SDL_RESIZABLE);
		running = (success>0);
	}
	
	if (!running)
		cout << "ERROR: Requested resolution and video " <<
				"modes are not supported." << endl;
	else {
		screen = SDL_SetVideoMode(winWidth, winHeight, 8,
								SDL_SWSURFACE|SDL_RESIZABLE);
		SDL_WM_SetCaption(gameTitle.c_str(), gameTitle.c_str());
		
		// Uncomment these two lines when we find a suitable icon
		//SDL_Surface *icon = SDL_LoadBMP("filename.bmp");
		//SDL_WM_SetIcon(icon, NULL);
		
		if (screen!=NULL)
			running = true;
		else {
			running = false;
			cout << "ERROR: Video mode did not set properly." << endl;
		}
	}
	
	if (bkgrnd==NULL) {
		background = new SDL_Color;
		background->r = RGBMAX;
		background->g = RGBMAX;
		background->b = RGBMAX;
	}
	else background = bkgrnd;
	
	if (running) {
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 
					background->r, background->g, background->b));
		SDL_UpdateRect(screen, 0,0,0,0);
	}
}


void Control::run() {
	cout << "This is where the program would run." << endl;
}


void Control::quit() {
	if (SDL_WasInit(SDL_INIT_VIDEO)!=0)
		SDL_Quit();
}

