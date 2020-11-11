#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.hpp"
#include <cmath>
#include "characterModel.hpp"
#include "axeModel.hpp"
#include "zombieModel.hpp"

typedef enum{
    Mata,
    Mantem
}statusZumbi;

class GameModel{
    public:
       statusZumbi checkIntersection(AxeModel machado, ZumbiModel zumbi);
};
