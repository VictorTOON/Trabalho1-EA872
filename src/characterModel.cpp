#include "characterModel.h"

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

int Personagem::get_health(){
    return health;
}

void Personagem::set_health(int novo_health){
    this->health = novo_health;
}