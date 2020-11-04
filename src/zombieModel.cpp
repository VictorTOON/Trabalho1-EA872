#include "zombieModel.h"

Zumbi::Zumbi(int x, int y, float teta){
	this->x = x;
	this->y = y;
	this->teta = teta;
}

int Zumbi::get_x(){
    return x;
}

void Zumbi::set_x(int novo_x){
    this->x = novo_x;
}

int Zumbi::get_y(){
    return y;
}

void Zumbi::set_y(int novo_y){
    this->y = novo_y;
}

float Zumbi::get_teta(){
    return teta;
}

void Zumbi::set_teta(float novo_teta){
    this->teta = novo_teta;
}

void Zumbi::update_teta(float delta){
	this->teta += delta;
}

int Zumbi::get_health(){
    return health;
}

void Zumbi::set_health(int novo_health){
    this->health = novo_health;
}

#define GRAD_TO_RAD (3.14159265/180)
#define CONST_SPIN 0.1
void Zumbi::followPersonagem(Personagem p){
	if (this->x < p.get_x()){
		this->x += PASSO * CONST_SPIN;
	} else if (this->x > p.get_x()){
		this->x -= PASSO * CONST_SPIN;
	}
	if (this->y < p.get_y()){
		this->y += PASSO * CONST_SPIN;
	} else if (this->y > p.get_y()){
		this->y -= PASSO * CONST_SPIN;
	}
}

