#pragma once

#include "gameView.h"
#include "characterView.h"
#include "characterModel.h"
#include "sdl_keyboard_handler.h"

#include <iomanip>
#include <iostream>

class GameController {
	private:
		std::unique_ptr<Personagem> personagem;
		std::unique_ptr<GameView> gameView;
		std::shared_ptr<PersonagemView> personagemView;
		SDL_Keyboard_Handler keyboardHandler;
		void updatePersonagemView();
	public:
		GameController(Personagem personagem);
		void personagem_updateViewByModel();
		void start();
		int iterate();
};
