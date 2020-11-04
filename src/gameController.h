#pragma once

#include "gameView.h"
#include "characterView.h"
#include "characterModel.h"
#include "zombieView.h"
#include "zombieModel.h"
#include "sdl_keyboard_handler.h"

#include <iomanip>
#include <iostream>

class GameController {
	private:
		std::unique_ptr<Personagem> personagem;
		std::unique_ptr<Zumbi> zumbi;
		std::unique_ptr<GameView> gameView;
		std::shared_ptr<PersonagemView> personagemView;
		std::shared_ptr<ZumbiView> zumbiView;
		SDL_Keyboard_Handler keyboardHandler;
		void updatePersonagemView();
	public:
		GameController(Personagem personagem, Zumbi zumbi);
		void personagem_updateViewByModel();
		void zumbi_updateViewByModel();
		void start();
		int iterate();
};
