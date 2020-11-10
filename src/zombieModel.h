#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include "characterModel.h"
#include "bodyModel.h"


#define PASSO_ZUMBI 10

class ZumbiModel: public CorpoModel{
    public:
        ZumbiModel(int x, int y, float teta);
	void follow(PersonagemModel);
};
