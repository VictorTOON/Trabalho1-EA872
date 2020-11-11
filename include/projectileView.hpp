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
        /* \brief Contrutor do view
            *
            * \param h altura do frame do machado
            * \param w largura do frame do machado
            * \param angle angulo d personagem
            * \param src_asset ponteiro para uma string cm o nome do asset
            * */
		ProjectileView(int h, int w, float angle, const char* src_asset);
		~ProjectileView();
        /* \brief Contrutor do view
            *
            * atualiza a view do projetil
            * 
            * \param x posicao nova do x
            * \param y posicao nova do y
            * \param angle angulo a ser atualizad
            * */
		void update(int x, int y, float angle);
		void set_render(SDL_Renderer *renderer);
		void draw();
		void updateAngle(float);
		float get_angle();
};
