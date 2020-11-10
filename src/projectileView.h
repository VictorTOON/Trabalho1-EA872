#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ProjectileView{
	private:
		int x,  y;
		float angle;
		char src_asset[100];
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		SDL_Rect rect;
	public:
		ProjectileView(int h, int w, float angle, char src_asset[100]);
		void update(int x, int y, float angle);
		void set_render(SDL_Renderer *renderer);
		void draw();
};
