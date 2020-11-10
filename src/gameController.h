#pragma once

#include "gameView.h"
#include "characterController.h"
#include "zombieController.h"
#include "sdl_keyboard_handler.h"

#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

class GameController {
	private:
		std::unique_ptr<PersonagemController> personagem;
		std::vector<ZumbiController> zumbis;
		std::unique_ptr<GameView> gameView;
		std::vector<ZumbiView> zumbiViews;
		void updatePersonagemView();
	public:
		GameController(PersonagemController personagem, std::vector<ZumbiController> zumbis);
		void addZumbi(ZumbiModel zumbi);
		void start();
		int iterate();
};
