#pragma once
#include <SDL2/SDL.h>
#include <memory> 
#include <SDL2/SDL_image.h>
#include "bodyView.hpp"

#define ZOMBIE_SIZE 150

class ZumbiView: public CorpoView{
	public:
		ZumbiView(int h, int w, float angle, const char* src_asset);
		virtual void drawCast();
};
