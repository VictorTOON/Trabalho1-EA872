#pragma once
#include <SDL2/SDL.h>
#include <memory> 
#include <SDL2/SDL_image.h>

#define ZOMBIE_SIZE 150

class ZumbiView{
	private:
		int x,  y;
		float angle;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		SDL_Rect rect;
	public:
		ZumbiView(int h, int w, float angle);
		void update(int x, int y, float angle);
		void set_render(SDL_Renderer *renderer);
		void draw();
};
