#ifndef __KEYBOARD_HANDLER_H__
#define __KEYBOARD_HANDLER_H__

#define KEYBOARD_FORCE 10

#define KEYBOARD_UP 1
#define KEYBOARD_DOWN 2
#define KEYBOARD_LEFT 4
#define KEYBOARD_RIGHT 3
#define KEYBOARD_SPACE 5

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class SDL_Keyboard_Handler{
	private:
	       	const Uint8* state;
	public:
		SDL_Keyboard_Handler();
		int getInput();
};

#endif 
