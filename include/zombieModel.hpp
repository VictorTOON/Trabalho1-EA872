#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include "characterModel.hpp"
#include "bodyModel.hpp"


#define PASSO_ZUMBI 10

typedef enum {
	CollisionPersonagem,
	CollisionZumbi, 
	DefaultFollow
} ZumbiFollowReturn;  

class ZumbiModel: public CorpoModel{
    public:
        ZumbiModel(int x, int y, int h, int w, float teta);
	ZumbiFollowReturn follow(std::shared_ptr<PersonagemModel> p);
};
