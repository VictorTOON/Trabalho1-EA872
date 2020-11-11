#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include <memory>

#define GRAD_TO_RAD (3.14159265/180)
#define PASSO 10
#define PASSO_TETA 10

class CorpoModel{
    private:
        int x, y, h, w, health;
        float teta;
	unsigned int lastHealthChange;
	SDL_Rect rect;
    public:
        CorpoModel(int x, int y, int h, int w, float teta);
        int get_x();
        void set_x(int);
        int get_y();void set_y(int);
        float get_teta();
        void set_teta(float);
        int get_health();
        void set_health(int);
	const SDL_Rect* get_rect();
	void update_teta(float);
};
