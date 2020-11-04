#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iomanip>
#include "characterView.h"
#include "zombieView.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

class GameView{
	private:
		SDL_Texture *backgroundTexture;
		std::shared_ptr<PersonagemView> personagemView;
		std::shared_ptr<ZumbiView> zumbiView;
		SDL_Window *window;
		SDL_Renderer* renderer;
		SDL_Event event;
	public:
		GameView(std::shared_ptr<PersonagemView> personagemView, std::shared_ptr<ZumbiView> zumbiView);
		~GameView();
		int draw();
		void setBackground();
		void drawBackground();
};
