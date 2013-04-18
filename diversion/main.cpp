/*
#include <iostream>
#include "SDL/SDL.h"
using namespace std;

void moveup(SDL_Surface*, SDL_Rect*, Uint32);
void movedown(SDL_Surface*, SDL_Rect*, Uint32);
void moveleft(SDL_Surface*, SDL_Rect*, Uint32);
void moveright(SDL_Surface*, SDL_Rect*, Uint32);
bool bounds(int, int, int, int);

int main()
{

	// Initialization
	Uint32 white, black, blue;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *screen = SDL_SetVideoMode(800,600,8,
						SDL_SWSURFACE | SDL_RESIZABLE);
	
	// Make the screen white
	black = SDL_MapRGB(screen->format, 0, 0, 0);
	white = SDL_MapRGB(screen->format, 255, 255, 255);
	SDL_FillRect(screen, NULL, white);
	SDL_UpdateRect(screen, 0,0,0,0);
	
	// Make a rectangle
	blue = SDL_MapRGB(screen->format, 0,0,255);
	SDL_Rect *rect;
	rect->x = 300;
	rect->y = 300;
	rect->h = 100;
	rect->w = 100;
	SDL_FillRect(screen, rect, blue);
	SDL_UpdateRects(screen, 1, rect);
	
	
	// Events...here we go..
	char term = 'x';
	bool running = true;

	
	bool b[4] = {0,0,0,0};
	
	Uint32 framestart;
	
	while (running) {							// UPDAIT LOP		
		
		SDL_Event event;		
		//framestart = SDL_GetTicks();
	  
		while (SDL_PollEvent(&event)) {
		  
			// Render white background
			SDL_FillRect(screen, NULL, white);
			SDL_UpdateRect(screen, 0,0,0,0);
			
			// Render visual object at current position
			SDL_FillRect(screen, rect, blue);
			SDL_UpdateRects(screen,1,rect);
		  
                       switch(event.type) {
                                case SDL_QUIT:
                                        running = false;
                                        break;
                                case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym) {
                                                case SDLK_UP:
                                                        b[0] = 1;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 1;
                                                        break;
                                                case SDLK_DOWN:
                                                        b[2] = 1;
                                                        break;
                                                case SDLK_RIGHT:
                                                        b[3] = 1;
                                                        break;
                                       
                                        }
                                        break;
                                case SDL_KEYUP:
                                        switch(event.key.keysym.sym) {
                                                case SDLK_UP:
                                                        b[0] = 0;
                                                        break;
                                                case SDLK_LEFT:
                                                        b[1] = 0;
                                                        break;
                                                case SDLK_DOWN:
                                                        b[2] = 0;
                                                        break;
                                                case SDLK_RIGHT:
                                                        b[3] = 0;
                                                        break;
                                       
                                        }
                                        break;
                        }		  
		  
		/*
		// POLLING FOR EVENTS: must be done in loop or it wont work, i dunno why
		
			// Render white background
			SDL_FillRect(screen, NULL, white);
			SDL_UpdateRect(screen, 0,0,0,0);
			
			// Render visual object at current position
			SDL_FillRect(screen, rect, blue);
			SDL_UpdateRects(screen,1,rect);						
			
			if (event.type==SDL_KEYDOWN) {
				char *mench = SDL_GetKeyName(event.key.keysym.sym);
				term = mench[0];
				
				switch(term) {
					case 'q':
						running = false;
						break;
					
					// Change current position of object with wasd. Will be updated on next render
					case 'w':
						mup = true;
						break;
					case 'a':
						mleft = true;
						break;
					case 's':
						mdown = true;
						break;
					case 'd':
						mright = true;
						break;
					default:
						cout << "You pressed: ";
						cout << mench << endl;
						break;
				}
			}
			
		
			if (mleft) {
			    moveleft(screen, rect, blue);
			}
			if (mright) {
			    moveright(screen, rect, blue);
			}
			if (mdown) {
			    movedown(screen, rect, blue);
			}
			if (mup) {
			    moveup(screen, rect, blue);
			}
			
		
			
			
		}
		
		if(b[0])
			moveup(screen, rect, blue);
		if(b[1])
			moveleft(screen, rect, blue);
		if(b[2])
			movedown(screen, rect, blue);
		if(b[3])
			moveright(screen, rect, blue);
		
                //SDL_FillRect(screen,&screen->clip_rect,color);
                //SDL_FillRect(screen,&rect,color2);
                //SDL_Flip(screen);
		
                //if(1000/FPS > SDL_GetTicks()-framestart) { //Wait
                //        SDL_Delay(1000/FPS-(SDL_GetTicks()-framestart));
                //}		
		
	}
	
	//int init; cin >> init;
	SDL_Quit();
	return 0;
}

void moveup(SDL_Surface *surf, SDL_Rect *box, Uint32 col)
{
	if (bounds((box->x),((box->y)-5),(box->h),(box->w))) {
		box->y = box->y - 5;
		cout << "Moved up" << endl;
	}
}


void movedown(SDL_Surface *surf, SDL_Rect *box, Uint32 col)
{
	if (bounds((box->x),((box->y)+5),(box->h),(box->w))) {
		box->y = box->y + 5;
		cout << "Moved down" << endl;
	}
}


void moveright(SDL_Surface *surf, SDL_Rect *box, Uint32 col)
{
	if (bounds(((box->x)+5),(box->y),(box->h),(box->w))) {
		box->x = box->x + 5;
		cout << "Moved right" << endl;
	}
}


void moveleft(SDL_Surface *surf, SDL_Rect *box, Uint32 col)
{
	if (bounds(((box->x)-5),(box->y),(box->h),(box->w))) {
		box->x = box->x - 5;
		cout << "Moved left" << endl;
	}
}

bool bounds(int x, int y, int h, int w) { //makes sure we're on screen - will be updated to account for screen scroll later
	return ((x >= w/2) && (x <= (800 - w/2)) && (y >= h/2) && (y <= (600 - h/2)));
	//Assumes 800 by 600
}
*/

#include <iostream>
#include <stdlib.h>
#include "SDL/SDL.h"
using namespace std;
void moveup(SDL_Surface*, SDL_Rect*);
void movedown(SDL_Surface*, SDL_Rect*);
void moveleft(SDL_Surface*, SDL_Rect*);
void moveright(SDL_Surface*, SDL_Rect*);
bool bounds(int, int, int, int);
void signal(int*, SDL_Rect*);
bool collision(int*, SDL_Rect*);
bool interact(SDL_Rect*, SDL_Rect*,int*);

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen = SDL_SetVideoMode(800,600,8, SDL_SWSURFACE | SDL_RESIZABLE);
	
	bool running = true;
	const int FPS = 30;
	
	Uint32 start;
	bool b[5] = {0,0,0,0,0};
	
	Uint32 blue = SDL_MapRGB(screen->format, 0,0,255);
	Uint32 green = SDL_MapRGB(screen->format, 0,255,0);
	
	SDL_Rect rect;
	rect.x = 300;
	rect.y = 300;
	rect.h = 100;
	rect.w = 100;
	SDL_FillRect(screen, &rect, blue);
	SDL_UpdateRects(screen, 1, &rect);
	SDL_Rect *rectptr = &rect;
	
	SDL_Rect rect2;
	rect2.x = 100;
	rect2.y = 100;
	rect2.h = 100;
	rect2.w = 100;
	SDL_FillRect(screen, &rect2, green);
	SDL_UpdateRects(screen, 1, &rect2);
	SDL_Rect *rectptr2 = &rect2;
	bool rect2interact = false;
	
	int* collidetest = new int[4];
	//int* collidetest;
	
	
	Uint32 white = SDL_MapRGB(screen->format, 0xff,0xff,0xff);
	
	while(running) {
		start = SDL_GetTicks();
		SDL_Event event;
		
		b[4] = 0;
		
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_UP:
							b[0] = 1;
							break;
						case SDLK_LEFT:
							b[1] = 1;
							break;
						case SDLK_DOWN:
							b[2] = 1;
							break;
						case SDLK_RIGHT:
							b[3] = 1;
							break;
						case SDLK_z:
							b[4] = 1;
							break;
					
					}
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.sym) {
						case SDLK_UP:
							b[0] = 0;
							break;
						case SDLK_LEFT:
							b[1] = 0;
							break;
						case SDLK_DOWN:
							b[2] = 0;
							break;
						case SDLK_RIGHT:
							b[3] = 0;
							break;
					
					}
					break;
			}
		}

		//logic
		if(b[0]) {
			//rect.y--;
			moveup(screen, rectptr);
		}
		if(b[1]) {
			//rect.x--;
			moveleft(screen, rectptr);
		}
		if(b[2]) {
			//rect.y++;
			movedown(screen, rectptr);
		}
		if(b[3]) {
			//rect.x++;
			moveright(screen, rectptr);
		}
		if(b[4]) {
			rect2interact = interact(rectptr, rectptr2, collidetest);
		}
		
		signal(collidetest, rectptr);
		bool collide = collision(collidetest, rectptr2);
		
		if (collide == true) {
		    cout << "Colliding!" << endl;
		}
		
		if (rect2interact) {
		    rect2.x++;
		}
			
		//render
		SDL_FillRect(screen,&screen->clip_rect,white);
		SDL_FillRect(screen,&rect2,green);	
		SDL_FillRect(screen,&rect,blue);	
		SDL_Flip(screen);
		if(1000/FPS > SDL_GetTicks()-start) {
			SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
		}
	}
	delete collidetest;
	SDL_Quit();
	return 0;
}

bool collision(int* array, SDL_Rect *box) {
	  int xbounds = (box->w + array[3])/2;
	  int ybounds = (box->h + array[4])/2;
	  return ((abs((box->x) - array[1]) < xbounds) && (abs((box->y) - array[2]) < ybounds));
}

void signal(int* array, SDL_Rect *box) {
	array[1] = box->x;
	array[2] = box->y;
	array[3] = box->w;
	array[4] = box->h;
}

void moveup(SDL_Surface *surf, SDL_Rect *box)
{
	if (bounds((box->x),((box->y)-5),(box->h),(box->w))) {
		box->y = box->y - 5;
		cout << "Moved up" << endl;
	}
}


void movedown(SDL_Surface *surf, SDL_Rect *box)
{
	if (bounds((box->x),((box->y)+5),(box->h),(box->w))) {
		box->y = box->y + 5;
		cout << "Moved down" << endl;
	}
}


void moveright(SDL_Surface *surf, SDL_Rect *box)
{
	if (bounds(((box->x)+5),(box->y),(box->h),(box->w))) {
		box->x = box->x + 5;
		cout << "Moved right" << endl;
	}
}


void moveleft(SDL_Surface *surf, SDL_Rect *box)
{
	if (bounds(((box->x)-5),(box->y),(box->h),(box->w))) {
		box->x = box->x - 5;
		cout << "Moved left" << endl;
	}
}

bool bounds(int x, int y, int h, int w) { //makes sure we're on screen - will be updated to account for screen scroll later
	return ((x >= 0) && (x <= 800 - w) && (y >= 0) && (y <= 600 - h));
	//Assumes 800 by 600
}

bool interact(SDL_Rect *box, SDL_Rect *npc, int* array) { //makes sure we're on screen - will be updated to account for screen scroll later
	signal(array, box);
	cout << "Interacted!" << endl;
	return collision(array, npc);
}