#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include "projectileModel.h"

class AxeModel: public ProjectileModel{
    public:
        AxeModel(int x, int y, float teta, int h, int w, float speed);
};
