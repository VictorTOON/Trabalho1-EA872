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
	window = SDL_CreateWindow("Sistema massa-mola",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
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
	if (renderer == nullptr){
		SDL_DestroyWindow(window);
		std::cout << SDL_GetError();
		SDL_Quit();
		return;
	}
}

GameView::~GameView(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


void GameView::drawGame(){
	SDL_PumpEvents();
	while (SDL_PollEvent(&(this->event))){
		if (this->event.type == SDL_QUIT){
			return -1;
		}	
	}
	this->block_view.y = pixel_pos;
	SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, 255);
	SDL_RenderClear(this->renderer);
	personagemView.draw();
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(this->renderer, &(this->block_view));
	SDL_RenderPresent(this->renderer);
	SDL_Delay(10);
	return 0;
}
