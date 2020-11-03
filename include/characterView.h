#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class PersonagemView{
	private:
	       	SDL_Rect personagem;
		int x,  y;
		float angle;
		int[3] color;
	public:
		PersonagemView(int x, int y, float angle, int[3] color);
		void update(int x, int y, float angle, int[3] color);
		void draw();
};
