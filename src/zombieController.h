#pragma once
#include "zombieModel.h"
#include "zombieView.h"
#include "characterModel.h"

class ZumbiController {
	private:
		ZumbiModel model;
		std::shared_ptr<ZumbiView> view;
		SDL_Keyboard_Handler keyboardHandler;
	public: 
		ZumbiController(int x, int y, int h, int w, float teta);
		void updateView();
		void updateModel(PersonagemModel p);
		std::shared_ptr<ZumbiView> getView();
		ZumbiModel getModel();
		void iterate(PersonagemModel p);
};
