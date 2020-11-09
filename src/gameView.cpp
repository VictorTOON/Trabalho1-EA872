#include "gameView.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

GameView::GameView(std::shared_ptr<PersonagemView> personagemView, std::vector<ZumbiView> zumbiViews){
	this->personagemView = personagemView;
	this->zumbiViews = zumbiViews;
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
	this->personagemView->set_render(renderer);
	for (auto it = begin(this->zumbiViews); it != end(this->zumbiViews); ++it){
		it->set_render(renderer);
	
	}
	this->setBackground();
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
	SDL_DestroyTexture(backgroundTexture);
	SDL_Quit();
}

void GameView::setBackground(){
    backgroundTexture = IMG_LoadTexture(renderer, "../assets/background.jpg");
}
void GameView::drawBackground(){
    SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);
}

void GameView::changeZumbi(int position, int x, int y, float angle){
	this->zumbiViews.at(position).update(x, y, angle);
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

	personagemView->draw();
	for (auto it = begin(this->zumbiViews); it != end(this->zumbiViews); ++it){
		it->draw();
	
	}
	SDL_RenderPresent(this->renderer);
	SDL_Delay(30);
	return 0;
}
