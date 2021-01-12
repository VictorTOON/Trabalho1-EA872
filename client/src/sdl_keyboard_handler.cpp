#include "sdl_keyboard_handler.hpp"

SDL_Keyboard_Handler::SDL_Keyboard_Handler(){
	state = SDL_GetKeyboardState(nullptr);
}

int SDL_Keyboard_Handler::getInput(){
	SDL_PumpEvents();
	int ret = 0;
	if (this->state[SDL_SCANCODE_S]){
		ret |= (1<<KEYBOARD_DOWN);
	}
	if (this->state[SDL_SCANCODE_A]){
		ret |= (1<<KEYBOARD_LEFT);
	}
	if (this->state[SDL_SCANCODE_D]){
		ret |= (1<<KEYBOARD_RIGHT);
	}
	if (this->state[SDL_SCANCODE_W]){
		ret |= (1<<KEYBOARD_UP);
	}
    if (this->state[SDL_SCANCODE_SPACE]){
		ret |= (1<<KEYBOARD_SPACE);
	}
    if (this->state[SDL_SCANCODE_0]){
		ret |= (1<<KEYBOARD_ZERO);
	}
    if (this-> state[SDL_SCANCODE_P]){
        ret |= (1<<KEYBOARD_P);
    }
    if (this-> state[SDL_SCANCODE_O]){
        ret |= (1<<KEYBOARD_O);
    }
	return ret;
}
