#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CorpoView{
	private:
		int x,  y;
		float angle;
		char* src_asset;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		SDL_Rect rect;
	public:
		CorpoView(int h, int w, float angle, const char* src_asset);
		void update(int x, int y, float angle);
		void set_render(SDL_Renderer *renderer);
		SDL_Renderer *get_render();
		virtual void drawCast() = 0;
		void draw();
};
