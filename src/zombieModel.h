#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include "characterModel.h"


#define PASSO_ZUMBI 10

class Zumbi{
    private:
        int x, y, health;
        float teta;
    public:
        Zumbi(int x, int y, float teta);
        int get_x();
        void set_x(int);
        int get_y();
        void set_y(int);
        float get_teta();
        void set_teta(float);
        int get_health();
        void set_health(int);
	void update_teta(float);
	void followPersonagem(Personagem);
};
