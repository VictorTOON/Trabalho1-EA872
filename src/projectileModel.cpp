#include "projectileModel.h"
#include <cmath>

ProjectileModel::ProjectileModel(int x, int y, float teta, float speed){
	this->x = x;
	this->y = y;
	this->teta = teta;
	this->speed = speed;
}

int ProjectileModel::get_x(){
    return this->x;
}

void ProjectileModel::set_x(int novo_x){
    this->x = novo_x;
}

int ProjectileModel::get_y(){
    return this->y;
}

void ProjectileModel::set_y(int novo_y){
    this->y = novo_y;
}

float ProjectileModel::get_teta(){
    return this->teta;
}

void ProjectileModel::set_teta(float novo_teta){
    this->teta = novo_teta;
}

#define GRAD_TO_RAD (3.14159265/180)
void ProjectileModel::update_xy(float tempo_pass, float tempo_atual){
	this->x = (int) this->speed*cos(this->teta*GRAD_TO_RAD)*(tempo_atual - tempo_pass) + this->x;
	this->y = (int) (this->speed*sin(this->teta*GRAD_TO_RAD)*(tempo_atual - tempo_pass) + this->y);
}

float ProjectileModel::get_speed(){
    return this->speed;
}

void ProjectileModel::set_speed(float novo_speed){
    this->speed = novo_speed;
}
