#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include "axeModel.hpp"
#include "json.hpp"
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

typedef enum{
    Destruir,
    Manter,
}retornoUpdateAxeController;
/* \brief Controller do machado
		 *
		 * Tem acesso ao view e ao model do machado
		 */
static int ID_AXE = 0;
class AxeController{
    private:
        std::shared_ptr<AxeModel> axeModel;
        float tempoVida;
	int id;
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
        std::shared_ptr<AxeModel> get_axeModel();
	nlohmann::json getStateJson();
	void readStateJson(nlohmann::json state);	
	std::string get_id();
};
