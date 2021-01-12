#pragma once
#include "characterModel.hpp"
#include "axeController.hpp"
#include "json.hpp"
#include <queue>

static int ID_PERSONAGEM = 0;

class PersonagemController {
	private:
		std::shared_ptr<PersonagemModel> model;
		std::vector<AxeController> axeControllers;
		RetornoHandle playerInput;
		int id;
        std::queue<int> fila_acoes;
	public: 
		PersonagemController(int x, int y, int h, int w, float teta);
		void updateModel();
		std::shared_ptr<PersonagemModel> getModel();
		void iterate();
		std::vector<AxeController> get_axeControllers();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
		std::string get_id();
};
