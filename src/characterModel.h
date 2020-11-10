#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include "bodyModel.h"
#include "axeModel.h"
#define speed 50

class Personagem: public Corpo{
    private:
        std::vector<Axe> axes;
    public:
        Personagem(int x, int y, float teta);
        void adicionaMachado();
	    void handle_keyboard(int); 
};
