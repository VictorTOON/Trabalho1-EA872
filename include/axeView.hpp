#pragma once
#include <SDL2/SDL.h>
#include <memory> 
#include <SDL2/SDL_image.h>
#include "projectileView.hpp"

#define AXE_SIZE 50

class AxeView: public ProjectileView{
	public:
     /* \brief Contrutor do view
            *
            * \param h altura do frame do machado
            * \param w largura do frame do machado
            * \param angle angulo d personagem
            * \param src_asset ponteiro para uma string cm o nome do asset
            * */
		AxeView(int h, int w, float angle, const char* src_asset);
};
