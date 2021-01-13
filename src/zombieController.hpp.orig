#pragma once
#include "zombieModel.hpp"
#include "zombieView.hpp"
#include "characterModel.hpp"
#include "json.hpp"
#include <string>

static int ID_CONTROLLER = 0;

class ZumbiController {
	private:
		ZumbiModel model;
		std::shared_ptr<ZumbiView> view;
		SDL_Keyboard_Handler keyboardHandler;
		std::string id;
		std::string player_id;
	public: 
		ZumbiController(int x, int y, int h, int w, float teta);
		void updateView(std::shared_ptr<PersonagemModel> p);
		void updateModel(std::shared_ptr<PersonagemModel> p);
		std::shared_ptr<ZumbiView> getView();
		ZumbiModel getModel();
		void iterate(std::shared_ptr<PersonagemModel> p);
		ZumbiModel get_model();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
		void saveStateJson();
		std::string get_id();
		void set_id(std::string id);
		void set_player_id(std::string id);
		std::string get_player_id();
};
