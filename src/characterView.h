#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define CHARACTER_SIZE 150

class PersonagemView{
	private:
	       	SDL_Rect personagem;
		int x,  y;
		float angle;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		SDL_Rect rect;
	public:
		PersonagemView(int h, int w, float angle);
		void update(int x, int y, float angle);
		void set_render(SDL_Renderer *renderer);
		void draw();
};
