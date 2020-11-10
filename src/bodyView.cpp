
#include "bodyView.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>

CorpoView::CorpoView(int h, int w, float angle, char src_asset[100]){
	this->angle = angle;
	this->rect.h = h;
	this->rect.w = w;
	std::strcpy(this->src_asset, src_asset);
	
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

virtual void drawCast(){}

void CorpoView::draw(){
	SDL_RenderCopyEx(renderer, this->texture, nullptr, &(this->rect), this->angle, nullptr, SDL_FLIP_NONE);
    drawCast();
}


