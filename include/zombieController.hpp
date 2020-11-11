#pragma once
#include "zombieModel.hpp"
#include "zombieView.hpp"
#include "characterModel.hpp"

class ZumbiController {
	private:
		ZumbiModel model;
		std::shared_ptr<ZumbiView> view;
		SDL_Keyboard_Handler keyboardHandler;
	public: 
		ZumbiController(int x, int y, int h, int w, float teta);
		void updateView();
		void updateModel(std::shared_ptr<PersonagemModel> p);
		std::shared_ptr<ZumbiView> getView();
		ZumbiModel getModel();
		void iterate(std::shared_ptr<PersonagemModel> p);
        ZumbiModel get_model();
};
