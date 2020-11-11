#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iomanip>
#include "characterView.hpp"
#include "zombieView.hpp"
#include "axeView.hpp"
#include <memory>
#include <vector>
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

class GameView{
	private:
		SDL_Texture *backgroundTexture;
		SDL_Window *window;
		SDL_Renderer* renderer;
		SDL_Event event;
	public:
		GameView();
		~GameView();
		int draw();
		void finishDraw();
		void setBackground();
		void addAxe(std::shared_ptr<AxeView> axe);
		void addZumbi(std::shared_ptr<ZumbiView> z);
		void addPersonagem(std::shared_ptr<PersonagemView> p);
		void drawBackground();
};
