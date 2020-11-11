#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include "bodyModel.h"
#include "axeController.h"

typedef enum {
	CriaMachado,
	Default
} RetornoHandle;

class PersonagemModel: public CorpoModel{
    private:
        std::vector<AxeController> axeControllers;
    public:
        PersonagemModel(int x, int y, float teta);
	RetornoHandle handle_keyboard(int);
};
