#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/*! \brief Classe base para o View dos corpos 
 *
 * Classe base para o View de um corpo, possui a posicao, o angulo,
 * O source da imagem da textura, o render que a textura vai se ligar 
 * E o SDL_Rect para a posicao
 *
 */
class CorpoView{
	private:
		int x,  y;
		float angle;
		char* src_asset;
		SDL_Renderer *renderer;
		SDL_Texture *texture;
		SDL_Rect rect;
	public:
		/*! \brief Construtor da classe
		 * \param h Altura da imagem
		 * \param w Largura da imagem
		 * \param angle Angulo da imagem
		 * \param src_asset Source path da imagem
		 * */
		CorpoView(int h, int w, float angle, const char* src_asset);

		/*! \brief Funcao que atualiza a textura
		 * \param x Posicao x da imagem
		 * \param y Posicao y da image
		 * \param angle Angulo da imagem
		 * */
		void update(int x, int y, float angle);

		/*! \brief Funcao que seta o render
		 * \param render Ponteiro do SDL_Renderer do jogo
		 * */
		void set_render(SDL_Renderer *renderer);
		SDL_Renderer *get_render();
		virtual void drawCast() = 0;
		/*! \brief Renderiza o corpo para o SDL
		 * */
		void draw();
};
