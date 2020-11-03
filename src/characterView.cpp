#include "characterView.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

PersonagemView::PersonagemView(int x, int y, float angle, int color[3]){
	this->x = x;
	this->y = y;
	this->angle = angle;
	this->color[0] = color[0];
	this->color[1] = color[1];
	this->color[2] = color[2];
	
}

void PersonagemView::update(int x, int y, float angle, int color[3]){

}

void PersonagemView::draw(){

}


