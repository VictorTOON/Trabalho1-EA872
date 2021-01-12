#pragma once
#include "characterModel.hpp"
#include "axeController.hpp"
#include "json.hpp"
#include <queue>

class PersonagemController {
    /* \brief Explicando a classe
            * Personagem controller tem acesso a Personagem Model e a um vetor de AxeControllers
            * Possui também um id pra ser encontrado no map
            * e uma fila de movimentos que vai agir, pra ser enviado pro servidor
            * */
	private:
		std::shared_ptr<PersonagemModel> model;
		std::vector<AxeController> axeControllers;
		RetornoHandle playerInput;
		std::string id;
		std::queue<int> fila_acoes;
	public: 
		PersonagemController(int x, int y, int h, int w, float teta);
		void updateModel();
		std::shared_ptr<PersonagemModel> getModel();
        /* \brief iterate
            * Iterate vai chamar a atualização do model, 
            * que atualiza os jogadores e seus machados um por um
            * */
		void iterate();
		std::vector<AxeController> get_axeControllers();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
		std::string get_id();
		void set_id(std::string id);
        /* \brief iterate
            * Função que recebe uma ação e adiciona ela na fila de ações da classe
            * */
		void addTo_fila_acoes(int acao);
};
