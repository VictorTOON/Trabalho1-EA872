#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iomanip>
#include "characterView.h"
#include "zombieView.h"
#include "axeView.h"
#include <memory>
#include <vector>
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

class GameView{
	private:
		SDL_Texture *backgroundTexture;
		std::shared_ptr<PersonagemView> personagemView;
		std::vector<ZumbiView> zumbiViews;
        std::vector<AxeView> axeViews;
		SDL_Window *window;
		SDL_Renderer* renderer;
		SDL_Event event;
	public:
		GameView(std::shared_ptr<PersonagemView> personagemView, std::vector<ZumbiView> zumbiViews);
		~GameView();
		int draw();
		void setBackground();
		void changeZumbi(int position, int x, int y, float angle);
		void drawBackground();
};
