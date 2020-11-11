#include "bodyModel.h"

CorpoModel::CorpoModel(int x, int y, int h, int w, float teta){
	this->x = x;
	this->y = y;
	this->teta = teta;
	this->rect.x = x;
	this->rect.y = y;
	this->rect.h = h;
	this->rect.w = w;
}

int CorpoModel::get_x(){
    return this->x;
}

void CorpoModel::set_x(int novo_x){
    this->x = novo_x;
    this->rect.x = this->x;
}

int CorpoModel::get_y(){
    return this->y;
}

void CorpoModel::set_y(int novo_y){
    this->y = novo_y;
    this->rect.y = this->y;
}

float CorpoModel::get_teta(){
    return this->teta;
}

void CorpoModel::set_teta(float novo_teta){
    this->teta = novo_teta;
}

void CorpoModel::update_teta(float delta){
	this->teta += delta;
}

int CorpoModel::get_health(){
    return health;
}

void CorpoModel::set_health(int novo_health){
    this->health = novo_health;
}
const SDL_Rect* CorpoModel::get_rect(){
	return &(this->rect);
}
