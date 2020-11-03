#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class PersonagemView{
	private:
	       	SDL_Rect personagem;
		int h, w;
		int x,  y;
		float angle;
		int color[3];
		SDL_Renderer *renderer;
		SDL_Texture *texture;
	public:
		PersonagemView(int x, int y, float angle, int color[3]);
		void update(int x, int y, float angle, int color[3]);
		void set_render(SDL_Renderer *render);
		void draw();
};
