#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include "bodyModel.h"

class Personagem: public Corpo{
    public:
        Personagem(int x, int y, float teta);
	void handle_keyboard(int); 
};
