#pragma once
#include <SDL2/SDL.h>
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
        /* \brief handle_keyboard
            * Recebe um int que representa a tecla clicada
            * e toma uma atitude referente a ela, gerando uma ação
            * */
		RetornoHandle handle_keyboard(int);
        /* \brief isDead
            * Função chamada caso o player morra
            * */
		bool isDead();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
};
