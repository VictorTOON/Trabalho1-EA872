#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define CHARACTER_SIZE 150

class CorpoView{
	private:
		int x,  y;
		float angle;
		const char src_asset[100];
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		SDL_Rect rect;
	public:
		CorpoView(int h, int w, float angle, char src_asset[100]);
		void update(int x, int y, float angle);
		void set_render(SDL_Renderer *renderer);
		void draw();
};
