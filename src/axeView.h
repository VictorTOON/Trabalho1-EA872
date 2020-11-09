#pragma once
#include <SDL2/SDL.h>
#include <memory> 
#include <SDL2/SDL_image.h>
#include "projectileView.h"

#define AXE_SIZE 50

class AxeView: public ProjectileView{
	public:
		AxeView(int h, int w, float angle, char src_asset[100]);
};
