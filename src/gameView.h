#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iomanip>
#include "characterView.h"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

class GameView{
	private:
		std::unique_ptr<PersonagemView> personagemView;
		SDL_Window *window;
		SDL_Renderer* renderer;
		SDL_Event event;
	public:
		GameView(PersonagemView personagemView);
		~GameView();
		int draw();

};
