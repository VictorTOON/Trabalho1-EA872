#include "characterModel.h"

Personagem::Personagem(int x, int y, float teta){
	this->x = x;
	this->y = y;
	this->teta = teta;
}

int Personagem::get_x(){
    return x;
}

void Personagem::set_x(int novo_x){
    this->x = novo_x;
}

int Personagem::get_y(){
    return y;
}

void Personagem::set_y(int novo_y){
    this->y = novo_y;
}

float Personagem::get_teta(){
    return teta;
}

void Personagem::set_teta(float novo_teta){
    this->teta = novo_teta;
}

void Personagem::update_teta(float delta){
	this->teta += delta;
}

int Personagem::get_health(){
    return health;
}

void Personagem::set_health(int novo_health){
    this->health = novo_health;
}

#define GRAD_TO_RAD (3.14159265/180)
void Personagem::handle_keyboard(int entry){
	
	if (entry & (1 << KEYBOARD_UP)){
			this->x += PASSO * cos(teta * (GRAD_TO_RAD));
			this->y += PASSO * sin(teta * (GRAD_TO_RAD)); 
			if (this->x < 0) this->x = 0;
			if (this->y < 0) this->y = 0;
	}
	if (entry & (1 << KEYBOARD_DOWN)){
			this->x -= PASSO * cos(teta * (GRAD_TO_RAD));
			this->y -= PASSO * sin(teta * (GRAD_TO_RAD)); 
			if (this->x < 0) this->x = 0;
			if (this->y < 0) this->y = 0;
	}
	if (entry & (1 << KEYBOARD_LEFT)){
			this->teta -= PASSO_TETA; 
	}
	if (entry & (1 << KEYBOARD_RIGHT)){
			this->teta += PASSO_TETA; 
	}
}

