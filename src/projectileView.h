#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <string.h>

class ProjectileView{
	private:
		int x,  y;
		float angle;
		char* src_asset;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		SDL_Rect rect;
	public:
		ProjectileView(int h, int w, float angle, const char* src_asset);
        ~ProjectileView();
		void update(int x, int y, float angle);
		void set_render(SDL_Renderer *renderer);
		void draw();
};
