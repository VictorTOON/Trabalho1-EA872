#include "characterView.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

PersonagemView::PersonagemView(int h, int w, float angle, int color[3]){
	this->h= h;
	this->w = w;
	this->angle = angle;
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
	
}

void PersonagemView::set_render(SDL_Renderer *renderer){
	this->renderer = renderer;
	this->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, h, w);
}

void PersonagemView::update(int x, int y, float angle, int color[3]){

}

void PersonagemView::draw(){
	
	std::cout << this->h << this-> w << std::endl; 
	SDL_SetRenderTarget(this->renderer, this->texture);
        SDL_SetRenderDrawColor(this->renderer, this->color[0], this->color[1], this->color[1], 255);
	//SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);

}


