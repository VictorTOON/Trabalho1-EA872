#include "characterView.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

PersonagemView::PersonagemView(int h, int w, float angle){
	this->angle = angle;
	this->rect.h = h;
	this->rect.w = w;
	
}

void PersonagemView::set_render(SDL_Renderer *renderer){
	this->renderer = renderer;
	this->texture = IMG_LoadTexture(renderer, "../assets/tree-character.png");
}

void PersonagemView::update(int x, int y, float angle){
	this->angle = angle;
	this->rect.x = ((x>0)?x:0);
	this->rect.y = ((y>0)?y:0);
	std::cout<<"no update: "<<angle<<" "<<rect.x<<" "<<rect.y<<std::endl;
}

void PersonagemView::draw(){
	std::cout<<angle<<" "<<rect.x<<" "<<rect.y<<std::endl;
	SDL_RenderCopyEx(renderer, this->texture, nullptr, &(this->rect), this->angle, nullptr, SDL_FLIP_NONE);

}


