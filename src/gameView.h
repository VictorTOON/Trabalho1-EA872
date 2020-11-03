#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iomanip>
#include "characterView.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

class GameView{
	private:
        SDL_Texture *backgroundTexture;
		std::unique_ptr<PersonagemView> personagemView;
		SDL_Window *window;
		SDL_Renderer* renderer;
		SDL_Event event;
	public:
		GameView(PersonagemView personagemView);
		~GameView();
		int draw();
        void setBackground();
        void drawBackground();
};
