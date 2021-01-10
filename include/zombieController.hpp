#pragma once
#include "zombieModel.hpp"
#include "characterModel.hpp"
#include "json.hpp"

static int ID_CONTROLLER = 0;

class ZumbiController {
	private:
		ZumbiModel model;
		int id;
	public: 
		ZumbiController(int x, int y, int h, int w, float teta);
		void updateModel(std::shared_ptr<PersonagemModel> p);
		ZumbiModel getModel();
		void iterate(std::shared_ptr<PersonagemModel> p);
		ZumbiModel get_model();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
		void saveStateJson();
		int get_id();
};
