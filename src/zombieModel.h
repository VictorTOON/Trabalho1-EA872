#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include "characterModel.h"
#include "bodyModel.h"


#define PASSO_ZUMBI 10

class Zumbi: public Corpo{
    public:
        Zumbi(int x, int y, float teta);
	void followPersonagem(Personagem);
};
