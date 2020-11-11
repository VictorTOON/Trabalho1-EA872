#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.h"
#include <cmath>
#include "characterModel.h"
#include "axeModel.h"
#include "zombieModel.h"

typedef enum{
    Mata,
    Mantem
}statusZumbi;

class GameModel{
    public:
       statusZumbi checkIntersection(AxeModel machado, ZumbiModel zumbi);
};