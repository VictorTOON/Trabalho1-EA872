#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_keyboard_handler.hpp"
#include <cmath>
#include "axeModel.hpp"
#include "axeView.hpp"

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

typedef enum{
    Destruir,
    Manter,
}retornoUpdateAxeController;
/* \brief Controller do machado
		 *
		 * Tem acesso ao view e ao model do machado
		 */
class AxeController{
    private:
        std::shared_ptr<AxeModel> axeModel;
        std::shared_ptr<AxeView> axeView;
        float tempoVida;
    public:
        /* \brief Contrutor do controller
            *
            * Interpreta os valores de state
            * */
        AxeController(int x, int y, float teta);
        /* \brief Funcao que atualiza o machado
		 *
		 * atualiza o model do machado a cada passagem de tempo
		 *
		 * \return Retorna um enum retornoAxeController
		 * Assim saberemos se o machado ainda deve existir
         * ou deve ser removido
		 * */
        retornoUpdateAxeController updateModel(float tempo_pass, float tempo_atual);
        /* \brief Funcao que atualiza o View
		 *
		 * atualiza a View do machado com base no model
		 * */
        void updateView();
	    std::shared_ptr<AxeView> getView();
        std::shared_ptr<AxeModel> get_axeModel();
};
