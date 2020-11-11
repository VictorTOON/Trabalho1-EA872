
#include "projectileView.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>

ProjectileView::ProjectileView(int h, int w, float angle, const char* src_asset){
	this->angle = angle;
	this->rect.h = h;
	this->rect.w = w;
	this->src_asset = (char*) malloc(sizeof(char)*strlen(src_asset));
	strcpy(this->src_asset, src_asset);
		
}

void ProjectileView::set_render(SDL_Renderer *renderer){
	this->renderer = renderer;
	this->texture = IMG_LoadTexture(renderer, src_asset);
}

void ProjectileView::update(int x, int y, float angle){
	this->angle = angle;
	this->rect.x = ((x>0)?x:0);
	this->rect.y = ((y>0)?y:0);
}

void ProjectileView::updateAngle(float delta_angle){
	this->angle += delta_angle;
}

float ProjectileView::get_angle(){
	return this->angle;

}

void ProjectileView::draw(){
	SDL_RenderCopyEx(renderer, this->texture, nullptr, &(this->rect), this->angle, nullptr, SDL_FLIP_NONE);

}

ProjectileView::~ProjectileView(){
    SDL_DestroyTexture(this->texture);
}

