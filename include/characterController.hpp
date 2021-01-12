#pragma once
#include "characterModel.hpp"
#include "axeController.hpp"
#include "json.hpp"

class PersonagemController {
	private:
		std::shared_ptr<PersonagemModel> model;
		std::vector<AxeController> axeControllers;
		RetornoHandle playerInput;
		std::string id;
	public: 
		PersonagemController(int x, int y, int h, int w, float teta);
		void updateModel();
		std::shared_ptr<PersonagemModel> getModel();
		void iterate();
		std::vector<AxeController> get_axeControllers();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
		std::string get_id();
		void set_id(std::string id);
};
