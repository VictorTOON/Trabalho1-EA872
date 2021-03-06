#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.hpp"
#include <cmath>
#include "bodyModel.hpp"
#include "axeController.hpp"

/*! \brief Enumerator com os valores retornados pela handle_keyboard
 * Esses valores podem ser interpretados pelo PersonagemController para fazer alguma acao no jogo
 * */
typedef enum {
	CriaMachado,
	Default
} RetornoHandle;

class PersonagemModel: public CorpoModel{
	private:
		std::vector<AxeController> axeControllers;
		unsigned int tempo;
		unsigned int tempoComparado;
	public:
		PersonagemModel(int x, int y, int h, int w, float teta);
		RetornoHandle handle_keyboard(int);
		bool isDead();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
};
