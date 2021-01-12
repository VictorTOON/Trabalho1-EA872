#pragma once
#include <SDL2/SDL.h>
#include <iostream>
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
