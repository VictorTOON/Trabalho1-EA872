#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>

#define GRAD_TO_RAD (3.14159265/180)
#define PASSO 10
#define PASSO_TETA 10

class ProjectileModel{
    private:
        int x, y;
        float teta, speed;
        SDL_Rect rect;
    public:
        ProjectileModel(int x, int y, float teta, int h, int w, float speed);
        int get_x();
        void set_x(int);
        int get_y();
        void set_y(int);
        float get_teta();
        void set_teta(float);
        float get_speed();
        void set_speed(float);
	    void update_xy(float, float);
        const SDL_Rect* get_rect();
};
