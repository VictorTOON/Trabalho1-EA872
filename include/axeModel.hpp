#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.hpp"
#include <cmath>
#include "projectileModel.hpp"

class AxeModel: public ProjectileModel{
    public:
        /* \brief Contrutor do model
            *
            * \param x posição em x
            * \param y posição em y
            * \param teta angulo do personagem
            * \param h altura do frame do machado
            * \param w largura do frame do machado
            * \param speed velocidade do machado (constante)
            * */
        AxeModel(int x, int y, float teta, int h, int w, float speed);
};
