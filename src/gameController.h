#pragma once

#include "gameView.h"
#include "characterView.h"
#include "characterModel.h"
#include "projectileView.h"
#include "projectileModel.h"
#include "zombieView.h"
#include "zombieModel.h"
#include "axeView.h"
#include "axeModel.h"
#include "sdl_keyboard_handler.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

class GameController {
	private:
		std::unique_ptr<Personagem> personagem;
        std::vector<Axe> axes;
		std::unique_ptr<GameView> gameView;
		std::shared_ptr<PersonagemView> personagemView;
		std::vector<ZumbiView> zumbiViews;
		SDL_Keyboard_Handler keyboardHandler;
		void updatePersonagemView();
	public:
		GameController(Personagem personagem, std::vector<Zumbi> zumbis);
		void personagem_updateViewByModel();
		void zumbi_updateViewByModel();
        void axe_updateViewByModel();
		void addZumbi(Zumbi zumbi);
		void start();
		int iterate();
};
