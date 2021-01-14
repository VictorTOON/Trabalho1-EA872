#pragma once
#include "characterModel.hpp"
#include "characterView.hpp"
#include "sdl_keyboard_handler.hpp"
#include "axeController.hpp"
#include "json.hpp"
#include "constants.hpp"

#include <utility>
#include <map>

class PersonagemController {
	private:
		std::shared_ptr<PersonagemModel> model;
		std::shared_ptr<PersonagemView> view;
		SDL_Keyboard_Handler keyboardHandler;
		std::unordered_map<std::string, AxeController> axeControllers;
	public: 
		PersonagemController(int x, int y, int h, int w, float teta);
		void updateView();
		void updateModel();
		std::shared_ptr<PersonagemView> getView();
		std::shared_ptr<PersonagemModel> getModel();
		void iterate();
		std::unordered_map<std::string, AxeController> get_axeControllers();
		nlohmann::json getStateJson();
		void readStateJson(nlohmann::json state);
};
