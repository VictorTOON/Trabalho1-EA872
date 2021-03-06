#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "json.hpp"
#include <cmath>
#include <memory>
#include <string>

#define GRAD_TO_RAD (3.14159265/180)
#define PASSO 10
#define PASSO_TETA 10

class CorpoModel{
	private:
		int x, y, h, w, health;
		float teta;
		unsigned int lastHealthChange;
		SDL_Rect rect;
		int id;
	public:
		CorpoModel(int x, int y, int h, int w, float teta);
		int get_x();
		void set_x(int);
		int get_y();void set_y(int);
		float get_teta();
		void set_teta(float);
		int get_health();
		void set_health(int);
		const SDL_Rect* get_rect();
		void update_teta(float);
		nlohmann::json baseJson();
		void readBaseJson(nlohmann::json base);
};
