#include "projectileModel.h"
#include <cmath>

Projectile::Projectile(int x, int y, float teta, float speed){
	this->x = x;
	this->y = y;
	this->teta = teta;
    this->speed = speed;
}

int Projectile::get_x(){
    return this->x;
}

void Projectile::set_x(int novo_x){
    this->x = novo_x;
}

int Projectile::get_y(){
    return this->y;
}

void Projectile::set_y(int novo_y){
    this->y = novo_y;
}

float Projectile::get_teta(){
    return this->teta;
}

void Projectile::set_teta(float novo_teta){
    this->teta = novo_teta;
}

void Projectile::update_xy(float tempo_pass, float tempo_atual){
	this->x = this->speed*cos(this->teta)*(tempo_atual - tempo_pass) + this->x
    this->y = this->speed*sen(this->teta)*(tempo_atual - tempo_pass) + this->y
}

float Projectile::get_speed(){
    return this->speed;
}

void Projectile::set_teta(float novo_speed){
    this->speed = novo_speed;
}