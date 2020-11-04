#include "sdl_keyboard_handler.h"

SDL_Keyboard_Handler::SDL_Keyboard_Handler(){
	state = SDL_GetKeyboardState(nullptr);
}

int SDL_Keyboard_Handler::getInput(){
	SDL_PumpEvents();
	if (this->state[SDL_SCANCODE_DOWN]){
		return KEYBOARD_DOWN;
	}
	if (this->state[SDL_SCANCODE_LEFT]){
		return KEYBOARD_LEFT;
	}
	if (this->state[SDL_SCANCODE_RIGHT]){
		return KEYBOARD_RIGHT;
	}
	if (this->state[SDL_SCANCODE_UP]){
		return KEYBOARD_UP;
	}
	return 0;
}
