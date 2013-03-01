#include "../headers/Control.h"

Control::Control (int width, int height) {
	running = true;
	winWidth = width;
	winHeight = height;
	screen = NULL;
}


Control::~Control() {
	if (background)
		delete background;
	if (player)
		delete player;
	if (SDL_WasInit(SDL_INIT_VIDEO))
		SDL_Quit();
}


bool Control::isRunning() {
	return running;
}


void Control::setup(SDL_Color* bkgrnd) {
	int success;
	success = SDL_Init(SDL_INIT_VIDEO);
	running = (success==0);
	cout << success << endl;
	player = new Player();
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
	
	if (!bkgrnd) {
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
		SDL_FillRect(screen, player->getShape(), player->mapColor(screen));
		SDL_UpdateRects(screen, 1, player->getShape());
	}
}


void Control::run() {
	char term = 'x';
	SDL_Event event;
	while (running) {							// UPDAIT LOP
		while (SDL_PollEvent(&event)) {
			// POLLING FOR EVENTS: must be done in loop or it wont work
			
			// Render white background
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,
						background->r, background->g, background->b));
			SDL_UpdateRect(screen, 0,0,0,0);
			
			if (event.type==SDL_KEYDOWN) {
				char *mench = SDL_GetKeyName(event.key.keysym.sym);
				term = mench[0];
				
				switch(term) {
					case 'q':
						running = false;
						break;
						
						// Change current position of object with wasd. Will be updated on next render
					case 'w':
						player->moveup();
						break;
					case 'a':
						player->moveleft();
						break;
					case 's':
						player->movedown();
						break;
					case 'd':
						player->moveright();
						break;
					default:
						cout << "You pressed: ";
						cout << mench << endl;
						break;
				}
				
				// Render visual object at current position
				SDL_FillRect(screen, player->getShape(), player->mapColor(screen));
				SDL_UpdateRects(screen, 1, player->getShape());
			}
		}
	}
}


void Control::quit() {
	if (SDL_WasInit(SDL_INIT_VIDEO)!=0)
		SDL_Quit();
}

