#ifndef __KEYBOARD_HANDLER_H__
#define __KEYBOARD_HANDLER_H__

#define KEYBOARD_FORCE 10

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class SDL_Keyboard_Handler{
	private:
	       	const Uint8* state;
	public:
		SDL_Keyboard_Handler();
		float HandleForceResponse();
};

#endif 
