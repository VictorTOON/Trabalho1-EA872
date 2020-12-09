#pragma once
#include "zombieModel.hpp"
#include "zombieView.hpp"
#include "characterModel.hpp"
#include "json.hpp"

static int ID_CONTROLLER = 0;

class ZumbiController {
	private:
		ZumbiModel model;
		std::shared_ptr<ZumbiView> view;
		SDL_Keyboard_Handler keyboardHandler;
		int id;
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
		int get_id();
};
