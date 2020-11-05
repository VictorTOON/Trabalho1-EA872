#include "bodyModel.h"

Corpo::Corpo(int x, int y, float teta){
	this->x = x;
	this->y = y;
	this->teta = teta;
}

int Corpo::get_x(){
    return this->x;
}

void Corpo::set_x(int novo_x){
    this->x = novo_x;
}

int Corpo::get_y(){
    return this->y;
}

void Corpo::set_y(int novo_y){
    this->y = novo_y;
}

float Corpo::get_teta(){
    return this->teta;
}

void Corpo::set_teta(float novo_teta){
    this->teta = novo_teta;
}

void Corpo::update_teta(float delta){
	this->teta += delta;
}

int Corpo::get_health(){
    return health;
}

void Corpo::set_health(int novo_health){
    this->health = novo_health;
}
