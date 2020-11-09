#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include "projectileModel.h"

class Axe: public Projectile{
    public:
        Projectile(int x, int y, float teta, float speed);
};