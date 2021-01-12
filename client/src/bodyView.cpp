
#include "bodyView.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>

CorpoView::CorpoView(int h, int w, float angle, const char* src_asset){
	this->angle = angle;
	this->rect.h = h;
	this->rect.w = w;
	this->src_asset = (char*) malloc(sizeof(char)*(strlen(src_asset) + 1));
	std::strcpy(this->src_asset, src_asset);
	
}

void CorpoView::set_render(SDL_Renderer *renderer){
	this->renderer = renderer;
	this->texture = IMG_LoadTexture(renderer, src_asset);
}

SDL_Renderer* CorpoView::get_render(){
	return this->renderer;
}

void CorpoView::update(int x, int y, float angle){
	this->angle = angle;
	this->rect.x = ((x>0)?x:0);
	this->rect.y = ((y>0)?y:0);
}


void CorpoView::draw(){
	SDL_RenderCopyEx(renderer, this->texture, nullptr, &(this->rect), this->angle, nullptr, SDL_FLIP_NONE);
	drawCast();
}


