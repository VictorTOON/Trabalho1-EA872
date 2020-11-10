#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>

#define GRAD_TO_RAD (3.14159265/180)
#define PASSO 10
#define PASSO_TETA 10

class Projectile{
    private:
        int x, y;
        float teta, speed;
    public:
        Projectile(int x, int y, float teta);
        int get_x();
        void set_x(int);
        int get_y();
        void set_y(int);
        float get_teta();
        void set_teta(float);
        float get_speed();
        float set_speed();
	void update_xy();
};
