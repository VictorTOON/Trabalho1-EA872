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
        /* \brief Contrutor do model
            *
            * \param x posição em x
            * \param y posição em y
            * \param teta angulo do personagem
            * \param h altura do frame do machado
            * \param w largura do frame do machado
            * \param speed velocidade do machado (constante)
            * */
        ProjectileModel(int x, int y, float teta, int h, int w, float speed);
        int get_x();
        void set_x(int);
        int get_y();
        void set_y(int);
        float get_teta();
        void set_teta(float);
        float get_speed();
        void set_speed(float);
        /* \brief Contrutor do model
            *
            * atualiza a posicao do projetil com base no tempo que passou
            * 
            * \param 1 tempo de referencia inicial
            * \param 2 temp de referencia final
            * */
	    void update_xy(float, float);
        /* \brief Contrutor do model
            *
            * Retorna um ponteiro para o .rect da classe
            *
            * \return ponteiro para o SDL_Rect() do projéticl
            * */
        const SDL_Rect* get_rect();
};
