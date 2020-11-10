#include "gameView.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

GameView::GameView(){
	if (SDL_Init (SDL_INIT_VIDEO) < 0){
		std::cout << SDL_GetError();
		return;
	}
	window = nullptr;
	window = SDL_CreateWindow("MASSACRE DAS ARVORES PARTE 2",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_FULLSCREEN_DESKTOP
			);

	if (window == nullptr){
		SDL_DestroyWindow(window);
		std::cout << SDL_GetError();
		SDL_Quit();
		return;
	}

	renderer = nullptr;
	renderer = SDL_CreateRenderer(
			window, 
			-1,
			SDL_RENDERER_ACCELERATED
			);
	
	this->setBackground();
	if (renderer == nullptr){
		SDL_DestroyWindow(window);
		std::cout << SDL_GetError();
		SDL_Quit();
		return;
	}
}

void GameView::addPersonagem(std::shared_ptr<PersonagemView> personagem){
	personagem->set_render(renderer);
}

void GameView::addZumbi(std::shared_ptr<ZumbiView> zumbi){
	zumbi->set_render(renderer);
}

GameView::~GameView(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(backgroundTexture);
	SDL_Quit();
}

void GameView::setBackground(){
    backgroundTexture = IMG_LoadTexture(renderer, "../assets/background.jpg");
}
void GameView::drawBackground(){
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);
}

int GameView::draw(){
	SDL_PumpEvents();
	while (SDL_PollEvent(&(this->event))){
		if (this->event.type == SDL_QUIT){
			return -1;
		}	
	}
	SDL_RenderClear(this->renderer);

	this->drawBackground();

	return 0;
}

void GameView::finishDraw(){
	SDL_RenderPresent(this->renderer);
	SDL_Delay(30);
}
