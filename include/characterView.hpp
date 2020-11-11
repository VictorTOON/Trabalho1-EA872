#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "bodyView.hpp"
#define CHARACTER_SIZE 150

class PersonagemView: public CorpoView{
	public:
		PersonagemView(int h, int w, float angle, const char* src_asset);
		virtual void drawCast();
};
