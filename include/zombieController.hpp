#pragma once
#include "zombieModel.hpp"
#include "characterModel.hpp"

#include "json.hpp"
#include <string>

static int ID_CONTROLLER = 0;

class ZumbiController {
	private:
		ZumbiModel model;
		int id;
        std::string player_id;
	public: 
		ZumbiController(int x, int y, int h, int w, float teta, std::string player_id);
		void updateModel(std::shared_ptr<PersonagemModel> p);
		ZumbiModel getModel();
		void iterate(std::shared_ptr<PersonagemModel> p);
		ZumbiModel get_model();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
		void saveStateJson();
		std::string get_id(); 
        std::string get_player_id();
};
