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
	this->texture = IMG_LoadTexture(renderer, "../assets/tree-character.png");
}

void PersonagemView::update(int x, int y, float angle, int color[3]){
}

void PersonagemView::draw(){
	static float i = 0;
	SDL_RenderCopyEx(renderer, this->texture, nullptr, nullptr, 45.0f + i++, nullptr, SDL_FLIP_NONE);

}


