
#include "bodyView.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

CorpoView::CorpoView(int h, int w, float angle){
	this->angle = angle;
	this->rect.h = h;
	this->rect.w = w;
	
}

void CorpoView::set_render(SDL_Renderer *renderer){
	this->renderer = renderer;
	this->texture = IMG_LoadTexture(renderer, src_asset);
}

void CorpoView::update(int x, int y, float angle){
	this->angle = angle;
	this->rect.x = ((x>0)?x:0);
	this->rect.y = ((y>0)?y:0);
}

void CorpoView::draw(){
	SDL_RenderCopyEx(renderer, this->texture, nullptr, &(this->rect), this->angle, nullptr, SDL_FLIP_NONE);

}


