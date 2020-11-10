#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "axeView.h"

#include "bodyView.h"
#define CHARACTER_SIZE 150

class PersonagemView: public CorpoView{
    private:
        std::vector<AxeView> axeViews;
	public:
		PersonagemView(int h, int w, float angle, char src_asset[100]);
};
