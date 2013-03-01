#if !defined (PLAYER_H)
#define PLAYER_H
#include <SDL/SDL.h>
using namespace std;

const int moveFactor = 5;

class Player
{
	private:
		SDL_Color *color;
		SDL_Rect *shape;
		
	public:
		Player(int=300, int=300, SDL_Color* =NULL);
		Player(const Player&);
		~Player();
		Player& operator= (const Player&);
		
		void moveup();
		void movedown();
		void moveleft();
		void moveright();
		SDL_Rect* getShape() const;
		SDL_Color* getColor() const;
		Uint32 mapColor(SDL_Surface*) const;
};

#endif
